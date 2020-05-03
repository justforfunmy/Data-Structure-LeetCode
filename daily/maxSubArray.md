#### 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

来源：[LeetCode](https://leetcode-cn.com/problems/maximum-subarray/)

#### 题解

````C
int maxSubArray(int* nums, int numsSize){
    int sum=nums[0],max=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(sum>0)
        {
            sum=sum+nums[i];
        }
        else
        {
            sum=nums[i];
        }
        max=sum>max?sum:max;
    }
    return max;
}
````