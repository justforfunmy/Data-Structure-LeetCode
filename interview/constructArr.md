#### 

给定一个数组` A[0,1,…,n-1]`，请构建一个数组 `B[0,1,…,n-1]`，其中 B 中的元素 `B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]`。不能使用除法。

来源：[LeetCode](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof)

#### 题解

两个辅助数组。

````C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){
    int* B = (int *)malloc(sizeof(int)*aSize);
    int* C = (int *)malloc(sizeof(int)*aSize);
    int* D = (int *)malloc(sizeof(int)*aSize);
    int count=1;
    for(int i=0;i<aSize;i++)
    {
        C[i]=count;
        count=count*a[i];
    }
    count=1;
    for(int  j=aSize-1;j>=0;j--)
    {
        D[j]=count;
        count=count*a[j];
    }
    for(int k=0;k<aSize;k++)
    {
        B[k]=C[k]*D[k];
    }
    free(C);
    free(D);
    *returnSize = aSize;
    return B;
}
````