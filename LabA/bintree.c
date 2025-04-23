#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
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
void inorder(struct node*n1)
{
    if(n1==NULL)
    {
        return;
    }
    inorder(n1->left);
    printf("%d",n1->data);
    inorder(n1->right);
}
void preorder(struct node*n1)
{
    if(n1==NULL)
    {
        return;
    }
    printf("%d",n1->data);
    preorder(n1->left);
    preorder(n1->right);
}
void postorder(struct node *n1)
{
    if(n1==NULL)
    {
        return;
    }
    preorder(n1->left);
    preorder(n1->right);
    printf("%d",n1->data);
}
void main()
{
    struct node*root=make_node();
    printf("inorder=");
    inorder(root);
    printf("\n");
    printf("preorder=");
    preorder(root);
    printf("\n");
    printf("postorder=");
    postorder(root);
}
