
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push ()
{
    int input;
    printf("enter data");
    scanf("%d",&input);
    struct node *nnode;
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=input;
    nnode->next=NULL;
    if(top==NULL)
    {
        top=nnode;
    }
    else{
        nnode->next =top;
        top=nnode;
    }
}
void pop()
{
    struct node *ptr;
        ptr=top;
        top=top->next;
        free(ptr);
    
}
void display()
{
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void main()
{
    push();
    push();
    push();
    pop();
    display();
}
