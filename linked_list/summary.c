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

//合并有序链表
struct ListNode *mergeList(struct ListNode * l1,struct ListNode* l2)
{
    struct ListNode* l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* dumpy = l3;
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
    return dumpy->next;
}

struct ListNode* mergeList2(struct ListNode* l1,struct ListNode* l2)
{
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    struct ListNode *node =  (struct ListNode *)malloc(sizeof(struct ListNode));
    if(l1->val<l2->val)
    {
        node->val=l1->val;
        node->next=mergeList2(l1->next,l2);
    }
    else
    {
        node->val=l2->val;
        node->next=mergeList2(l1,l2->next);
    }
    return node;
    
}

void main()
{
    struct ListNode *dumpy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dumpy->val=1;
    dumpy->next=NULL;
    printList(dumpy);
    printf("is empty ? %s \n",isEmpty(dumpy)?"yes":"no");
    insertNode(2,find(1,dumpy));
    insertNode(3,find(2,dumpy));
    insertNode(4,find(3,dumpy));
    insertNode(5,find(4,dumpy));
    printf("after insert :\n");
    printList(dumpy);
    deleteNode(2,dumpy);
    printf("after delete :\n");
    printList(dumpy);
    // struct ListNode *reverse = reverseList(dumpy);
    // printf("after reverse :\n");
    // printList(reverse);
    // struct ListNode *reverse2 = reverseList2(dumpy);
    // printf("after reverse :\n");
    // printList(reverse2);
    printf("add two numbers:\n");
    struct ListNode *l1= (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val=1;
    l1->next=NULL;
    insertNode(3,find(1,l1));
    insertNode(5,find(3,l1));
    printf("list l1:\n");
    printList(l1);

    struct ListNode *l2= (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val=2;
    l2->next=NULL;
    insertNode(3,find(2,l2));
    printf("list l2:\n");
    printList(l2);

    printf("after merged:\n");
    printList(mergeList2(l1,l2));
}