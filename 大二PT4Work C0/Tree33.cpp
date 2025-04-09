#include "pt4.h"
//An integer N (> 0) is given. 
//Create a balanced tree with N nodes and output the address of the tree root. 
//The value of each node should be equal to its level 
//(for example, the root value is 0, the value of its children is 1, and so on).
// Create the balanced tree be means of the recursive algorithm described in Tree32.
using namespace std;
void Creattree(PNode &p,int n,int l){
    if(n==0){
        return;
    }
    p = new TNode;
    p->Data = l;
    p->Left = nullptr;
    p->Right = nullptr;
    Creattree(p->Left,n/2,l+1);
    Creattree(p->Right,(n-1)/2,l+1);
}

void Solve()
{
    Task("Tree33");
    int n;
    pt >> n;
    PNode p;
    Creattree(p,n,0);
    pt << p;
}
