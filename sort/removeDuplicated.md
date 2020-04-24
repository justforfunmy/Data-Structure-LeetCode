#### 删除排序数组中的重复项 II

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

来源：[LeetCode](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii)

#### 题解

将重复的第三个数移到末尾

````C
int removeDuplicates(int* nums, int numsSize){
    if(numsSize<=2)
    {
        return numsSize;
    }
    //i：遍历计数器，j:数据前移计数器，count:重复计数器，key:用于比较重复的值,del:记录删除的个数
    int i,j,count=1,key=nums[0],del=0;
    //遍历数组，因为删除的数据往尾部添加，所以i<numsSize-del
    for(i=1;i<numsSize-del;i++)
    {
        
        if(nums[i]==key)
        {
            //如果和当前key值相同，count加一
            count++;
        }
        else
        {
            //如果不同，key值更新，count还原为1
            key=nums[i];
            count=1;
        }

        if(count>2)
        {
            //当重复数大于2时，将该数据移到末尾，后面数据依次前移
            for(j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            nums[j]=key;
            //删除数加一
            del++;
            //重复数减一
            count--;
            //这步比较关键，因为数据前移了，所以遍历的下一个位置还是原位置
            i--;
        }
    }
    return numsSize-del;

}
````