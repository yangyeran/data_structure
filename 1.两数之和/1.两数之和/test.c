#include<stdio.h>
#include<stdlib.h>
//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±�
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//����԰�����˳�򷵻ش𰸡�
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //ֻ��һ����ȷ�Ĵ𰸣���ͬһԪ�ز����ظ�����
    int* arr = (int*)malloc(sizeof(int) * 2);
    int j = 0;
    while (j < numsSize)
    {
        int temp = target - nums[j];
        int i = j;
        while (i < numsSize)
        {
            if (nums[i] == temp && i != j)
            {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
            else
            {
                ++i;
            }
        }
        ++j;
    }
    *returnSize = 0;
    return NULL;
}