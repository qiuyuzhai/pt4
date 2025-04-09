#include "pt4.h"
//A sequence of nonzero integers terminated by zero is given 
//(the final zero is not an element of the sequence). Output the length of the sequence.




void Solve(void)
{
    Task("ZSeries12");
    int a;
    GetN(&a);
    int b=0;
    while(a!=0)
    {
      b++; 
      GetN(&a); 
    }
    PutN(b);


}
