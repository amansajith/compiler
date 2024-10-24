%{
#include<stdio.h>
int flag=0;
%}

%token NUMBER;
%left '+''-'
%left '*''/''%'
%left '('')'



%%
ArithmeticExpression: E{
        printf("\nResult = %d\n",$$);
        return 0;
        }
E:E'+'E{$$=$1+$3;}
|E'-'E{$$=$1-$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|E'%'E{$$=$1%$3;}
|'('E')'{$$=$2;}
|NUMBER{$$=$1;}
;
%%

void main()
{
printf("Enter any arithmetic expression: \n");
yyparse();
if (flag == 0)
{
printf("Entered arithmetic expression is valid!\n");
}
}
void yyerror()
{
printf("\nEntered arithmetic expression is invalid!");
flag = 1;
}
