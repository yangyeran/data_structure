#include<stdio.h>
#include<stdlib.h>
void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int x = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > x)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = x;
        }
    }
}
int BinarySearch(int* a, int numsSize, int n)
{
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] < n)
            left = mid+1;
        else if (a[mid] > n)
            right = mid-1;
        else
            return mid;
    }
    return -1;
}
int* Buyspace(int* temp, int* capacity)
{
    *capacity = (*capacity) * 2;
    temp = (int*)realloc(temp, sizeof(int)*(*capacity));
    return temp;
}
//给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
//返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
//如果给定的数组已经排好序呢？你将如何优化你的算法？
//如果 nums1 的大小比 nums2 小，哪种方法更优？
//如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    //将两个数组排序
    //开辟空间
    int count = 0;
    int capacity = 2;
    int* temp = (int*)malloc(sizeof(int) * capacity);
    //比较两个数组谁大谁小，然后以小的为主体，去多的里面去查找是否有相同的数，有的话就入数组
    if (nums1Size > nums2Size)
    {
        for (int i = nums2Size-1; i >= 0; --i)
        {
            ShellSort(nums1, nums1Size);
            int mid = BinarySearch(nums1,  nums1Size, nums2[i]);
            if (mid != -1)
            {
                if (count == capacity)
                    temp = Buyspace(temp, &capacity);
                temp[count++] = nums1[mid];
                nums1[mid] = -1;
            }
        }
    }
    else
    {
        for (int i = nums1Size-1; i >= 0; --i)
        {
            ShellSort(nums2, nums2Size);
            int mid = BinarySearch(nums2, nums2Size, nums1[i]);
            if (mid != -1)
            {
                if (count == capacity)
                temp= Buyspace(temp, &capacity);
                temp[count++] = nums2[mid];
                nums2[mid] = -1;
            }
        }
    }
    *returnSize = count;
    return temp;
}
void test1()
{
    int arr1[] = { 43,85,49,2,83,2,39,99,15,70,39,27,71,3,88,5,19,5,68,34,7,41,84,2,13,85,12,54,7,9,13,19,92 };
    int arr2[] = { 10,8,53,63,58,83,26,10,58,3,61,56,55,38,81,29,69,55,86,23,91,44,9,98,41,48,41,16,42,72,6,4,2,81,42,84,4,13 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int returnSize = 0;
    int *temp=intersect(arr1, size1, arr2, size2,&returnSize);
    int j = 0;
}
int main()
{
    test1();
}