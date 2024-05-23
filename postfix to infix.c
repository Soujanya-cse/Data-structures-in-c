#include <stdio.h>
#include <ctype.h>
#include <math.h>

int i, top = -1, elem, ans, a, b, num, stack[50];
char expp[50], symb;

void push();
int pop();

void push(int elem)
{
    top++;
    stack[top] = elem;
}

int pop()
{
    num = stack[top];
    top--;
    return num;
}

void main()
{
    printf("Enter the postfix expression:");
    scanf("%s", expp);
    for (i = 0; expp[i] != '\0'; i++)
    {
        symb = expp[i];
        if (isdigit(symb))
            push(symb - '0');
        else
        {
            a = pop();
            b = pop();
            switch (symb)
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b/ a);
                break;
            case '%':
                push(b % a);
                break;
            case '&':
                push(pow(b, a));
                break;
            case '^':
                push(pow(b, a));
                break;
            default:printf("Invalid operator");
            }
        }
    }
    ans = pop();
    printf("The result is %d", ans);
}