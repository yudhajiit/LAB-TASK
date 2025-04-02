
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
struct node *head, *tail;

void delindex()
{
    int i=1,pos;
    printf("pos");
    scanf("%d",&pos);
    struct node *ptr;
    ptr=head;
    while(i<pos){
        ptr=ptr->next;
        i++;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
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
        nnode->prev = NULL;
        if (head == NULL)
        {
            head = tail = nnode;
        }
        else
        {
            tail->next = nnode;
            nnode->prev = tail;
            tail = nnode;
        }
        i++;
    }
    tail->next = NULL;
    delindex();
   traverse();
}
