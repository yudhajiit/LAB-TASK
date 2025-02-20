#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node at the end
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    struct Node* mergedTail = mergedHead;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            mergedTail->next = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    if (head1) {
        mergedTail->next = head1;
    } else {
        mergedTail->next = head2;
    }

    return mergedHead;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int arr1[] = {10, 20, 30, 40};
    int arr2[] = {5, 12, 25, 38};

    for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++) {
        append(&list1, arr1[i]);
    }

    for (int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++) {
        append(&list2, arr2[i]);
    }

    struct Node* mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
