#include "pt4.h"
using namespace std;
//An integer K (> 0) and references A1 and A2 to the first and last component of a nonempty doubly linked list are given.
// Perform a cyclic shift of all list components by K positions forward (that is, from the beginning toward the end of the list). 
//Output references to the first and last component of the resulting list. 
//The required shift should be performed as follows: 
//transform the given list to the circular one (see Dynamic55) 
//and then break this circular list at the position that corresponds to the given value of K. 
//Do not create new instances of the Node class

void Solve()
{
    Task("Dynamic57");
    int k;
    pt>>k;
    PNode a,b,c,d;
    pt>>a>>b;
    c=b;
    while (b&&k>0)
    {
        b=b->Prev;
        k-=1;
    }
    d=b->Next;
    d->Prev=a->Prev;
    b->Next=c->Next; 
    a->Prev=c;
    c->Next=a;
    pt<<d<<b;

    

}
