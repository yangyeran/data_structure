#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
// 选择排序
void SelectSort(int* a, int n)
{
	//选择排序是遍历一边然后找出最大或者最小的一个元素放在第一个下标位置或者是最后一个下标位置
	//这里用优化一点的选择排序，就是遍历一遍然后去找两个元素，一个是最大的一个是最小的，分别放在两头
	int end = n - 1;//用下标定位
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
		//如果最大的位置在begin位置
		//说明min是和最大的交换位置
		//这个时候max的位置就发生了变换
		//max变到了min的位置,要更新max的位置
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		--end;
		++begin;
	}
}
// 堆排序
void AdjustDwon(int* a, int n, int parent)
{
	//升序排大堆，降序排小堆
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
	//构建堆
	for (int i = (n - 1-1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	//不断的交换并且向下调整
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