#include<stdio.h>
#include<stdlib.h>
//给定一个非负整数numRows生成杨辉三角的前numRows行
//在杨辉三角中每个数是它左上方和右上方的数的和
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	//malloc一块二维数组空间
	*returnSize = numRows;
	//开辟numRows行
	int** ret = (int**)malloc(numRows * sizeof(int*));
	//开辟列的头一个元素
	*returnColumnSizes = (int*)malloc(numRows * sizeof(int));
	for (int i = 0; i < numRows; i++)
	{
		//开辟每一列的大小
		ret[i] = (int*)malloc((i + 1) * sizeof(int));
		//returnColumnSizes是一个一维数组存放了每一列的大小，这是在给里面的值赋值，上面传的是一维数组的大小
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