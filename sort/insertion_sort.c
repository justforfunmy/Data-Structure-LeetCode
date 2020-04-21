#include<stdio.h>

//O(n^2)

int* insertSort(int* arr,int size)
{
    int i,j;
    for(i=1;i<size;i++)
    {
        int p = arr[i];
        //比p大的值都向后移一位
        for(j=i;j>0&&arr[j-1]>p;j--)
        {
            arr[j]=arr[j-1];
        }
        // 把p放到正确的位置
        arr[j]=p;
    }
    return arr;
}

void printArr(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d \n",arr[i]);
    }
}

void main()
{
    int arr[5] = {32,23,77,43,12};
    printf("original: \n");
    printArr(arr,5);
    printf("sorted: \n");
    printArr(insertSort(arr,5),5);

}