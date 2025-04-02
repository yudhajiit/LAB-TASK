
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head=NULL, *tail=NULL,*head2=NULL,*tail2=NULL;

void concate()
{
   tail->next=head2;
   tail2->next=head;
}
void traverse()
{
    struct node*temp;
    temp=head;
    while(temp!=tail2)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d \n",tail2->data);
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


    i=1;
    struct node  *nnode2;
    printf("enter no of nodes for second circular ll");
    scanf("%d", &n);
    while (i <= n)
    {
        nnode2 = (struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d", &nnode2->data);
        nnode2->next = NULL;
    
        if (head2 == NULL)
        {
            head2 = tail2 = nnode2;
        }
        else
        {
            tail2->next = nnode2;
           
            tail2 = nnode2;
        }
        i++;
    }
    tail2->next = head2;
    concate();
    traverse();

}
