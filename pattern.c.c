#include<stdio.h>

char str[50],pat[50],rep[50],ans[50];
int i,j,k,c,m,flag=0;
void pattern();

void main()
{
    printf("Enter the main string\n");
    scanf("%s",str);
    printf("Enter the pattern string\n");
    scanf("%s",pat);
    printf("Enter the replace string\n");
    scanf("%s",rep);
    pattern();  //function call
}

void pattern()
{
    c=m=i=j=0;
    while(str[c]!=0)
    {
        if(str[m]==pat[i])
        {
            //true part
            i++;
            m++;
            if(pat[i]=='\0')
            {
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++)
                ans[j]=rep[k];
                i=0;
                m++;
                c=m;
            }
        }
        else
        {
            ans[j]=str[c];
            j++;
            c++;
            i=0;
            m=c;
        }//End of else
    }//End of while
    if(flag==0)
    printf("Pattern not found\n");
    else
    {
        ans[j]='\0';
        printf("Result:%s",ans);
    }
}