#include<stdio.h>
#include<stdlib.h>
//��MATLAB��,��һ���ǳ����õĺ���reshape�����Խ�һ��m*n��������Ϊ��һ����С��ͬr*c���¾��󣬵�������ԭʼ����
//����һ���ɶ�ά����mat��ʾ��m* n�����Լ�����������r��c�ֱ��ʾ��Ҫ���ع��ľ��������������
//�ع���ľ�����Ҫ��ԭʼ���������Ԫ������ͬ���б���˳�����
//������и���������reshape�����ǿ����Һ����������µ����ܾ���; �������ԭʼ����.
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