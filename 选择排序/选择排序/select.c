#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
// ѡ������
void SelectSort(int* a, int n)
{
	//ѡ�������Ǳ���һ��Ȼ���ҳ���������С��һ��Ԫ�ط��ڵ�һ���±�λ�û��������һ���±�λ��
	//�������Ż�һ���ѡ�����򣬾��Ǳ���һ��Ȼ��ȥ������Ԫ�أ�һ��������һ������С�ģ��ֱ������ͷ
	int end = n - 1;//���±궨λ
	int begin = 0;
	while (begin < end)
	{
		int max = end;
		int min = begin;
		for (int i = begin; i < end ; i++)
		{
			if (a[i] <= a[min])
			{
				min = i;
			}
			if (a[i] >= a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		//�������λ����beginλ��
		//˵��min�Ǻ����Ľ���λ��
		//���ʱ��max��λ�þͷ����˱任
		//max�䵽��min��λ��,Ҫ����max��λ��
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		--end;
		++begin;
	}
}
// ������
void AdjustDwon(int* a, int n, int parent)
{
	//�����Ŵ�ѣ�������С��
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1 < n) && a[child] < a[child + 1])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child],&a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//������
	for (int i = (n - 1-1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	//���ϵĽ����������µ���
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a,end,0);
		end--;
	}
}
void TestPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void test1()
{
	int a[] = { 2,1,4,7,9,10,8,6,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	TestPrint(a, size);
	printf("\n");
	SelectSort(a, size);
	//HeapSort(a,size);
	TestPrint(a, size);
}
int main()
{
	test1();
}