#include<stdio.h>
#include<stdlib.h>
void MergeSortNonR(int* a, int n)
{	
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc　false");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		////还可以增加代码打条件断点例如
		//if (gap == 4)
		//{
		//	//这里面的代码是什么都无所谓，只是为了方便打断点
		//	int j = 0;
		//}
		for (int i = 0; i < n; i += 2 * gap)
		{
			//这里面会被分成[i,i+gap-1][i+gap,i+2*gap-1]
			//情况1:[begin2,end2]区间不存在(只能保证i是不会越界，但是i+2*gap-1不能够保证)
			//情况2:end1也越界，[begin2,end2]不存在
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			//这个就适用于oj题不方便调试时，可以用这种打印的方式来看
			//就可以看每次归并的区间了
			//printf("[%d][%d] [%d][%d] ", begin1, end1, begin2, end2);


			//控制越界
			//通过修正来控制越界(这种方法不能使用break,根本原因是使用的大区间拷贝，即一轮排完之后才会去拷回原数组，就会导致temp缺数)
			//end1越界，就代表后面的都越界了，就没有了排的必要，但是begin1的数还是需要归到temp数组中
			if (end1 >= n)
			{	//end1越界了就会来到了这里
				//需要把begin1的数给拷贝到temp数组里面
				end1 = n - 1;
			}
			//[begin1,end1]存在，[begin2,end2]不存在
			if (begin2 >= n)
			{
				//index的越界本质就是越界之后把值都修正成相等的了
				//那我们就可以把它修正成一个不存在的空间，这样就不会进入循环
				begin2 = n;
				end2 = n - 1;
			}
			//end2越界
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
					//当begin1==end1==begin2==end2时
					//会出现拷了两次，导致index越界，当释放temp数组的时候就会报错
					temp[index++] = a[begin2++];
				}
			}
			//注意跳出来之后index也有可能会越界，所以需要判断一下index<n
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
//		printf("malloc　false");
//		exit(-1);
//	}
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//这里面会被分成[i,i+gap-1][i+gap,i+2*gap-1]
//			//情况1:[begin2,end2]区间不存在(只能保证i是不会越界，但是i+2*gap-1不能够保证)
//			//情况2:end1也越界，[begin2,end2]不存在
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = i;
//			//知道原理的话就可以进行另一种修改，就是像递归一样，进行小区间拷贝
//			if (end1 >= n|| begin2 >= n)
//				break;
//			//只需要去修正这一种情况，因为还有数需要排
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
//			//小区间拷贝，归并一组拷一组
//			//因为需要的是初始的下标，begin1在比较的时候++了，所以用i来代替
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

////这是主体的思路但是这样写只适用于2的次方数
//void MergeSortNonR(int* a, int n)
//{
//	//归并排序是需要建立新的空间
//	int* temp = (int*)malloc(sizeof(int) * n);
//	if (temp == NULL)
//	{
//		printf("malloc　false");
//		exit(-1);
//	}
//	//开始归并排序
//		//归并的非递归没有必要用堆或者队列来实现，循环就能够实习这一操作
//	//2,5,3,1,9,7,6,8,10,4 我们可以给它分组gap=1,gap=2.....gap*=2;
//	//之所以这么分组就是归并一开始是一个和一个归并，归并成2个然后2个归并成4个。。。。这样不断的归并
//	int gap = 1;
//	while (gap < n)
//	{
//		//i+=2*gap这个式子可以参考gap=1，然后画出这一段的过程图，就能推断出来
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//这里面会被分成[i,i+gap-1][i+gap,i+2*gap-1]
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
//	//销毁开辟的空间
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