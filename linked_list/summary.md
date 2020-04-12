##  链表小结

### 链表结构

链表是一种以不连续的方式存储数据的数据结构。对于最基本的单链表，其每个节点不仅包含值`val`，也包含一个指向下一个节点地址的指针`next`。以C语言实现为例：

````C
#include<stdio.h>
#include<stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

//判断链表为空
int isEmpty(struct ListNode *head)
{
    return head==NULL;
}

//查找节点,找不到返回NULL
struct ListNode* find(int x, struct  ListNode* head)
{
    while(head && head->val!=x)
    {
        head=head->next;
    }
    return head;
}

//查找前驱节点
struct ListNode* findPrevious(int x, struct ListNode *head)
{
    if(head->val==x)
    {
        return NULL;
    }
    struct ListNode* pre = head;
    while(head && head->val!=x)
    {
        pre=head;
        head=head->next;
    }
    return head==NULL?NULL:pre;
}

//插入节点
void insertNode(int x, struct ListNode*position)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val=x;
    struct ListNode *temp=position->next;
    position->next=node;
    node->next=temp;
}

//删除节点
void deleteNode(int x, struct ListNode *head)
{

    //头删
    if(head->val==x)
    {
        struct ListNode *next = head->next;
        free(head);
        *head=*next;
    }
    struct ListNode *pre = findPrevious(x,head);
    if(pre)
    {
        struct ListNode *cur = pre->next;
        pre->next=cur->next;
        free(cur);
    }
}

void printList(struct ListNode *head)
{
    int idx = 0;
    while(head)
    {
        printf("%d --- element val is %d \n",idx,head->val);
        head=head->next;
    }
}

void main()
{
    struct ListNode *dumpy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dumpy->val=1;
    dumpy->next=NULL;
    printList(dumpy);
    printf("is empty ? %s \n",isEmpty(dumpy)?"yes":"no");
    insertNode(2,find(1,dumpy));
    printf("after insert :\n");
    printList(dumpy);
    deleteNode(2,dumpy);
    printf("after delete :\n");
    printList(dumpy);
}
````

注意：`free()`函数不会删除指针，而是将指针指向的内存释放。在删除节点的函数中，如果是头删，先获得后一个节点，即第二个节点，然后将头指针指向的内存释放，再将头指针指向第二个节点，`*head=*next`.

### 链表算法题

解决链表的问题，一般可以有两种方法：迭代和递归。

##### 题一：反转链表

核心思路：让节点的`next`值指向上一个节点，这里需要同时保存当前节点和前一个节点，并同时移动。

1. 双指针迭代法

遍历每个节点，并将当前节点的`next`指向上一个节点。这里需要定义指针变量`pre`保存前一个节点的指针，初始化为`NULL`(因为反转后的尾节点就是反转前的首节点。),并定义指针变量`cur`保存遍历到的节点。 当遍历完成时，`pre`保存的是原链表的尾节点，也就是新链表的首节点。

````C
//反转链表
struct ListNode * reverseList(struct ListNode *head)
{
    //如果链表为空或者只有一个节点，直接返回原链表
    if(!head || !head->next)
    {
        return head;
    }

    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
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

2. 递归

递归函数的作用是让节点的`next`指向上一节点。

````C
//递归反转
struct ListNode *reverseList2(struct ListNode *head)
{
    if(!head || !head->next)
    {
        return head;
    }

    struct ListNode *temp = reverseList2(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
````


##### 题二：合并连个有序链表

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。





