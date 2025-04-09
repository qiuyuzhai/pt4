#include "pt4.h"
#include<string.h>
//A character C representing a digit or a letter of the Latin alphabet is given. 
//If C is a digit then output the string "digit", 
//if C is a capital letter then output the string "capital", otherwise output the string "small".

void Solve(void)
{
    Task("String6");
    char c;
    GetC(&c);//这里取出来的是ASCLL码
    if (c>=48&&c<=57)
    PutS("digit");
    if(c>=65&&c<=90)
    PutS("capital");
    if(c>=97&&c<=122)
    PutS("small");
    
 }
