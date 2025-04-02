
#include <stdio.h>
#include <stdlib.h>

struct node {
   char data;
    struct node *next;
};

struct node *top = NULL;

void push(char str[]) {
    int i = 0;
    while (str[i] != '\0') {  
        struct node *nnode = (struct node *)malloc(sizeof(struct node));
        nnode->data = str[i];
        nnode->next = top;
        top = nnode;
        i++;
    }
}

void pop() {
    if (top == NULL) return;
    struct node *temp = top;
    top = top->next;
    free(temp);
}

int main() {
    char str[100];
    int n, i;
    
    printf("Enter the size of the string: ");
    scanf("%d", &n);
    getchar(); 
    
    for (i = 0; i < n; i++) {
        scanf("%c", &str[i]);
    }
    str[n] = '\0'; 
    
    push(str); 
    
  
    int test = 1;
    for (i = 0; i < n; i++) {
        if (top == NULL || top->data != str[i]) {
            test = 0;
            break;
        }
        pop();
    }
    
   
    while (top != NULL) pop();
    if(test!=0){
    printf("The string is  a palindrome.\n", str);
    }
    else{printf(" not palindrome");}
    return 0;
}
