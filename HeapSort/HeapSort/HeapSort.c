#include<stdio.h>
typedef int HPDataType;
//��������
void Swap(HPDataType* a, HPDataType* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//������
//���Ⱦ��ǽ��ѣ��ڶ������������Ŵ�ѣ�������С��
//��Topk�㷨�������ļ�������С�ѣ�����С�ļ������ô��
void AdjustDown(HPDataType* a, int n, int parent)
{
	//���µ���
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ע�ⲻ�������Һ��ӿ��ܲ�����
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
		//����else����ѭ��
		else
		{
			break;
		}
	}
}
void HeapSort(HPDataType* a, int n)
{
	//�������
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//���򣬽���һ�������һ��������Ȼ����������
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
////����
//void HeapSort(int* a, int n)
//{
////	//��a�����ɴ��
////	//��Ajustup(����һ)
////	for (int i = 1; i < n; i++)
////	{
////		//�ѵ�һ���������Ƕ�(���׽ڵ�)��Ȼ��Ѻ�����������
////		Adjustup(a, i);
////	}
//	//������
//	//�������򣬴ӷ�Ҷ�ӽڵ㿪ʼ
//	//Ҷ�ӽڵ㲻�õ�
//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		int parent = (i - 1) / 2;
//		AdjustDown(a, n, parent);
//	}
//	//�Ѿ��Ǵ��
//	int end = n - 1;
//	while (end > 0)
//	{
//		//������һ�������һ����
//		int temp = a[0];
//		a[0] = a[end];
//		a[end] = temp;
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}