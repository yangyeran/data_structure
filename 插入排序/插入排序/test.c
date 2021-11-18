#include<stdio.h>
#include<stdlib.h>
//��������
void InsertSort(int* a,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int x = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = x;
	}
}
//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	//gap�����ܻ����1����ΪΪ1ʱ�պ��ź�
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = x;
		}
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
	ShellSort(a,size);
	//InsertSort(a,size);
	TestPrint(a,size);
}
int main()
{
	test1();
}