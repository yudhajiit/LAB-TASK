#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
int k=0,cnt=0;
struct node *make_node()
{
    int ch;
    printf("enter ch");
    scanf("%d",&ch);
    struct node *nnode=(struct node *)malloc(sizeof(struct node));
    nnode->right=NULL;
    nnode->left=NULL;
    if(ch==-1)
    {return 0;}
    else{
        nnode->data=ch;
        printf("enter left child");
        nnode->left=make_node();
        printf("enter right child");
        nnode->right=make_node();
        return nnode;
    }
}
void leafnode(struct node*n1)
{
    if(n1==NULL)
    {
        return;
    }
    if(n1->left==NULL && n1->right==NULL)
    {
        cnt++;
    }
    leafnode(n1->left);
    leafnode(n1->right);
}
void totnode(struct node*n1)
{
    if(n1==NULL)
    {
        return;
    }
    k++;
    totnode(n1->left);
    totnode(n1->right);
}
void main()
{
    struct node*root=make_node();
    totnode(root);
    printf("total nodes");
    printf("%d",k);
    printf("\n");
    printf("leaf nodes=");
    leafnode(root);
    printf("%d",cnt);
}
