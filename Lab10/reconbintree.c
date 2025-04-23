#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* buildTree(int preorder[], int* preIndex, int inStart, int inEnd, int* inMap, int minVal) {
    if (inStart > inEnd) {
        return NULL;
    }

    int currentVal = preorder[*preIndex];
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = currentVal;
    newNode->left = NULL;
    newNode->right = NULL;
    (*preIndex)++;

    if (inStart == inEnd) {
        return newNode;
    }

    int inPos = inMap[currentVal - minVal];

    newNode->left = buildTree(preorder, preIndex, inStart, inPos - 1, inMap, minVal);
    newNode->right = buildTree(preorder, preIndex, inPos + 1, inEnd, inMap, minVal);

    return newNode;
}

void printInorder(struct node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void freeTree(struct node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    int inorderArr[100], preorderArr[100];
    int n = 0;

    printf("Enter inorder traversal (space-separated): ");
    char input[500];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    while (token != NULL && n < 100) {
        inorderArr[n++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    int inorderSize = n;

    n = 0;
    printf("Enter preorder traversal (space-separated): ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " \n");
    while (token != NULL && n < 100) {
        preorderArr[n++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    int preorderSize = n;

    if (inorderSize != preorderSize) {
        printf("Error: Inorder and Preorder traversals have different lengths.\n");
        return 1;
    }

    if (inorderSize == 0) {
        printf("Empty tree.\n");
        return 0;
    }

    int minVal = inorderArr[0];
    int maxVal = inorderArr[0];
    for (int i = 1; i < inorderSize; i++) {
        if (inorderArr[i] < minVal) {
            minVal = inorderArr[i];
        }
        if (inorderArr[i] > maxVal) {
            maxVal = inorderArr[i];
        }
    }

    int range = maxVal - minVal + 1;
    int* inMap = (int*)malloc(range * sizeof(int));
    if (inMap == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < range; i++) {
        inMap[i] = -1;
    }

    for (int i = 0; i < inorderSize; i++) {
        inMap[inorderArr[i] - minVal] = i;
    }

    int preIndex = 0;
    struct node* root = buildTree(preorderArr, &preIndex, 0, inorderSize - 1, inMap, minVal);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    free(inMap);
    freeTree(root);

    return 0;
}
