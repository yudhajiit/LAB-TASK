
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL, *tail = NULL, *head2 = NULL, *tail2 = NULL, *fhead = NULL, *ftail = NULL;

void merge() {
    struct node *ptr = head, *temp = head2;

    if (tail != NULL) tail->next = NULL; 
    if (tail2 != NULL) tail2->next = NULL;

    
    while (ptr != NULL && temp != NULL) {
        if (ptr->data < temp->data) {
            if (fhead == NULL) {
                fhead = ftail = ptr;
            } else {
                ftail->next = ptr;
                ftail = ptr;
            }
            ptr = ptr->next;
        } else {
            if (fhead == NULL) {
                fhead = ftail = temp;
            } else {
                ftail->next = temp;
                ftail = temp;
            }
            temp = temp->next;
        }
    }

    
    while (ptr != NULL) {
        ftail->next = ptr;
        ftail = ptr;
        ptr = ptr->next;
    }

    
    while (temp != NULL) {
        ftail->next = temp;
        ftail = temp;
        temp = temp->next;
    }

        ftail->next = fhead;
    
}

void traverse() {
    if (fhead == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = fhead;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != fhead);
    printf("\n");
}

int main() {
    int i = 1, n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create first circular linked list
    while (i <= n) {
        struct node* nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &nnode->data);
        nnode->next = NULL;

        if (head == NULL) {
            head = tail = nnode;
        } else {
            tail->next = nnode;
            tail = nnode;
        }
        i++;
    }
    if (tail != NULL) tail->next = head; 

    // Create second circular linked list
    i = 1;
    while (i <= n) {
        struct node* nnode2 = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for second circular linked list node %d: ", i);
        scanf("%d", &nnode2->data);
        nnode2->next = NULL;

        if (head2 == NULL) {
            head2 = tail2 = nnode2;
        } else {
            tail2->next = nnode2;
            tail2 = nnode2;
        }
        i++;
    }
 tail2->next = head2; 

    
    merge();

  
    printf("Merged List: ");
    traverse();

    return 0;
}
