//归并排序的递归算法
//1.跟二叉树的遍历很像，先让左边有序再让右边有序，最后再让整体有序
//2.这就需要开辟一个数组，空间复杂度为O(N)
//3.记得把握边界
#include<stdio.h>
#include<stdlib.h>
void _MergeSort(int* a, int left, int right, int* temp)
{
	if (left >= right)
		return;
	//将数组分为两个部分不断的往后递归
	int mid = left + (right - left) / 2;
	//[left,mid] [mid+1,right]
	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid + 1, right, temp);
	//注意i不能为0，要等于left因为递归到后面left不是0
	int i = left;
	//定义几个变量方便控制，就是左右的边界
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	//只要有一个超过边界就跳出
	while (begin1<=end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			temp[i++] = a[begin1++];
		else
			temp[i++] = a[begin2++];
	}
	//下面的俩个循环会进去一个
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}
	//将temp拷贝到a中
	for (int j = left; j <=right; ++j)
	{
		a[j] = temp[j];
	}
}
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
		return;
	_MergeSort(a,0,n-1,temp);
	free(temp);
	temp = NULL;
}
void TestMergeSort()
{
	int arr[] = { 2,5,3,1,9,7,6,8,10,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	TestMergeSort();
}