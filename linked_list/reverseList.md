#### 反转链表

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

来源:[LeetCode](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

#### 题解

+ 双指针迭代

定义两个指针pre和cur,pre保存反转后的链表的头节点，cur保存当前迭代的节点。通过让当前节点的next指向上一个节点实现。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre=NULL,*cur=head;
    while(head)
    {
        head=head->next;
        cur->next=pre;
        pre=cur;
        cur=head;
    }
    return pre;
}
````

+ 递归

递归函数实现功能是让节点的后一节点的next指向当前节点。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head || !head->next)
    {
        return head;
    }
    struct ListNode *ret = reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return ret;
}
````