#### 在排序数组中查找数字

统计一个数字在排序数组中出现的次数。

来源：[LeetCode](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)

#### 题解

二分法查找数字，然后左右查找相同的数字

````C
int search(int* nums, int numsSize, int target){
    if(numsSize<=0)
    {
        return 0;
    }
    int mid;
    int left=0,right=numsSize-1;
    int count=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]==target)
        {
            count++;
            int i=mid+1;
            while(i<numsSize)
            {
                if(nums[i]==target)
                {
                    count++;
                }
                else
                {
                    break;
                }
                i++;
            }
            i=mid-1;
            while(i>=0)
            {
                if(nums[i]==target)
                {
                    count++;
                }
                else
                {
                    break;
                }
                i--;
            }
            return count;
        }else if(nums[mid]>target)
        {
            right=mid-1;
        }else
        {
            left=mid+1;
        }
    }
    return count;    
}
````