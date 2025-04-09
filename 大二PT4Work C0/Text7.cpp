#include "pt4.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void Solve()
{
    Task("Text7");
    string s,name1,name2="$$.tmp";
    pt>>s>>name1;
    ifstream f1(name1);
    ofstream f2(name2);
    f2<<s<<endl;//原来文件里写数据是从上往下写的
    while (f1.peek()!=EOF)//就是文件f1还没到空集时
    {
        getline(f1,s);
        f2<<s<<endl;
    }
    f1.close();
    f2.close();
    remove(name1.c_str());
    rename(name2.c_str(),name1.c_str());//把后面的名字给到前面
}
