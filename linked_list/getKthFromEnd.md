#### 链表中倒数第k个节点

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

来源：[力扣（LeetCode）](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof)

#### 题解
+ 方法一:常规方法

首先想到的方法是先循环遍历得到链表的长度n，然后再循环n-k次获得倒数第k个节点。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int len=0;
    struct ListNode *ptr = head;
    while(ptr)
    {
        len++;
        ptr=ptr->next;
    }
    int j=len-k;
    while(head && j>0)
    {
        j--;
        head=head->next;
    }
    return head;
}

````
+ 方法二：双指针

倒数第k个节点，可以理解成距离最后一个节点（这里可以认为是`NULL`）隔了k个节点。
所以可以用两个相隔k个节点的指针同步移动，当前面的指针移动到尾部时，后面的指针
刚好到距离前面指针k个节点的位置。

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *former=head;
    struct ListNode *latter=head;
    while(former!=NULL)
    {
        former=former->next;
        if(k>0){
            k--;
        }else{
            latter=latter->next;
        }
    }
    return latter;
}
````