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
struct node* del(struct node*u,struct node *v)
{
    u=v;
    return u;
}
void main()
{
    struct node *head ,*sec,*third,*fourth;
    head=(struct node*)malloc(sizeof(struct node));
    sec=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth =(struct node*)malloc(sizeof(struct node));
    head->data=100;
    head->next=sec;

    sec->data=10;
    sec->next=third;
   
 
    third->data=98;
    third->next=fourth;

    fourth->data=44;
    fourth->next=NULL;

   
  head=del(head,sec);

    traverse(head);
}