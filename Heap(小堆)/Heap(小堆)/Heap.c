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
	//������������С�ڸ��׽ڵ���ô����������λ��
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
//���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	//С�ѵ����µ���
	assert(a);
	int child = parent * 2 + 1;
	//int leftchild = parent * 2 + 1;
	//int rightchild = parent * 2 + 2;
	//ѭ���ж�����
	//while(leftchild<n && a[parent]>leftchild && a[parent]>rightchild)
	while (child < n)
	{
		//�������ӣ�Ȼ���Һ����Ƿ�С������
		if (child + 1 < n && a[child + 1] > a[child])
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
		//�ȱȽ����Һ��ӵĴ�С��Ȼ�����������(����)
		/*if(rightchild>=n)
		{
			Swap(&a[leftchild],&a[parent]);
			break;
		}
		if(a[leftchild]<a[rightchild])
		{
			//��������С���ұߣ���ô�͸���߽���
			Swap(&a[leftchild],&a[parent]);
			parent=leftchild;
			leftchild=parent*2+1;
			rightchild=parent*2+2;
		}
		else
		{
			Swap(&a[rightchild],&a[parent]);
			parent=rightchild;
			leftchild=parent*2+1;
			rightchild=parent*2+2;
		}*/
	}
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