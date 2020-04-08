#### 合并连个有序链表

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

来源:[LeetCode](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)

#### 题解

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp = l3;
    while(l1 && l2)
    {
        if(l1->val<l2->val)
        {
            l3->next=l1;
            l1=l1->next;
        }
        else
        {
            l3->next=l2;
            l2=l2->next;
        }
        l3=l3->next;
    }
    l3->next=l1==NULL?l2:l1;
    return temp->next;
}
````