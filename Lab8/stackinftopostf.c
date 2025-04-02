
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

struct node *top = NULL;

void push(char c) {
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = c;
    nnode->next = top;
    top = nnode;
}

void pop() {
    if (top == NULL) return;
    struct node *temp = top;
    top = top->next;
    free(temp);
}

//  operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[], int n) {
    int j = 0; // Index  postfix array

    for (int i = 0; i < n; i++) {
        char c = infix[i];
        
        // If operand, add to output
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }
        //  (
        else if (c == '(') {
            push(c);
        }
        //  )
        else if (c == ')') {
            while (top != NULL && top->data != '(') {
                postfix[j++] = top->data;
                pop();
            }
            pop(); // Remove '(' from stack
        }
        
        else {
            while (top != NULL && precedence(top->data) >= precedence(c)) {
                postfix[j++] = top->data;
                pop();
            }
            push(c);
        }
    }

    while (top != NULL) {
        postfix[j++] = top->data;
        pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    int n;

    printf("Enter the size of the expression: ");
    scanf("%d", &n);
    getchar();

   

    printf("Enter the infix expression: ");
    for (int i = 0; i < n; i++) {
        scanf("%c", &infix[i]);
    }
    infix[n] = '\0';

    // Convert to postfix
    infixToPostfix(infix, postfix, n);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
