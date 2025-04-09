#include "pt4.h"
#include<fstream>
using namespace std;
int n,k;
string s;
ofstream f;
void step(int n0,char k0,int w,int sw)
{
    sw+=w;//sw好像是sum of w，总的路径的重量
    if(sw<0)
      return;
    s+=k0;//k0这个符号接在s后面
    if (n0==n)
    {
        f<<s<<endl;
    }
    else
    {
        step(n0+1,'A',1,sw);
        step(n0+1,'B',-1,sw);
    }
    s.erase(n0);//erase(position);删除position处的一个字符(position是个string类型的迭代器)
}

void Solve()
{
    Task("Recur28");
    string name;
    pt>>n>>name;
    f.open(name);
    step(0,'C',0,0);
    f.close();



}
