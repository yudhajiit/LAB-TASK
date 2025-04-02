
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head, *tail;
void inseindex()
{
    int i=1,pos;
    struct node*newnode;
    newnode= (struct node *)malloc(sizeof(struct node));
    printf("enter new node data");
    scanf("%d",&newnode->data);
    printf("pos");
    scanf("%d",&pos);
    newnode->next=NULL;
    struct node *ptr;
    ptr=head;
    while(i<pos-1){
        ptr=ptr->next;
        i++;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
}
void traverse()
{
    struct node*temp;
    temp=head;
    while(temp!=tail)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d \n",tail->data);
}
void main()
{
    int n, i = 1;
    struct node  *nnode;
    head = NULL;
    printf("enter no of nodes");
    scanf("%d", &n);
    while (i <= n)
    {
        nnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
    
        if (head == NULL)
        {
            head = tail = nnode;
        }
        else
        {
            tail->next = nnode;
           
            tail = nnode;
        }
        i++;
    }
    tail->next = head;
    inseindex();
    traverse();
   
}
