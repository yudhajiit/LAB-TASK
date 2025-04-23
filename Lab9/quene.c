#include<stdio.h>
int front=-1,rear=-1;
int a[100];
int enq(int x)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        a[rear]=x;
    }
    else{
        rear++;
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
        front++;
    }
}
void traverse()
{
    int temp=front;
    while(temp!=rear)
    {
        printf("%d ",a[temp]);
        temp++;
    }
    printf("%d",a[temp]);
}
void main()
{
    enq(10);
    enq(20);
    enq(30);
    deq();
    traverse();
}
