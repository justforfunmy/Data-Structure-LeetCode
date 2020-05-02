#### 最小的k个数

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

来源:[LeetCode](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)

#### 题解

快速排序，输出前k个数

````C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quicksort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left, j = right ;
	int key = arr[left];
	int temp;
	while (i < j)
	{
		while (i < j && arr[j] >= key)
		{
			j--;
		}
		arr[i] = arr[j];
		while (i < j && arr[i] <= key)
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = key;
	//对左右两边分别进行快速排序
	quicksort(arr, left, i - 1);
	quicksort(arr, i + 1, right);
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    quicksort(arr,0,arrSize-1);
    *returnSize=k;
    return arr;
}
````