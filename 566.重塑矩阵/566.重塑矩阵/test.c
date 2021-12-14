#include<stdio.h>
#include<stdlib.h>
//在MATLAB中,有一个非常有用的函数reshape它可以将一个m*n矩阵重塑为另一个大小不同r*c的新矩阵，但保留其原始数据
//给你一个由二维数组mat表示的m* n矩阵以及两个正整数r和c分别表示想要的重构的矩阵的行数和列数
//重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充
//如果具有给定参数的reshape操作是可行且合理的则输出新的重塑矩阵; 否则，输出原始矩阵.
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    if (r * c != numsSize * (*numsColSize))
    {
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }
    int row = 0;
    int col = 0;
    int m = 0;
    int k = 0;
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int*));
    int** a = (int**)malloc(r * sizeof(int*));
    for (row = 0; row < r; ++row)
    {
        a[row] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[row] = c;
    }
    for (row = 0; row < numsSize; ++row)
    {
        for (col = 0; col < (*numsColSize); ++col)
        {
            a[m][k++] = nums[row][col];
            if (k == c)
            {
                k = 0;
                m++;
            }
        }
    }
    return a;
}