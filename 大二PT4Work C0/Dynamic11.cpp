#include "pt4.h"
using namespace std;
struct TStack//题目要求类型是TStack
{
    PNode Top;//top是指向堆栈顶部
};
void Push(TStack&s,int d)//添加元素到栈堆s//s是TStack类型的输入出的元素，d是输入元素
{
    PNode p=new TNode;//移动p（老工具人了）
    p->Data=d;
    p->Next=s.Top;//即原栈堆的顶指针
    s.Top=p;//新栈堆的顶指针是新输入的p
}
void Solve()
{
    Task("Dynamic11");//题目是从顶部插入n个给定数据
    TStack s;//自己创建了栈堆s
    int n;
    pt>>s.Top>>n;//这里的s.top是题目中的p1指针
    for (int i = 0; i < n; i++)
    {
        int d;
        pt>>d;
        Push(s,d);
    }
    pt<<s.Top;//输出新堆栈顶部的地址
}
