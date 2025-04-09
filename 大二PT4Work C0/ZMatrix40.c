#include "pt4.h"
#include<float.h>
#include<math.h>
//An M × N matrix of integers is given. 
//Find the index of the last row that contains the maximal amount of elements with equal values.
void Solve(void)
{
    Task("ZMatrix40");
    int m,n;
    GetN(&m);
    GetN(&n);
    int a[10],c[10];
    int s[10][10];
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        GetN(&s[i][j]);
  for(int i=0; i<10; i++)
    {
       a[i]=i;
    }
 for(int i=0; i<m; i++) 
    {
     int b[10];
     int max=-100;
     for(int z=0; z<=9; z++) 
      {
         b[z]=0;
      }
    for(int j=0; j<n; j++)
     {
       for(int k=0; k<=9; k++) {
       if(a[k]==s[i][j]) {
     b[k]++;
    }
   }
  }
  for(int l=0; l<=9; l++) {
   ShowN(b[l]);
    if(b[l]>max) {
     max=b[l];
     }
   }
  c[i]=max;
      ShowN(c[i]);
 }
 int w=-100;
 for(int i=0; i<m; i++) {
  if(c[i]>w) {
   w=c[i];
  }
 }
 for(int i=m-1;i>=0;i--)
 {
  if(c[i]==w)
  {
   PutN(i);
   break;
  }
 }
    }
    
    

    


