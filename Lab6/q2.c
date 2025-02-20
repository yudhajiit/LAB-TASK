#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void segregateOddEven(struct node *head, struct node **odd, struct node **even) {
    *odd = NULL;
    *even = NULL;
    struct node *oddTail = NULL, *evenTail = NULL;

    while (head) {
        struct node *next = head->next;
        if (head->data % 2 == 0) {
            if (*even == NULL) {
                *even = head;
                evenTail = *even;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } else {
            if (*odd == NULL) {
                *odd = head;
                oddTail = *odd;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = next;
    }

    if (oddTail) oddTail->next = NULL;
    if (evenTail) evenTail->next = NULL;
}

void printList(struct node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->data = 5;
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->data = 20;
    head->next->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->next->data = 21;
    head->next->next->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->next->next->data = 12;
    head->next->next->next->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->next->next->next->data = 14;
    head->next->next->next->next->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->next->next->next->next->data = 7;
    head->next->next->next->next->next->next->next = NULL;

    printf("Original list:\n");
    printList(head);

    struct node *odd = NULL, *even = NULL;
    segregateOddEven(head, &odd, &even);

    printf("Odd list:\n");
    printList(odd);

    printf("Even list:\n");
    printList(even);

    return 0;
}