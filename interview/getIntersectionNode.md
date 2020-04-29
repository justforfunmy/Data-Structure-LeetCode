#### 两个链表的第一个公共节点

输入两个链表，找出它们的第一个公共节点。

来源：[LeetCode](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)

#### 题解

先计算两个链表的长度a,b，使用快慢指针，快指针先走|a-b|步。注意这里是节点完全相同，而不是值相同

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptr;
    int al=0,bl=0;
    int j;
    ptr=headA;
    while(ptr)
    {
        al++;
        ptr=ptr->next;
    }
    ptr=headB;
    while(ptr)
    {
        bl++;
        ptr=ptr->next;
    }
    if(al>bl)
    {
        j=al-bl;
        while(j>0)
        {
            headA=headA->next;
            j--;
        }
    }
    if(al<bl)
    {
        j=bl-al;
        while(j>0)
        {
            headB=headB->next;
            j--;
        }
    } 

    while(headA!=headB)
    {
        headA=headA->next;
        headB=headB->next;
    }
    return headA?headA:NULL;
}
````