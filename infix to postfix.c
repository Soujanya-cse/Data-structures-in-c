#include <stdio.h>
#include <ctype.h>
int top = -1, i, k = 0;

char infix[30], stack[30], postfix[30];
char sysm, elem;

void push(char elem)
{
    top++;
    stack[top] = elem;
}

char pop()
{
    elem = stack[top];
    top--;
    return elem;
}

int priority(char sysm)
{
    switch (sysm)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
    case '$':
        return 4;
    }
}

void evaluate()
{
    for (i = 0; infix[i] != '\0'; i++)
    {
        sysm = infix[i];
        if (sysm == '(')
            push(sysm);
        else if (isalnum(sysm)) /* if it is Operand */
        {
            postfix[k] = sysm;
            k++;
        }                     // end of else
        else if (sysm == ')') /* if it right parenthesis */
        {
            while (stack[top] != '(')
            {
                postfix[k] = pop();
                k++;
            } // end of while loop
            pop();
        } // end of elseif
        else
        {
            while (priority(stack[top]) >= priority(sysm))
            {
                postfix[k] = pop();
                k++;
            } // end of while loop
            push(sysm);
        } // end of else
    } //End of for loop
    while (stack[top] != '(')
    {
        postfix[k] = pop();
        k++;
    } // end of while
    postfix[k] = '\0';
}
int main()
{
    printf("Enter the infix expression\n");
    scanf("%s", infix);
    push('(');
    evaluate();
    printf("postfix expression is %s\n", postfix);
    return 0;
}
