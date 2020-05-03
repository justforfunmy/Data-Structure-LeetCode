#### 二维数组中的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

来源：[LeetCode](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof)

#### 题解

+ 常规解法

因为是排序好的，所以可以先比较每个子数组的第一个值，如果小于目标值，再依次比较该数组里的值，如果等于目标值，直接返回true，如果大于目标值，跳出循环。要两个循环，时间复杂度为O(n^2);

````C
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize==0||*matrixColSize==0)
    {
        return false;
    }
    int i,j;
    for(i=0;i<matrixSize;i++)
    {
        if(matrix[i][0]<target)
        {
            for(j=0;j<*matrixColSize;j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        else if(matrix[i][0]==target)
        {
            return true;
        }
        else
        {
            break;
        }
    }
    return false;
}

````

+ 一次循环

可以从左下角或者右上角开始，因为这两个角上的值的两边分别是大于和小于角上的值，可以逐渐缩小范围。

````C
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    bool found = false;
    if(matrixSize>0&&*matrixColSize>0)
    {
        int i=0,j=matrixSize-1;
        while(i<*matrixColSize&&j>=0)
        {
            if(matrix[j][i]==target)
            {
                found=true;
                break;
            }
            else if(matrix[j][i]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    
    return found;

}
````