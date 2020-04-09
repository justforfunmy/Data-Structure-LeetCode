#### 环形链表

给定一个链表，判断链表中是否有环。

来源：[LeetCode](https://leetcode-cn.com/problems/linked-list-cycle/)


#### 题解

快慢指针，两个指针如果能相遇，就是环形的。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head)
    {
        return false;
    }
    struct ListNode *fast,*slow;
    slow=head;
    fast=head->next;
    while(fast&&fast->next)
    {
        if(fast->val==slow->val)
        {
            return true;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return false;
}
````