#include "pt4.h"
using namespace std;
bool deleteMin(PNode p, int rootval, bool prevmin)
{
    if (p != NULL)
    {
        prevmin = (p->Data < rootval) or prevmin;
        if (deleteMin(p->Left, rootval, prevmin))
            p->Left = NULL;
        if (deleteMin(p->Right, rootval, prevmin))
            p->Right = NULL;
        if (prevmin)
        {
            delete(p);
            return true;
        }
        else
            return false;
    }
    else 
        return true;
}
void Solve()
{
    Task("Tree42");
    PNode root = GetNode();
    deleteMin(root, root->Data, false);

}
