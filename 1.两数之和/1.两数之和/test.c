#include<stdio.h>
#include<stdlib.h>
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //只有一组正确的答案，且同一元素不能重复出现
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