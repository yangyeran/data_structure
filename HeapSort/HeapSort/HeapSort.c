#include<stdio.h>
typedef int HPDataType;
//交换函数
void Swap(HPDataType* a, HPDataType* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//排升序
//首先就是建堆，在堆排序中升序排大堆，降序排小堆
//在Topk算法中求最大的几个数用小堆，求最小的几个数用大堆
void AdjustDown(HPDataType* a, int n, int parent)
{
	//向下调整
	int child = parent * 2 + 1;
	while (child < n)
	{
		//注意不能忘记右孩子可能不存在
		if (child+1<n &&a[child] < a[child + 1])
			{
				child++;
			}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		//不加else会死循环
		else
		{
			break;
		}
	}
}
void HeapSort(HPDataType* a, int n)
{
	//构建大堆
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//排序，讲第一个跟最后一个交换，然后向下排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
int main()
{
	HPDataType a[10] = { 70,12,34,74,21,42,54,86,10,55 };
	HeapSort(&a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
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
////升序
//void HeapSort(int* a, int n)
//{
////	//把a构建成大堆
////	//有Ajustup(方法一)
////	for (int i = 1; i < n; i++)
////	{
////		//把第一个数看成是堆(父亲节点)，然后把后面的数插入堆
////		Adjustup(a, i);
////	}
//	//方法二
//	//向下排序，从非叶子节点开始
//	//叶子节点不用调
//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		int parent = (i - 1) / 2;
//		AdjustDown(a, n, parent);
//	}
//	//已经是大堆
//	int end = n - 1;
//	while (end > 0)
//	{
//		//交换第一个和最后一个数
//		int temp = a[0];
//		a[0] = a[end];
//		a[end] = temp;
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}