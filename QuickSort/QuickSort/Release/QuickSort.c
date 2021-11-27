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
////hoare�汾����(�ݹ�ʵ��)
int Partion1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < right)
	{
		//�����key�ұ�����
		//���Ҵ�����С
		//=�Ų����٣����������ȫ����ֵͬ������(��:5 5 5 5 5 5 5 )�����Ӿͻ���ѭ��(����ȥѭ��right��left������ı�)
		//��Ϊleft<rightֻ���жϽ�������һ�Σ����Ժ���ѭ����Ҫ���ϣ�����ͻ�Խ��
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
//�ڿӷ�
int Partion2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	//pit�ǿ�
	int pit = left;
	while (left < right)
	{
		//�ڿӷ����������Ϊkey,��һ���ӣ�Ȼ����ұ��ұȿ�λ��ֵС��ֵ����ֵ�Ž�����γ��µĿ�
		//Ȼ��Ϳ�������ұȿ�λ���ֵ
		//�����ȵ�ʱ��Ѵ��ֵ����ȵĵط�
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
	//��Ϊ��һ�����������ĸ�����
	a[pit] = key;
	return pit;
}
//ǰ��ָ��
	//cur��prevָ��Ķ����±�
	//ǰ��ָ�뷨���Ƕ���һ��cur��һ��prev��ѡ���Ϊkeyʱ��curָ������ĵڶ���Ԫ�أ�prevָ������ĵ�һ��Ԫ��(�����Ҫ�ߵ�right����Ҳ����right�ĺ���һ����)
	//��ѡ�ұ�Ϊkeyʱ��curָ������ĵ�һ��Ԫ�أ�prevָ������֮ǰ��Ԫ��(�ߵ�right�Ϳ��Խ����ˣ�����֮��Ľ�����Ҫ��key�Ƚ�һ��ֵ��Ҫ��a[prev]<a[key]��Ҫprev++һ�£�����ֱ�ӽ����ͺ�)
	//cur���ұ�keyС��ֵ���ҵ�֮���ͣ����Ȼ��prev++��������������ֵ��ֱ��cur�ߵ�ͷ 
	//����ѭ��֮�����ֶ���Ҫ�ڽ���һ�ν���prev��key��
int Partion3(int* a, int left, int right)
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
		if (a[cur] < a[key] && ++prev != cur)//if��д��
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
		/*	while (cur <= right && a[cur] >= a[key])//while��д��
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
	//��ֻ��һ������һ��û��ʱ����
	//���ھ����ұ�Ϊ�գ���߲�Ϊ��
	//���ھ���������Ϊ1;
	if (left >= right)
		return;
	//�����ڶ������ı���
	//���ŵݹ��С�����Ż�
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