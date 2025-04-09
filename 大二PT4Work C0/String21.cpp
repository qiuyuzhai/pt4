#include "pt4.h"
using namespace std;

void Solve()
 {
    Task("String21");
    int a;
    pt>>a;
    //Show(a);我应该早点先看看这个输入是一个个输入还是一下子输入一整个数
    for (int i = 0; a>0; i++)
    {
        int h=a%10+48;
        Show(h);
        pt<<(char)h;
        a=a/10;
    }
    
 }
 


