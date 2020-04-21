#### 按奇偶排序数组

给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

来源：[LeetCode](https://leetcode-cn.com/problems/sort-array-by-parity/)

#### 题解

遍历一次，奇数值从尾部放入数组，偶数值从头部放入数组

````C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *arr;
    arr = (int *)malloc(sizeof(int)*ASize);
    int i;
    int head=0,tail=ASize-1;
    for(i=0;i<ASize;i++)
    {
        if(A[i]%2!=0)
        {
            arr[tail--]=A[i];
        }
        else
        {
            arr[head++]=A[i];
        }
    }
    *returnSize=ASize;
    return arr;
}
````