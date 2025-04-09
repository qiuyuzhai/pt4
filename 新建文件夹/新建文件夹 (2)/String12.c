#include "pt4.h"
#include <string.h>
//Given a nonempty string and an integer N (> 0), 
//output a new string that contains the given string characters separated by N characters "*".

void Solve(void)
{
    Task("String12");
    char s[80];
    GetS(s);
    int n;
    GetN(&n);
    char s1[80];
    int h=strlen(s);//
    int h1=(h-1)*(n+1)+1;
    
    for (int i = 0; i < h1; i++)//
    {
        s1[i]='*';
    }
    s1[h1]=0;//
    ShowS(s1);
    s1[0]=s[0];
    s1[h1-1]=s[h-1];
    for (int i = 1; i <h-1; i++)
    {
        s1[(n+1)*i]=s[i];
    }
   //ShowS(s1);
    PutS(s1);
    

}

//strlen 指求出\0前面字符的个数
//我先把所有字符都变成星号

//这是老师改的，得在新建的字符串最后加一个0当结尾