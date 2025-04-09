#include "pt4.h"
//Positive integers A and B (A < B) are given. Output all integers in the range A to B,
// with an integer of a value K being output K times (for example, the number 3 must be output 3 times).

void Solve(void)
{
    Task("For39");
    int A,B;
    GetN(&A);
    GetN(&B);
    for ( int i = A; i <=B ; i++)
    {
        for (int k = 1; k<=i; k++)
        {
            PutN(i);

        }
        
       
    }
    

}
