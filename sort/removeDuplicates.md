#### 删除排序数组中的重复项

给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

来源：[LeetCode](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array)

#### 题解

双指针，一个指针用来遍历，另一个指针用来存值。

````C
int removeDuplicates(int* nums, int numsSize){
    if(numsSize<=0)
    {
        return 0;
    }
    int i,j=0;
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[j])
        {
            nums[++j]=nums[i];
        }
    }
    return j+1;
}
````