#### 斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：[LeetCode](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof)


#### 题解

递归方法效率太低，可以用循环法或者动态规划法

+ 循环法

````C
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int a=0,b=1,sum=a+b;
    for(int i=2;i<n;i++)
    {
        a=b;
        b=sum;
        sum=(a+b)%1000000007;
    }
    return sum;
}

````

+ 动态规划


动态规划的大致思路是把一个复杂的问题转化成一个分阶段逐步递推的过程，从简单的初始状态一步一步递推，最终得到复杂问题的最优解。

````C
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int *arr = (int *)malloc(sizeof(int)*(n+1));
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%1000000007;
    }
    return arr[n];
}
````