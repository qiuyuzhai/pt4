#include "pt4.h"
using namespace std;


void out(p)
{
    if p == None:
    return
    int d=p.Data
    p=p.Left
    out(p)
    put(d)
    while(p != None):
        p=p.Right
        out(p)
}

def solve():
    task("Tree92")
    out(GetNode())


start(solve)



