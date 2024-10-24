#include <stdio.h>
#include <string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[20], ac[20], atk[20],act[10];
void check();

int main()
{
        puts("GRAMMAR is \nE->E+E \n E->E*E \n E->(E) \n E->id");
        puts("Enter the inut string");
        scanf("%s",a);
        c = strlen(a);
        strcpy(act, "SHIFT->");
        puts("Stack \t\t Input \t\t Action");
        for(k=0,i=0;j<c;k++,i++,j++)
        {
                if(a[j] == 'i' && a[j+1] == 'd')
                {
                        atk[i] = a[j];
                        atk[i + 1] = a[j + 1];
                        atk[i + 2] = '\0';
                        a[j] = ' ';
                        a[j + 1] = ' ';
                        printf("\n$%s\t\t%s$\t\t%sid", atk,a,act);
                        check();
                }
                else
                {
                        atk[i] = a[j];
                        atk[i+1] = '\0';
                        a[j] = ' ';
                        printf("\n$%s\t\t%s$\t\t%ssymbols", atk,a,act);
                        check();
                }
        }
        check();
        printf("\n");
}

void check()
{
        strcpy(ac, "REDUCE TO E");
        for(z=0;z<c;z++)
        {
        if(atk[z] == 'i' && atk[z+1] == 'd')
        {
                atk[z] = 'E';
                atk[z+1] = '\0';
                printf("\n$%s\t\t%s$\t\t%s", atk,a,ac);
                j++;
        }
        }
        for(z=0;z<c;z++)
        {
        if(atk[z] == '(' && atk[z+1] == 'E' && atk[z+2] == ')')
        {
                atk[z] = 'E';
                atk[z+1] = '\0';
                atk[z+1] = '\0';
                printf("\n$%s\t\t%s$\t\t%s",atk,a,ac);
                i = i - 2;
        }
        }
        for(z=0;z<c;z++)
        {
        if (atk[z] == 'E' && atk[z + 1] == '+' && atk[z+2] == 'E')
        {
                atk[z] = 'E';
                atk[z+1] = '\0';
                atk[z+2] = '\0';
                printf("\n$%s\t\t%s$\t\t%s",atk,a,ac);
                i = i-2;
        }
        }
        for(z=0;z<c;z++)
        {
        if(atk[z] == 'E' && atk[z+1] == '*' && atk[z+2] == 'E')
        {
                atk[z] = 'E';
                atk[z+1] = '\0';
                atk[z+1] = '\0';
                printf("\n$%s\t\t%s$\t\t%s",atk,a,ac);
                i = i - 2;
        }
        }
}
