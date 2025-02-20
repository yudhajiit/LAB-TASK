#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node *current = head, *prev = NULL;
    struct Node *temp;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Helper function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

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

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 31);
    insertEnd(&head, 31);

    printf("Linked list before removing duplicates: ");
    printList(head);

    removeDuplicates(head);

    printf("\nLinked list after removing duplicates: ");
    printList(head);

    return 0;
}
