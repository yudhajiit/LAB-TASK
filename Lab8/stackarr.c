
#include <stdio.h>

int stack[5];
int top=-1;
int k=1;
void push()
{
    int data;
  
    if(top==5-1)
    {if(k==1)
        {printf("overflow condition\n");
        k++;}
    }
    else{if(top<5-1){
        printf("enter data");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
    }
    }
}
void pop(){
    int data;
    if(top ==-1)
    {
        printf("underflow condition\n");
    }
    else{
        data=stack[top];
        printf("deleted ele %d \n",data);
        top--;
    }
}
void display()
{printf("final stack ");
    while(top>=0)
    {
        printf("%d ",stack[top]);
        top--;
    }
}
void main()
{
    push();
    push();
    push();
    pop();
    display();
}
