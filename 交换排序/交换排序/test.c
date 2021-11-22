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
//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else//a[mid]是最大的
		{
			if (a[left] > a[right])
				return left;
			else
				return right;
		}
	}
	else//a[left]>a[mid] 
	{
		if (a[mid] > a[right])
			return mid;
		else//a[mid]是最小的
		{
			if (a[right] > a[left])
				return right;
			else
				return left;
		}
	}
}
//单趟
int Partion(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < right)
	{
		//左边做key右边先走
		//左找大，右找小
		//=号不能少，这是针对于全是相同值的排序(例:5 5 5 5 5 5 5 )，不加就会死循环(进不去循环right和left都不会改变)
		//因为left<right只能判断进来的那一次，所以后续循环需要加上，否则就会越界
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
//hoare版本
void QuickSort(int* a, int left,int right)
{
	//当只有一个或者一个没有时返回
	//大于就是右边为空，左边不为空
	//等于就是两个都为1;
	if (left >= right)
		return;
	//根据递归实现
	int keyi = Partion(a, left,right);
	//[left,keyi-1]  keyi [keyi+1,right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi+1,right);
}
void test1()
{
	int a[] = { 2,1,4,7,9,10,8,6,3,5};
	//int a[] = { 1,2,3,4,5,6,7,8,9,10 };
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