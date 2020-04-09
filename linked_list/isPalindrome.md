#### 回文链表

编写一个函数，检查输入的链表是否是回文的。

来源：[LeetCode](https://leetcode-cn.com/problems/palindrome-linked-list-lcci/)

#### 题解

创建一个反转链表，然后逐一比对。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    struct ListNode *old = head;
    struct ListNode *now = NULL;
    struct ListNode *temp;
    while(head)
    {
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=head->val;
        temp->next=now;
        now=temp;
        head=head->next;
    }

    while(now)
    {
        if(now->val!=old->val)
        {
            return false;
        }
        now=now->next;
        old=old->next;
    }

    return true;

}
````