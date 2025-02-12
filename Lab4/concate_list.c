#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
void traverse(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node* concate(struct node*u,struct node *v)
{
   u->next=v;
   return u;
}

void main()
{
    struct node *head ,*sec,*third,*head2,*sec2,*third2;
    head=(struct node*)malloc(sizeof(struct node));
    sec=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head2=(struct node*)malloc(sizeof(struct node));
    sec2=(struct node*)malloc(sizeof(struct node));
    third2=(struct node*)malloc(sizeof(struct node));

    head->data=100;
    head->next=sec;

    sec->data=10;
    sec->next=third;

    third->data=97;
    third->next=NULL;

    head2->data=67;
    head2->next=sec2;

    sec2->data=22;
    sec2->next=third2;

    third2->data=56;
    third2->next=NULL;
    
   third= concate(third,head2);
    traverse(head);
}