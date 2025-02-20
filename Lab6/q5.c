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

// Function to find the frequency of elements in the linked list
void findFrequency(struct Node* head) {
    struct Node* current = head;
    struct Node* index = NULL;
    int count;

    // Use a visited marker for elements that have been counted
    while (current != NULL) {
        count = 1;
        index = current->next;
        while (index != NULL) {
            if (current->data == index->data) {
                count++;
                index->data = -1; // Mark visited nodes
            }
            index = index->next;
        }
        if (current->data != -1) {
            printf("Element %d occurs %d times\n", current->data, count);
        }
        current = current->next;
    }
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
    insertEnd(&head, 20);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 31);
    insertEnd(&head, 31);

    printf("Linked list: ");
    printList(head);

    printf("\nFrequency of elements:\n");
    findFrequency(head);

    return 0;
}