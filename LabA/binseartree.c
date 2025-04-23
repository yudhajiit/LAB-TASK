#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(struct node* root, int target) {
    if (root == NULL) {
        return 0; 
    }
    if (target == root->data) {
        return root->data; 
    } else if (target < root->data) {
        return search(root->left, target); // Search left subtree
    } else {
        return search(root->right, target); // Search right subtree
    }
}

struct node* create_bst() {
    struct node* root = NULL;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    return root;
}

// Inorder traversal 
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Free memory
void delete_tree(struct node* root) {
    if (root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

int main() {
    struct node* root = create_bst();
    
    printf("\nInorder traversal : ");
    inorder(root);
    
    int target;
    printf("\n\nEnter value to search: ");
    scanf("%d", &target);
    if (search(root, target)) {
        printf("%d is present \n", target);
    } else {
        printf("%d is not found \n", target);
    }
    
    delete_tree(root);
    return 0;
}
