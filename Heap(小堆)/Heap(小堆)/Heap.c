#include "Heap.h"
//��ʼ������
void HeapInit(HP* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}
//��������
void Swap(HPDataType* hp, HPDataType* hy)
{
	HPDataType temp = *hp;
	*hp = *hy;
	*hy = temp;
}
void AdjustUp(HPDataType* a, int child)
{
	//�����������ݴ��ڸ��׽ڵ���ô����������λ��
	//���
	assert(a);
	int parent = (child - 1) / 2;
	//child�������0���ʾû�и��׽ڵ�������ֱ������
	while (child > 0)
	{
		//������Ӵ��ڸ��׾ͽ��������˵�ֵ�������±�Ҳ��Ҫ�ı�
		if (a[child] > a[parent])
		{
			//HPDataType temp=a[child];
			//a[child]=a[parent];
			//a[parent]=temp;
			Swap(&a[child],&a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//�����൱��β��
void HeapPush(HP* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//����
		int Newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* newNode = (HPDataType*)realloc(hp->a,sizeof(HPDataType) * Newcapacity);
		if (newNode == NULL)
		{
			printf("realloc false");
			exit(-1);
		}
		hp->a = newNode;
		hp->capacity = Newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	//�������ܹ����˶��ٿռ䣬�ͺ��ӵ��±�
	AdjustUp(hp->a, hp->size - 1);
}
//�ж��Ƿ�Ϊ��
bool HeapEmpty(HP* hp)
{
	//Ϊ�շ�����true��Ϊ�ٷ���false
	assert(hp);
	return hp->size == 0;
}
//����Ч�ĸ���
int HeapSize(HP* hp)
{
	return hp->size;
}

//ɾ���Ǵ�������ɾ��
void HeapPop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&(hp->a[0]), &(hp->a[hp->size - 1]));
	hp->size--;
	AdjustDown(hp->a,hp->size, 0);
}
//���ٺ���
void HeapDistroy(HP* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
//��ӡ����
void HeapPrint(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}


//��ѵ����µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n &&  a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//���Ҷ���
int HeapTop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->a[0];
}
// �ѵĹ���
void HeapCreate(HP* hp, HPDataType* a, int n)
{
	//ֱ�ӽ���
	for (int i = 0; i < n; i++)
	{
		HeapPush(hp,a[i]);
	}
}
//Topk�㷨
void PrintTopk(HPDataType* a, int n, int k)
{
	//Ҫ�ҵ�����k���������ҵ���С��k����
	//����д��������С��k����
	//������ҵ���С��k��������ô������Ҫ���ľ��ǽ���һ��k���ڵ�Ĵ�ѣ��öѶ�Ԫ����ʣ�µ�n-k��Ԫ�رȽϣ�����ȶѶ�С�ͽ���
	HP hp;
	HeapInit(&hp);
	//���Ĵ��
	HeapCreate(&hp, a, k);
	//��Ҫ��ʼ������������Ƚ�
	for (int i = k; i < n; i++)
	{
		//�ȶѶ�С�ͽ���
		if (HeapTop(&hp) > a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	//�����ˣ���ӡ��һ���Ƿ����
	HeapPrint(&hp);
	HeapDistroy(&hp);
}


//void AdjustUp(HPDataType* a, int child)
//{
//	//������������С�ڸ��׽ڵ���ô����������λ��
//	//С��
//	assert(a);
//	int parent = (child - 1) / 2;
//	//child�������0���ʾû�и��׽ڵ�������ֱ������
//	while (child > 0)
//	{
//		//�������С�ڸ��׾ͽ��������˵�ֵ�������±�Ҳ��Ҫ�ı�
//		if (a[child] < a[parent])
//		{
//			//HPDataType temp=a[child];
//			//a[child]=a[parent];
//			//a[parent]=temp;
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

////С�ѵ����µ���
//void AdjustDown(HPDataType* a, int n, int parent)
//{
//	assert(a);
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			child++;
//		}
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
