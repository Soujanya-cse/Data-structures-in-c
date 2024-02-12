#include<stdio.h>
#include<stdlib.h>
#define max 5
int st[max],top=-1,i,ch,elm,flag;
void push()
{
    if(top==(max-1))
    printf("Stack Overflow\n");
    else
    {
        printf("Enter the element\n");
        scanf("%d",&elm);
        top++;
        st[top]=elm;

    }
}

void pop()
{
    if(top==-1)
    printf("Stack Underflow\n");
    else
    {
        elm=st[top];
        top--;
        printf("Poped element=%d\n",elm);
    }
}

void palindrome()
{
    flag=1;
    for(i=0;i<=top/2;i++)
    {
        if(st[i]!=st[top-i])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    printf("Stack is Palindrome\n");
    else
    printf("Stack is not Palindrome\n");
}

void display()
{
    if(top==1)
    printf("Stack is empty\n");
    else
    {
        printf("Stack elements:\n");
        for(i=top;i>=0;i--)
        printf("%d\n",st[i]);
    }
}

void main()
{
    while(1)
    {
        printf("\n\tMENU\n1.Push\t2.Pop\t3.Display\t4.Palindrome\t5.EXIT\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:palindrome();
            break;
            case 5:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}