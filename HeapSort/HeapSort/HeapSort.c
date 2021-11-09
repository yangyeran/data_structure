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
//����
void HeapSort(int* a, int n)
{
//	//��a�����ɴ��
//	//��Ajustup(����һ)
//	for (int i = 1; i < n; i++)
//	{
//		//�ѵ�һ���������Ƕ�(���׽ڵ�)��Ȼ��Ѻ�����������
//		Adjustup(a, i);
//	}
	//������
	//�������򣬴ӷ�Ҷ�ӽڵ㿪ʼ
	//Ҷ�ӽڵ㲻�õ�

	for (int i = n - 1; i >= 0; i--)
	{
		int parent = (i - 1) / 2;
		AdjustDown(a, n, parent);
	}
	//�Ѿ��Ǵ��
	int end = n - 1;
	while (end > 0)
	{
		//������һ�������һ����
		int temp = a[0];
		a[0] = a[end];
		a[end] = temp;
		AdjustDown(a, end, 0);
		end--;
	}
}