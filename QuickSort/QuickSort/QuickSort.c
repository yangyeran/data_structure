#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void InsertSort(int* a, int n)
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
////hoare版本单趟(递归实现)
int Partion1(int* a, int left, int right)
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
//挖坑法
int Partion2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	//pit是坑
	int pit = left;
	while (left < right)
	{
		//挖坑法就是以左边为key,挖一个坑，然后从右边找比坑位的值小的值，把值放进坑里，形成新的坑
		//然后就开从左边找比坑位大的值
		//最后相等的时候把存的值给相等的地方
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[pit] = a[right];
		pit = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[pit] = a[left];
		pit = left;
	}
	//因为都一样，所以用哪个都行
	a[pit] = key;
	return pit;
}
//前后指针
	//cur和prev指向的都是下标
	//前后指针法就是定义一个cur和一个prev当选左边为key时，cur指向数组的第二个元素，prev指向数组的第一个元素(左边需要走到right结束也就是right的后面一个数)
	//当选右边为key时，cur指向数组的第一个元素，prev指向数组之前的元素(走到right就可以结束了，结束之后的交换需要跟key比较一下值，要是a[prev]<a[key]需要prev++一下，大于直接交换就好)
	//cur是找比key小的值，找到之后就停下来然后prev++，交换俩个数的值，直到cur走到头 
	//跳出循环之后两种都需要在进行一次交换prev与key的
int Partion3(int* a, int left, int right)
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
		if (a[cur] < a[key] && ++prev != cur)//if的写法
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
		/*	while (cur <= right && a[cur] >= a[key])//while的写法
			{
				++cur;
			}
			if (cur <= right&&++prev!=cur)
				Swap(&a[prev], &a[cur]);
			++cur;
		*/
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	//当只有一个或者一个没有时返回
	//大于就是右边为空，左边不为空
	//等于就是两个都为1;
	if (left >= right)
		return;
	//类似于二叉树的遍历
	//快排递归的小区间优化
	if (right - left+1 < 10)
	{
		InsertSort(a + left, right - left+1);
	}
	else
	{
		int keyi = Partion3(a, left, right);
		//[left,keyi-1]  keyi [keyi+1,right]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}
void test1()
{
	srand(time(0));
	const int N = 1000000;
	int* a5 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a5[i] = rand();
	}
	//TestPrint(a5, N);
	//printf("\n");
	int begin5 = clock();
	QuickSort(a5, 0, N-1);
	int end5 = clock();
	//TestPrint(a5, N);
	//printf("\n");
	printf("QuickSort:%d\n", end5 - begin5);
	free(a5);
}
void test2()
{
	int a[] = { 2,1,4,7,9,10,8,6,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	TestPrint(a, size);
	printf("\n");
	QuickSort(a, 0,size-1);
	TestPrint(a, size);
}
int main()
{
	test1();
}