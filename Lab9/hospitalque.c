
#include<stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int k=0;
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
 k++;
}
void traverse()
{
    struct node* temp=front;
    while(temp!=rear)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}
void update()
{
    struct node*temp;
    temp=front;
    int i=1;
    while(i<k)
    {
       temp->data=i;
       i++;
       temp=temp->next;
    }
    traverse();
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
    update();
    k--;
}

void main()
{
    enq(1);
    enq(2);
    enq(3);
    deq();
    enq(4);
    enq(5);
    deq();
   
}
