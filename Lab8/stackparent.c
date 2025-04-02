
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top = NULL;

// Push a single character onto the stack
void push(char c)
{
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = c;
    nnode->next = top;
    top = nnode;
}

void pop()
{
    if (top == NULL)
        return;
    struct node *temp = top;
    top = top->next;
    free(temp);
}

int isBalanced(char str[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == NULL)
            {
                return 0;
            }
            char topChar = top->data;
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '['))
            {
                pop();
            }
            else
            {
                return 0; 
            }
        }
    }
    return (top == NULL); 
}

int main()
{
    char str[100];
    int n;

    printf("Enter the size of the string: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the characters: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &str[i]);
    }
    str[n] = '\0';

    int result = isBalanced(str, n);

    
    while (top != NULL)
    {
        pop();
    }
    if(result!=0)
    {printf("Parentheses are balanced.\n", str);}
    else{printf("not balanced");}
    return 0;
}
