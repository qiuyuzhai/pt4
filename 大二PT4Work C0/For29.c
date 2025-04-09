#include "pt4.h"
// An integer N (> 1) and two points A, B (A < B) on the real axis are given. 
//The segment [A, B] is divided into N sub-segments of equal length. 
//Output the length H of each sub-segment and then output the sequence of points

//A,    A + H,    A + 2·H,    A + 3·H,    …,    B,

//which forms a partition of the segment [A, B].

void Solve(void)
{
    Task("For29");
    int N;
    double A,B,H;
    GetN(&N);
    GetD(&A);
    GetD(&B); 
     H=(B-A)/N;
    //ShowD(H);
    PutD(H); 
    for(double i=0;i<=N;i++)//  
{
               
     PutD(A+i*H);
}
    
    
    
    
    

   





}
