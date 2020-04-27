#### 二进制中1的个数

请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

来源：[LeetCode](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof)

#### 题解

位运算的效率要比除法运算快很多

````C
int hammingWeight(uint32_t n) {
    int count=0;
    unsigned int flag=1;
    while(flag)
    {
        //比较最低位是不是1
        if(n&flag)
        {
            count++;
        }
        //flag左移一位，即比较的位置向前一位
        flag=flag<<1;
    }
    return count;
}

````