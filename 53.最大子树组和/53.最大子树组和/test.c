#include<stdio.h>
//��C99��֧�ִ��������ʱ��ʹ�ñ��������������С
//�����˼·������һ��prev�������nums[prev]Ϊ������ô�����κθı䣬���nums[prev]����������ô�ͺ����ڵ�����ӷ��ڵ�ǰλ��
//Ϊ�˷�����������´�����һ������
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