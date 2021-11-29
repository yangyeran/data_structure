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
//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else//a[mid]������
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
		else//a[mid]����С��
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
		//�ҵ�a[cur]С��key���ˣ����Ҳ�����cur��prev��ͬ��
		//ע��һ�����if���Ƶ�������prtev������ǰ��++����cur�ȣ���Ϊֻ����Ȳ�����(�Լ����Լ�����û������)������˵���prev��++
		//ǰ��ָ�뷨�Ķ��嵱a[cur]�ҵ���a[key]С��ֵ��prevҪ++
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
	//�÷ǵݹ���д����Ҫ�õ�ջ
	//���ź�һ������Ȼ��ͻ�ֳ����䣬������������������δ���ջ��
	Stack ST;
	StackInit(&ST);
	StackPush(&ST,left);
	StackPush(&ST, right);
	while (!StackEmpty(&ST))
	{
		//��ȡջ���Ԫ��
		//�������left�����ȳ�����right
		int end=StackTop(&ST);
		StackPop(&ST);
		int begin = StackTop(&ST);
		StackPop(&ST);
		//��ȡ��Ԫ���˾Ϳ��Կ�ʼ����
		int keyi = Partion(a, begin, end);
		//�������Ԫ�ؼ�����ջ��ջֱ��ջ��
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