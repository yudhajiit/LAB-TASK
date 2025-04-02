
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    char data;
    struct node *next;
};

struct node *top = NULL;

// Stack for evaluation (integers)
struct eval_node {
    int data;
    struct eval_node *next;
};
struct eval_node *eval_top = NULL;

// Push character (for infix to postfix)
void push(char c) {
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = c;
    nnode->next = top;
    top = nnode;
}

// Pop character (for infix to postfix)
void pop() {
    if (top == NULL) return;
    struct node *temp = top;
    top = top->next;
    free(temp);
}

// Push integer (for evaluation)
void eval_push(int value) {
    struct eval_node *new_node = (struct eval_node *)malloc(sizeof(struct eval_node));
    new_node->data = value;
    new_node->next = eval_top;
    eval_top = new_node;
}

// Pop integer (for evaluation)
int eval_pop() {
    if (eval_top == NULL) {
        printf("Error: Invalid postfix expression\n");
        exit(1);
    }
    struct eval_node *temp = eval_top;
    int value = temp->data;
    eval_top = eval_top->next;
    free(temp);
    return value;
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        char c = infix[i];
        if (isdigit(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != NULL && top->data != '(') {
                postfix[j++] = top->data;
                pop();
            }
            pop(); // Remove '('
        } else {
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

// Evaluate postfix expression
int evaluate_postfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            eval_push(c - '0'); // Convert char to int
        } else {
            int b = eval_pop();
            int a = eval_pop();
            switch (c) {
                case '+': eval_push(a + b); break;
                case '-': eval_push(a - b); break;
                case '*': eval_push(a * b); break;
                case '/': 
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    eval_push(a / b); 
                    break;
                default: 
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }
        }
    }
    int result = eval_pop();
    if (eval_top != NULL) {
        printf("Error: Malformed postfix expression\n");
        exit(1);
    }
    return result;
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

    infixToPostfix(infix, postfix, n);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
