#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 3
int top=-1;
int *stack=NULL;
void createStack()
{
        stack=(int *)malloc(MAX*sizeof(int));
}
int isempty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(top==MAX-1)
    return 1;
    else
    return 0;
}
void push(int x)
{
    if(isfull())
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=x;
}
int pop()
{
    if(isempty())
    {
        printf("stack underflow");
        return -1;
    }
    return stack[top--];
}
void display()
{
    if(isempty())
    {
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--)
    printf("%d\n",stack[i]);
}
int peek()
{
    if(isempty())
    {
        printf("stack underflow\n");
        return -1;
    }
    return stack[top];
}
int checkpalin()
{
    int num=0,rev=0,x,e=0;
    while(!isempty())
    {
        x=pop();
        num=x*pow(10,e)+num;
        e++;
        rev=rev*10+x;
    }
    if(num==rev)
    return 1;
    else
    return 0;
}

int main()
{
    createStack();
    int ch,x;
    while(1)
    {
       printf("1. push\n");
       printf("2. pop\n");
       printf("3. check palindrome\n");
       printf("4. display\n");
       printf("5. peek\n");
       printf("6. exit\n");
       printf("Whats your choice?\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:  printf("Enter the element to be pushed\n");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2: x=pop();
                    if(x!=-1)
                    printf("Popped element is %d\n",x);
                    break;
            case 3: if(checkpalin())
                    printf("palindrome\n");
                    else
                    printf("Not a palindrome\n");
                    break;
            case 4:display();
                    break;
            case 5: x=peek();
                    if(x!=-1)
                    printf("Top element is %d\n",x);
                    break;
            case 6:exit(0);
       }
    }
return 0;
}