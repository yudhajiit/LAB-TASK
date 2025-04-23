#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left, * right;
};
struct node* make_node() {
    int ch;
    printf("Enter ch: ");
    scanf("%d", &ch);

    if (ch == -1) {
        return NULL; 
    }

    struct node* nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = ch;
    printf("Enter left child ");
    nnode->left = make_node();
    printf("Enter right child ");
    nnode->right = make_node();
    return nnode;
}
int height(struct node* root) {
    if (root == NULL) {
        return 0; 
    } else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        // Height of current node = 1 + max of left/right subtree heights
        if(left_height>right_height)
        {
            return left_height+1;
        }
        else{
            return right_height+1;
        }
    }
}

void inorder(struct node* n1) {
    if (n1 == NULL) return;
    inorder(n1->left);
    printf("%d ", n1->data);
    inorder(n1->right);
}

int main() {
    struct node* root = make_node();
    
    printf("\nInorder traversal: ");
    inorder(root);
    
    printf("\nHeight: %d\n", height(root));
    
    return 0;
}
