#include "pt4.h"
//A reference A0 to one of the components of a nonempty doubly linked list is given. 
//Output the amount N of the list components 
//and also references A1 and A2 to the first and last component respectively.
using namespace std;
//p0是双链表中的任意一个元素的指针，输出链表元素个数和前后顶指针
//他这个文件里的方法我没看懂
struct TStack  
{
    PNode Top;
    PNode Bottem;
};
int count_nodes(&s)
{
    int sm = 0;
    p = Top;
    while (p!=nullptr):
        sm++;
        p = p->next;
    return sm
};
void Solve()
{
    Task("Dynamic31");
    PNode p0;
    pt>>p0;
    TStack s;
    pt<<count_nodes(&s)<<s.Top<<s.Bottem;


}
