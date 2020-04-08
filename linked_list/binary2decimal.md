#### 二进制链表转十进制

给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。
已知此链表是一个整数数字的二进制表示形式。请你返回该链表所表示数字的 十进制值 。

来源：[力扣（LeetCode）](https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer)


通过位运算可以解，链表向下一个节点移动的过程就是二进制数向左移一位的过程。将移位后的值和节点的值做位或运算，
可以将节点的值写到二进制数的最低位。

#### 题解
````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    struct ListNode *ptr = head;
    int num=0;
    while(ptr)
    {
        num=(num<<1) | (ptr->val);
        ptr=ptr->next;
    }
    return num;
}
````