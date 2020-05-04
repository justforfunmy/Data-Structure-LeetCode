#### 青蛙跳台阶问题

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：[LeetCode](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof)

#### 题解

因为到最终的台阶的前一次跳，可以是1级或者2级，既可以理解为f(n)=f(n-1)+f(n-2),即斐波那契数列。

````C
int numWays(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    int a=1,b=1,sum=a+b;
    for(int i=2;i<n;i++)
    {
        a=b;
        b=sum;
        sum=(a+b)%1000000007;
    }
    return sum;
}
````