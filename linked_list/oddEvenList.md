#### 奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

来源:[LeetCode](https://leetcode-cn.com/problems/odd-even-linked-list/)

#### 题解

分为奇偶两个链表，然后连接起来。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head||!head->next)
    {
        return head;
    }
    struct ListNode *odd,*even,*even_head;
    odd=head;
    even=head->next;
    even_head=even;
    while(even&&even->next)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=even_head;
    return head;

}
````