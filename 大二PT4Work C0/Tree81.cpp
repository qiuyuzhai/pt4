#include "pt4.h"
#include <iostream>
#include <string>
using namespace std;
string Op(int k) {
    if (k == -1) {
        return "+";
    }
    if (k == -2) {
        return "-";
    }
    return "*";
}

string Pref(Node* p) {
    if (p->Data >= 0) {
        return to_string(p->Data);
    }
    return Op(p->Data) + " " + Pref(p->Left) + " " + Pref(p->Right);
}


void Solve()
{
    Task("Tree81");
    PNode p1;
    pt>>p1;
    pt<<Pref(p1);

}
