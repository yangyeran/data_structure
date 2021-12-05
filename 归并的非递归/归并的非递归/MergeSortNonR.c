#include<stdio.h>
#include<stdlib.h>
void MergeSortNonR(int* a, int n)
{	
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc��false");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		////���������Ӵ���������ϵ�����
		//if (gap == 4)
		//{
		//	//������Ĵ�����ʲô������ν��ֻ��Ϊ�˷����ϵ�
		//	int j = 0;
		//}
		for (int i = 0; i < n; i += 2 * gap)
		{
			//������ᱻ�ֳ�[i,i+gap-1][i+gap,i+2*gap-1]
			//���1:[begin2,end2]���䲻����(ֻ�ܱ�֤i�ǲ���Խ�磬����i+2*gap-1���ܹ���֤)
			//���2:end1ҲԽ�磬[begin2,end2]������
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			//�����������oj�ⲻ�������ʱ�����������ִ�ӡ�ķ�ʽ����
			//�Ϳ��Կ�ÿ�ι鲢��������
			//printf("[%d][%d] [%d][%d] ", begin1, end1, begin2, end2);


			//����Խ��
			//ͨ������������Խ��(���ַ�������ʹ��break,����ԭ����ʹ�õĴ����俽������һ������֮��Ż�ȥ����ԭ���飬�ͻᵼ��tempȱ��)
			//end1Խ�磬�ʹ������Ķ�Խ���ˣ���û�����ŵı�Ҫ������begin1����������Ҫ�鵽temp������
			if (end1 >= n)
			{	//end1Խ���˾ͻ�����������
				//��Ҫ��begin1������������temp��������
				end1 = n - 1;
			}
			//[begin1,end1]���ڣ�[begin2,end2]������
			if (begin2 >= n)
			{
				//index��Խ�籾�ʾ���Խ��֮���ֵ����������ȵ���
				//�����ǾͿ��԰���������һ�������ڵĿռ䣬�����Ͳ������ѭ��
				begin2 = n;
				end2 = n - 1;
			}
			//end2Խ��
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[index++] = a[begin1++];
				}
				else
				{
					//��begin1==end1==begin2==end2ʱ
					//����ֿ������Σ�����indexԽ�磬���ͷ�temp�����ʱ��ͻᱨ��
					temp[index++] = a[begin2++];
				}
			}
			//ע��������֮��indexҲ�п��ܻ�Խ�磬������Ҫ�ж�һ��index<n
			while (begin1 <= end1)//&&index<n)
			{
				temp[index++] = a[begin1++];
			}
			while (begin2 <= end2)//&& index < n)
			{
				temp[index++] = a[begin2++];
			}
		}
		//printf("\n");
		for (int i = 0; i < n; ++i)
		{
			a[i] = temp[i];
		}
		gap *= 2;
	}
	free(temp);
	temp = NULL;
}

//void MergeSortNonR(int* a, int n)
//{
//	int* temp = (int*)malloc(sizeof(int) * n);
//	if (temp == NULL)
//	{
//		printf("malloc��false");
//		exit(-1);
//	}
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//������ᱻ�ֳ�[i,i+gap-1][i+gap,i+2*gap-1]
//			//���1:[begin2,end2]���䲻����(ֻ�ܱ�֤i�ǲ���Խ�磬����i+2*gap-1���ܹ���֤)
//			//���2:end1ҲԽ�磬[begin2,end2]������
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = i;
//			//֪��ԭ��Ļ��Ϳ��Խ�����һ���޸ģ�������ݹ�һ��������С���俽��
//			if (end1 >= n|| begin2 >= n)
//				break;
//			//ֻ��Ҫȥ������һ���������Ϊ��������Ҫ��
//			if (end2 >= n)
//				end2 = n - 1;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					temp[index++] = a[begin1++];
//				}
//				else
//				{
//					temp[index++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				temp[index++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				temp[index++] = a[begin2++];
//			}
//			//С���俽�����鲢һ�鿽һ��
//			//��Ϊ��Ҫ���ǳ�ʼ���±꣬begin1�ڱȽϵ�ʱ��++�ˣ�������i������
//			for (int j = i; j<=end2; ++j)
//			{
//				a[j] = temp[j];
//			}
//		}
//		gap *= 2;
//	}
//	free(temp);
//	temp = NULL;
//}

////���������˼·��������дֻ������2�Ĵη���
//void MergeSortNonR(int* a, int n)
//{
//	//�鲢��������Ҫ�����µĿռ�
//	int* temp = (int*)malloc(sizeof(int) * n);
//	if (temp == NULL)
//	{
//		printf("malloc��false");
//		exit(-1);
//	}
//	//��ʼ�鲢����
//		//�鲢�ķǵݹ�û�б�Ҫ�öѻ��߶�����ʵ�֣�ѭ�����ܹ�ʵϰ��һ����
//	//2,5,3,1,9,7,6,8,10,4 ���ǿ��Ը�������gap=1,gap=2.....gap*=2;
//	//֮������ô������ǹ鲢һ��ʼ��һ����һ���鲢���鲢��2��Ȼ��2���鲢��4�����������������ϵĹ鲢
//	int gap = 1;
//	while (gap < n)
//	{
//		//i+=2*gap���ʽ�ӿ��Բο�gap=1��Ȼ�󻭳���һ�εĹ���ͼ�������ƶϳ���
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//������ᱻ�ֳ�[i,i+gap-1][i+gap,i+2*gap-1]
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = i;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					temp[index++] = a[begin1++];
//				}
//				else
//				{
//					temp[index++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				temp[index++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				temp[index++] = a[begin2++];
//			}
//		}
//		for (int i = 0; i < n; ++i)
//		{
//			a[i] = temp[i];
//		}
//		gap *= 2;
//	}
//	//���ٿ��ٵĿռ�
//	free(temp);
//	temp = NULL;
//}
void TestMergeSortNonR()
{
	int arr[] = { 2,5,3,1,9,7,6,8,10,4 };
	//int arr[] = {10,6,7,1,3,9,4,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	MergeSortNonR(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	TestMergeSortNonR();
}