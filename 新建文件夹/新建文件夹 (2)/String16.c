#include "pt4.h"
#include<string.h>
#include<ctype.h>
//Given a string, convert all Latin capital letters of the string to lowercase.
//给定一个字符串，将字符串的所有拉丁大写字母转换为小写。

void Solve(void)
{
    Task("String16");
    char s[80];
    GetS(s);
    for (char *p = s; *p!=0; p++)
        if(isupper(*p))//如果这个符号是大写字母，则。。。
            *p+=32;
    PutS(s);
    
    


}
