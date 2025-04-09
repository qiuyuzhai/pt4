#include "pt4.h"
using namespace std;

bool IsSquare(int k)
{
    int i=1;
    while(i*i<k)
        ++i;
    return i*i==k;
}

void Solve()
{
    Task("ZFunc10");                  
    int cnt = 0;
    for(int i=0;i<10;++i)
        if(IsSquare(GetInt()))
            ++cnt;
    pt << cnt;

}
