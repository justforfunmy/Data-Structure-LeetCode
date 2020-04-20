#include<stdio.h>

typedef struct HeapStruct *PriorityQueue;

struct HeapStruct
{
    int capacity;
    int size;
    int *elements;
};

PriorityQueue initialize(int maxElements)
{
    PriorityQueue h;
    h=malloc(sizeof(struct HeapStruct));
    h->elements=malloc(sizeof(int)*(maxElements+1));
    h->capacity=maxElements;
    h->size=0;
    h->elements[0]=0;
    return h;
}

void insert(int x,PriorityQueue h)
{
    int i;
    for(i=++h->size;h->elements[i/2]>x;i=i/2)
    {
        h->elements[i]=h->elements[i/2];
    }
    h->elements[i]=x;
}

void main()
{

}