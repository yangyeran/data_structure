#include<stdio.h>
//在C99中支持创建数组的时候使用变量来控制数组大小
//本题的思路：定义一个prev变量如果nums[prev]为负数那么不做任何改变，如果nums[prev]是正数，那么就和现在的数相加放在当前位置
//为了方便理解我重新创建了一个数组
int maxSubArray(int* nums, int numsSize) {
    int prev = 0;
    // int max[numsSize];
    //max[prev]=nums[0];
    for (int j = 1; j < numsSize; ++j)
    {
        if (nums[prev] < 0)
        {
            //max[j]=nums[j];
            ++prev;
        }
        else//max[prev]>=0
        {
            // max[j]=nums[j]+max[prev];
            nums[j] = nums[j] + nums[prev];
            ++prev;
        }
    }
    //int _max=max[0];
    int max = nums[0];
    while (prev > 0)
    {
        // if(_max<max[prev])
        //_max=max[prev];
        if (max < nums[prev])
            max = nums[prev];
        --prev;
    }
    //return _max;
    return max;
}