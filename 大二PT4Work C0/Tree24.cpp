#include "pt4.h"//齐心文件有22
using namespace std;
//A pointer P1 to the root of a nonempty tree is given. 
//Using inorder tree walk find the last node with the maximal odd value and output its address P2. 
//If the tree does not contain nodes with odd values then output nil.
//这题不得借助python的tree24类似的题
int dmax;//他这个glabal是真央用的原来
PNode pmax;
void CNodeOutput(PNode p)//直接把13题的拿来改一下就用了
{
    
    if (p==NULL)
        return;
    CNodeOutput(p->Left);
    if (p->Data%2!=0 and p->Data>=dmax)//等于号是保证输出的是最后的那个
    {
        dmax=p->Data;
        pmax=p;
    }
    CNodeOutput(p->Right);
}

void Solve()
{
    Task("Tree24");
    PNode p1=GetNode();
    pmax=NULL;
    dmax=-1;
    CNodeOutput(p1);
    pt<<pmax;

}
