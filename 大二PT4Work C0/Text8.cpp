#include "pt4.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Solve()
{
    Task("Text8");
    string s,name1,name2,name3="$$.tmp";
    pt>>name1>>name2;
    ifstream f1(name1);//f12是用来读的
    ifstream f2(name2);//f3是用来写的
    ofstream f3(name3);
    while (f2.peek()!=EOF)
    {
        getline(f2,s);
        f3<<s<<endl;
    }
    while(f1.peek()!=EOF)
    {
        getline(f1,s);
        f3<<s<<endl;
    }
    f1.close();
    f2.close();
    f3.close();
    remove(name1.c_str());
    remove(name2.c_str());
    rename(name3.c_str(),name1.c_str());
    


}
