#### 排序字符串

字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。

S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。

返回任意一种符合条件的字符串T。

来源：[LeetCode](https://leetcode-cn.com/problems/custom-sort-string)


#### 题解

对于每一个S中的字符，找到T中的字符并将其放置到前面，采用交换策略。

````C
char * customSortString(char * S, char * T){
    int i,j;
    int p=0;
    int sLen=strlen(S);
    int tLen=strlen(T);
    char temp;
    char swap;
    for(i=0;i<sLen;i++)
    {
        temp=S[i];
        for(j=p;j<tLen;j++)
        {
            if(T[j]==temp)
            {
                swap=T[p];
                T[p]=temp;
                T[j]=swap;
                p++;
            }
        }
    }
    return T;
}
````