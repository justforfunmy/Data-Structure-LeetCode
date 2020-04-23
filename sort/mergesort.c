#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int temp[],int left,int mid,int right);

void mergeSort(int arr[],int temp[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(right+left)/2;
        //左边排序
        mergeSort(arr,temp,left,mid);
        //右边排序
        mergeSort(arr,temp,mid+1,right);
        //合并排序
        merge(arr,temp,left,mid,right);
    }

}

void merge(int arr[],int temp[],int left,int mid,int right)
{
    //i用来保存左边数组的下标，k用来保存右边数组的下标，l用来保存新数组的下标
    int i=left,k = mid+1,l=left;
    while(l!=mid+1 && k!=right+1)
    {
        //把两边中的较小值存入新的数组
        if(arr[l]<arr[k])
        {
            temp[i++]=arr[l++];
        }
        else
        {
            temp[i++]=arr[k++];
        }
    }
    //当有一边的数组遍历完之后，把另一边数组的剩余部分直接加到新数组的后面
    while(l!=mid+1)
    {
        temp[i++]=arr[l++];
    }
    while(k!=right+1)
    {
        temp[i++]=arr[k++];
    }
    //复制新数组的值到原先的数组
    int j;
    for(j=left;j<=right;j++)
    {
        arr[j]=temp[j];
    }

}

void main()
{
    int a[8]={11,23,4,25,9,0,1,6};
    int i;
    int *b=malloc(8*sizeof(int));
    mergeSort(a,b,0,7);
    for(i=0; i<8; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// #include <stdlib.h>
// #include <stdio.h>

// void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
// {
//     int i = startIndex, j = midIndex + 1, k = startIndex;
//     while (i != midIndex + 1 && j != endIndex + 1)
//     {
//         if (sourceArr[i] > sourceArr[j])
//             tempArr[k++] = sourceArr[j++];
//         else
//             tempArr[k++] = sourceArr[i++];
//     }
//     while (i != midIndex + 1)
//         tempArr[k++] = sourceArr[i++];
//     while (j != endIndex + 1)
//         tempArr[k++] = sourceArr[j++];
//     for (i = startIndex; i <= endIndex; i++)
//         sourceArr[i] = tempArr[i];
// }

// //内部使用递归
// void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
// {
//     int midIndex;
//     if (startIndex < endIndex)
//     {
//         midIndex = startIndex + (endIndex - startIndex) / 2; //避免溢出int
//         MergeSort(sourceArr, tempArr, startIndex, midIndex);
//         MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
//         Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
//     }
// }

// int main(int argc, char *argv[])
// {
//     int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
//     int i, b[8];
//     MergeSort(a, b, 0, 7);
//     for (i = 0; i < 8; i++)
//         printf("%d ", a[i]);
//     printf("\n");
//     return 0;
// }