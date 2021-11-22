#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int* a, int n)
{
	int flag = 0;
	for (int j = n-1; j >0; --j)
	{
		for (int i = 0; i < j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void TestPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
//����
int Partion(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		//�����key�ұ�����
		//���Ҵ�����С
		int i = right;
		//=�Ų����٣����������ȫ����ֵͬ������(��:5 5 5 5 5 5 5 )�����Ӿͻ���ѭ��(����ȥѭ��right��left������ı�)
		//��Ϊleft<rightֻ���жϽ�������һ�Σ����Ժ���ѭ����Ҫ���ϣ�����ͻ�Խ��
		while (left < right && a[keyi] <= a[right])
		{
			--right;
		}
		while (left < right && a[keyi] >= a[left])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
//hoare�汾
void QuickSort(int* a, int left,int right)
{
	//��ֻ��һ������һ��û��ʱ����
	if (left >= right)
		return;
	//���ݵݹ�ʵ��
	int keyi = Partion(a, left,right);
	//[left,keyi-1]  keyi [keyi+1,right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi+1,right);
}
void test1()
{
	int a[] = { 2,1,4,7,9,10,8,6,3,5};
	int size = sizeof(a) / sizeof(a[0]);
	TestPrint(a, size);
	printf("\n");
	//BubbleSort(a,size);
	QuickSort(a,0,size-1);
	TestPrint(a, size);
}
int main()
{
	test1();
}