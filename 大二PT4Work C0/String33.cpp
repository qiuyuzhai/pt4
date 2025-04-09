#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String33");
    string s,s0;
    pt>>s>>s0;
    size_t k=s.find(s0);//s中第一次出现s0的位置返回给k
    if (k!=s.npos)
        s.erase(k,s0.length());//s中删除从k开始的长度为s0.length()的数据
    pt<<s;
    
}
//string::find
//string::erase