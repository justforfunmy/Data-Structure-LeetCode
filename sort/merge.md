#### 合并两个排序数组

给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

来源：[LeetCode](https://leetcode-cn.com/problems/sorted-merge-lcci)


#### 题解

对于B中的每个元素，利用插入排序原理将其放到A中的正确位置

````C
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=B[i];
        for(j=m;j>0&&A[j-1]>temp;j--)
        {
            A[j]=A[j-1];
        }
        A[j]=temp;
        m++;
    }
}
````