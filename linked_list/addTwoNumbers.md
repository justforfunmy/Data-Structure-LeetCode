#### 链表求和

给定两个用链表表示的整数，每个节点包含一个数位。
这些数位是反向存放的，也就是个位排在链表首部。
编写函数对这两个整数求和，并用链表形式返回结果。

来源：[LeetCode](https://leetcode-cn.com/problems/sum-lists-lcci/)

#### 题解

相当于加法竖式计算的方式。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = l3;
    struct ListNode *temp;
    int num=0;//进位
    while(l1 || l2 || num!=0)
    {
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        num=(l1?l1->val:0)+(l2?l2->val:0)+num;
        temp->val=num%10;
        temp->next=NULL;
        l3->next=temp;
        l3=temp;
        num=num/10;
        l1=l1?l1->next:0;
        l2=l2?l2->next:0;
    }
    return head->next;
}
````