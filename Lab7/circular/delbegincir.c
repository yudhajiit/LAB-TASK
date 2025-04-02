
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head, *tail;
void delbegin()
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    tail->next=head;
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
    
   delbegin();
   traverse();
}
