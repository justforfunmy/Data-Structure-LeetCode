#include<stdio.h>

void quicksort(int arr[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int i=left,j=right-1;
    //确定枢纽元为最后一个元素
    int key=arr[right];
    int temp;
    while(i<j)
    {
        //i从头开始遍历，找到第一个大于key的值
        while(arr[i]<key)
        {
            i++;
        }
        //j从倒数第二个开始遍历，找到第一个小于key的值
        while(arr[j]>key)
        {
            j--;
        }
        //当i<j时，交换两个位置上的值
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    //交换位置i上的值和枢纽元，至此，枢纽元左边是小于它的值，右边是大于它的值
    arr[right]=arr[i];
    arr[i]=key;
    //对左右两边分别进行快速排序
    quicksort(arr,left,i-1);
    quicksort(arr,i+1,right);
}

void main()
{
    int a[8]={11,23,4,25,9,0,1,6};
    quicksort(a,0,7);
    for(int i=0; i<8; i++)
        printf("%d ", a[i]);
}