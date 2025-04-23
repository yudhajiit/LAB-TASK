#include<stdio.h>
int front=-1,rear=-1;
#define n 5
int a[n];
int enq(int x)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        a[rear]=x;
    }
    else{
        rear=(rear+1)%n;
        a[rear]=x;
    }
}
void deq()
{
    if(front==-1 && rear==-1)
    {
        printf("empty quene");
    }
    else if(front==rear)
    {
        rear=front=-1;
    }
    else{
        front=(front+1)%n;
    }
}
void traverse()
{
    int temp=front;
    while(temp!=rear)
    {
        printf("%d ",a[temp]);
        temp=(temp+1)%n;
    }
    printf("%d",a[temp]);
}
void main()
{
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    enq(50);
    deq();
    enq(60);
    traverse();
}
