#include<stdio.h>
#include<stdlib.h>
//����һ���Ǹ�����numRows����������ǵ�ǰnumRows��
//�����������ÿ�����������Ϸ������Ϸ������ĺ�
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	//mallocһ���ά����ռ�
	*returnSize = numRows;
	//����numRows��
	int** ret = (int**)malloc(numRows * sizeof(int*));
	//�����е�ͷһ��Ԫ��
	*returnColumnSizes = (int*)malloc(numRows * sizeof(int));
	for (int i = 0; i < numRows; i++)
	{
		//����ÿһ�еĴ�С
		ret[i] = (int*)malloc((i + 1) * sizeof(int));
		//returnColumnSizes��һ��һά��������ÿһ�еĴ�С�������ڸ������ֵ��ֵ�����洫����һά����Ĵ�С
		(*returnColumnSizes)[i] = i + 1;
	}
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				ret[i][j] = 1;
			else
			{
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}
	}
	return ret;
}