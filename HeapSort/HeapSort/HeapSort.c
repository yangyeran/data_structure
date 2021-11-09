typedef int HPDataType;
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//升序
void HeapSort(int* a, int n)
{
//	//把a构建成大堆
//	//有Ajustup(方法一)
//	for (int i = 1; i < n; i++)
//	{
//		//把第一个数看成是堆(父亲节点)，然后把后面的数插入堆
//		Adjustup(a, i);
//	}
	//方法二
	//向下排序，从非叶子节点开始
	//叶子节点不用调

	for (int i = n - 1; i >= 0; i--)
	{
		int parent = (i - 1) / 2;
		AdjustDown(a, n, parent);
	}
	//已经是大堆
	int end = n - 1;
	while (end > 0)
	{
		//交换第一个和最后一个数
		int temp = a[0];
		a[0] = a[end];
		a[end] = temp;
		AdjustDown(a, end, 0);
		end--;
	}
}