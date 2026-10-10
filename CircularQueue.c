#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int cq[MAX],front=0,rear=-1,count=0;
int isempty()
{
    if(count==0)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(count==MAX)
    return 1;
    else
    return 0;
}
void insert()
{
    int x;
    if(isfull())
    {
        printf("Circular queue Overflow\n");
        return;
    }
    printf("Enter the element:");
    scanf("%d",&x);
    rear=(rear+1)%MAX;
    cq[rear]=x;
    count++;
}
int delete()
{
    int x;
    if(isempty())
    {
        printf("Circular queue underflow\n");
        return -1;
    }
    x=cq[front];
    front=(front+1)%MAX;
    count--;
    return x;
}
void display()
{
    int j=front;
    if(isempty())
    {
       printf("Circular queue underflow\n");
       return; 
    }
    for(int i=1;i<=count;i++)
    {
        printf("%d \n ",cq[j]);
        j=(j+1)%MAX;
    }
}
int main()
{
    int ch,ele;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("What's your choice?\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                    break;
            case 2:ele=delete();
                    if(ele!=-1)
                    printf("Deleted element:%d\n",ele);
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid Choice\n");
        }
    }
    return 0;
}