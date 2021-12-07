#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void CountSort(int* a, int n)
{
	//�ҳ���С����������Ϊ�˽�ʡ�ռ俪�ٵĴ�СΪ 4 * (mxa-min+1)
	int max = a[0], min = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//�Ϳ�ʼ��������
	int* count = (int*)malloc(sizeof(int) * (max - min + 1));
	if (count == NULL)
	{
		printf("malloc false\n");
		exit(-1);
	}
	//�����ٵ����鶼��ʼ��Ϊ0
	memset(count,0, sizeof(int) * (max - min + 1));
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < max - min + 1; ++i)
	{
		while (count[i]>0)
		{
			a[j++] = min+i;
			count[i]--;
		}
	}
	free(count);
	count = NULL;
}
void TestCountSort()
{
	int arr[] = { 5,4,1,2,2,2,3,3,7,8,9,7,6,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	CountSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	TestCountSort();
}