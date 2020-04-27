####

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

来源：[LeetCode](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

#### 题解

+ 方法一

固定一个数字，查找另一个与之和为s的数字，O(n^2),当数据量大时容易超出时间限制。

````C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize =2;
    int *arr = (int *)malloc(sizeof(int)*2);
    int i=0,j=numsSize-1;
    while(i<numsSize)
    {
        while(j>i)
        {
            if(nums[i]+nums[j]==target)
            {
                arr[0]=nums[i];
                arr[1]=nums[j];
                return arr;
            }
            j--;
        }
        i++;
        j=numsSize-1;
    }
    return NULL;
}
````

+ 方法二

注意，题中的数组时递增的有序数组，则可以用双指针法，首先双指针位于收尾，如果相加结果等于S，则完成查找，如果相加结果小于S，则让小的数值变大一些，就是第一个指针后移，如果相加结构大于S，则让大的数值便小一些，即第二个指针迁移，直到前后指针相遇。

````C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int i=0,j=numsSize-1;
    int *result = (int *)malloc(sizeof(int)*2);
    while(i<j)
    {
        if(nums[i]+nums[j]==target)
        {
            result[0]=nums[i];
            result[1]=nums[j];
            break;
        }
        else if(nums[i]+nums[j]<target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return result;
}
````
