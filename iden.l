%{
#include "y.tab.c"
%}
  
%%
[0-9]+ {return DIGIT;}
[a-zA-Z]+ {return LETTER;}
[\t] {;}
["\n"] {return 0;}
. {return yytext[0];}
%%
 
int yywrap()
{
 return 1;
 }
