#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Text1");
    string name;
    int n,k;
    pt>>name>>n>>k;
    ofstream f(name);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<k; j++)
        {
            f<<'*';
        }
        f<<endl;
    }
    f.close();
    

}
