//�鲢����ĵݹ��㷨
//1.���������ı�����������������������ұ��������������������
//2.�����Ҫ����һ�����飬�ռ临�Ӷ�ΪO(N)
//3.�ǵð��ձ߽�
#include<stdio.h>
#include<stdlib.h>
void _MergeSort(int* a, int left, int right, int* temp)
{
	if (left >= right)
		return;
	//�������Ϊ�������ֲ��ϵ�����ݹ�
	int mid = left + (right - left) / 2;
	//[left,mid] [mid+1,right]
	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid + 1, right, temp);
	//ע��i����Ϊ0��Ҫ����left��Ϊ�ݹ鵽����left����0
	int i = left;
	//���弸������������ƣ��������ҵı߽�
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	//ֻҪ��һ�������߽������
	while (begin1<=end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			temp[i++] = a[begin1++];
		else
			temp[i++] = a[begin2++];
	}
	//���������ѭ�����ȥһ��
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}
	//��temp������a��
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