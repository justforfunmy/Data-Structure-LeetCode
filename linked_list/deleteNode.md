#### 删除节点

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。

来源：[LeetCode](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)

#### 题解

分两种情况考虑，如果被删除的节点是头节点，直接返回next节点即可。如果不是头节点，遍历查找，让被删节点的上一节点的next指向其下一个节点。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head->val==val)
    {
        return head->next;
    }
    struct ListNode *dumpy=head;
    struct ListNode *pre=head;
    head=head->next;
    while(head && head->val!=val)
    {
        pre=head;
        head=head->next;
    }
    pre->next=head->next;
    return dumpy;

}
````