
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head, *tail;

void delindex(int x)
{int i=1;
    struct node *ptr,*u;
   
    ptr=head;
    while(i<x-1)
    {
        ptr=ptr->next;
        i++;
    }
    u=ptr->next;
    ptr->next=u->next;
    free(u);
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
   
    int pos;
    printf("pos");
    scanf("%d",&pos);
  delindex(pos);
  traverse();
}
