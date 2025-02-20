#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to insert a new node at the end of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
       *head_ref = new_node;
       return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node *prev = NULL, *current = *head_ref, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Helper function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 5);
    insertEnd(&head, 20);
    insertEnd(&head, 21);
    insertEnd(&head, 12);
    insertEnd(&head, 14);
    insertEnd(&head, 7);

    printf("Linked list before reversing: ");
    printList(head);

    reverseList(&head);

    printf("\nLinked list after reversing: ");
    printList(head);

    return 0;
}
