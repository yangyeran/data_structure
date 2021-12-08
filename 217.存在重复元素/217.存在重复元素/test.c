#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
bool containsDuplicate(int* nums, int numsSize) {
    int max = nums[0], min = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }
    int* count = (int*)malloc(sizeof(int) * (max - min + 1));
    memset(count, 0, sizeof(int) * (max - min + 1));
    for (int i = 0; i < numsSize; ++i)
    {
        count[nums[i] - min]++;
    }
    int j = max - min;
    while (j >= 0)
    {
        if (count[j] > 1)
        {
            free(count);
            return true;
        }
        --j;
    }
    free(count);
    return false;
}