#include<stdio.h>
#include<stdlib.h>
#define MAX 4

char q[MAX],elem;
int rear=-1,front=0,i,ele;

void insert();
void delete();
void display();

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}

void insert()
{
    if((front==0 && rear==MAX-1)||(front>0&&rear==front-1))
    printf("Queue Overflow\n");
    else
    {
        printf("Enter the character/element to be inserted\n");
        scanf(" %c",&ele);
        if(rear==MAX-1 && front>0)
        {
            rear=0;
            q[rear]=ele;
        }
        else if((front==0 && rear==-1)||(rear!=front-1))
        {
            rear++;
            q[rear]=ele;
        }
    }
}

void delete()
{
    if(front==0 && rear==-1)
    printf("Queue Underflow\n");
    else

    {
        if(front==rear)
        {
            ele=q[front];
            front=0,rear=-1;
        }
        else if(front==MAX-1)
        {
            ele=q[front];
            front=0;
        }
        else
        {
            ele=q[front];
            front++;
        }
        printf("Deleted element is: %c\n",ele);
    }
}

void display()
{
    if(front==0 && rear==-1)
    printf("Queue is empty\n");
    else
    {
        printf("Queue contents are:\n");
        if(front>rear)
        {
            for(i=front;i<=MAX-1;i++)
            printf("%c\t",q[i]);
            for(i=0;i<=rear;i++)
            printf("%c\t",q[i]);
        }
        else
        {
            for(i=front;i<=rear;i++)
            printf("%c\t",q[i]);
        }
    }
}