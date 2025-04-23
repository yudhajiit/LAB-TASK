#include<stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
int enq(int x)
{struct node *nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=x;
    nnode->next=NULL;
 if(front==NULL && rear==NULL)
 {
    front=rear=nnode;
 }
 else{
    rear->next=nnode;
    rear=nnode;
 }
}
void deq()
{struct node *temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("empty quene");
    }
    else if(front==rear)
    {
        rear=front=NULL;
    }
    else{
       front=front->next;
    }
    free(temp);
}
void traverse()
{
    struct node* temp=front;
    while(temp!=rear)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
void main()
{
    enq(10);
    enq(20);
    enq(30);
    deq();
    traverse();
}
