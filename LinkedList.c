#include <stdio.h>
#include <stdlib.h>
struct node{
    char usn[10];
    char name[20];
    char prog[10];
    int sem;
    long int phno;
    struct node *next;
};
struct node *head=NULL;
int count=0;
struct node *create()
{
    struct node *x;
    x=(struct node*)malloc(sizeof(struct node));
    printf("Enter USN:");
    scanf("%s",x->usn);
    printf("\nEnter Name:");
    scanf("%s",x->name);
    printf("\nEnter Programme:");
    scanf("%s",x->prog);
    printf("\nEnter sem:");
    scanf("%d",&x->sem);
    printf("\nEnter Phone Number:");
    scanf("%ld",&x->phno);
    x->next=NULL;
    count++;
    return x;
}

void del_beg()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    ptr=head;
    head=head->next;
    printf("Student data deleted with USN: %s\n",ptr->usn);
    free(ptr);
    count--;
}
void del_end()
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        printf("Student data deleted with USN: %s\n",ptr->usn);
        free(ptr);
        count--;
        return;
    }
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=NULL;
    printf("Student data deleted with USN: %s\n",ptr->usn);
    free(ptr);
    count--;
}
void ins_beg()
{
    struct node *newnode;
    newnode=create();
    newnode->next=head;
    head=newnode;
}
void ins_end()
{
    struct node *newnode,*temp;
    temp=head;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("USN:%s\tName:%s\tProgramme:%s\tSem:%d\tPhone Number:%d\n",temp->usn,temp->name,temp->prog,temp->sem,temp->phno);
        temp=temp->next;
    }
    printf("COUNT:%d\n",count);
}
int main()
{
    int n,ch;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter data for Student%d\n",i);
        ins_beg();
    }
    while(1)
    {
        printf("1. Display\n");
        printf("2. Insertion at the end\n");
        printf("3. Deletion at the end\n");
        printf("4. Insertion at the Front\n");
        printf("5. Deletion at the Front\n");
        printf("6. Exit\n");
        printf("What's your choice?\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:display();
                    break;
            case 2:ins_end();
                    break;
            case 3:del_end();
                    break;
            case 4:ins_beg();
                    break;
            case 5:del_beg();
                    break;
            case 6:exit(0);
                    break;
            default:printf("Invalid Input");
        }
    }
    return 0;
}