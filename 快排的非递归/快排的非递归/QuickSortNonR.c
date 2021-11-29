#include"Stack.h"
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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
int Partion(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		//找到a[cur]小于key的了，并且不交换cur和prev相同的
		//注意一点就是if控制的条件中prtev必须是前置++来跟cur比，因为只是相等不交换(自己跟自己交换没有意义)，不是说相等prev不++
		//前后指针法的定义当a[cur]找到比a[key]小的值后，prev要++
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
void QuickSortNonR(int* a, int left, int right)
{
	//用非递归来写，需要用到栈
	//先排好一个数，然后就会分出区间，这样把它的区间的两段存入栈中
	Stack ST;
	StackInit(&ST);
	StackPush(&ST,left);
	StackPush(&ST, right);
	while (!StackEmpty(&ST))
	{
		//获取栈里的元素
		//先入的是left所以先出的是right
		int end=StackTop(&ST);
		StackPop(&ST);
		int begin = StackTop(&ST);
		StackPop(&ST);
		//获取到元素了就可以开始排了
		int keyi = Partion(a, begin, end);
		//如果还有元素继续入栈出栈直到栈空
		//[begin,keyi-1]  keyi  [keyi+1,end]
		if (begin < keyi - 1)
		{
			StackPush(&ST, begin);
			StackPush(&ST, keyi - 1);
		}
		if (keyi + 1 < end)
		{
			StackPush(&ST, keyi + 1);
			StackPush(&ST, end);
		}
	}
}
void test()
{
	int arr[] = { 2,4,1,3,8,10,7,9,6,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	TestPrint(arr,size);
	printf("\n");
	QuickSortNonR(arr, 0, size - 1);
	TestPrint(arr,size);
}
int main()
{
	test();
}