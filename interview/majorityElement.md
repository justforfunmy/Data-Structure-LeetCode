#### 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

来源：[LeetCode](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/)

#### 题解

投票算法

````C
int majorityElement(int* nums, int numsSize){
    int result;
    int count=0;
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(count==0)
        {
            result=nums[i];
            count=1;
        }
        else if(result==nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return result;
}
````

 