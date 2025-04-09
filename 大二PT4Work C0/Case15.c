#include "pt4.h"
#include<string.h>
//The suits of playing cards are numbered as: 1 — spades, 2 — clubs, 3 — diamonds, 4 — hearts.
// Card values "Jack", "Queen", "King", "Ace" are numbered as 11, 12, 13, 14 respectively.
// A card value N (as an integer in the range  6 to 14) and a suit M (as an integer in the range 1 to 4) are given.
// Output the card description as: "six of diamonds", "queen of spades", etc.

void Solve(void)
{
    Task("Case15");
    int N,M;
    GetN(&N);
    GetN(&M);
    char s[80];
    switch(N)
    {
        case 6:strcpy(s,"six");break;
        case 7:strcpy(s,"seven");break;
        case 8:strcpy(s,"eight");break;
        case 9:strcpy(s,"nine");break;
        case 10:strcpy(s,"ten");break;
        case 11:strcpy(s,"jack");break;
        case 12:strcpy(s,"queen");break;
        case 13:strcpy(s,"king");break;
        case 14:strcpy(s,"ace");break;
    }
    switch (M)
    {
        case 1:strcat(s," of spades");break;
        case 2:strcat(s," of clubs");break;
        case 3:strcat(s," of diamonds");break;
        case 4:strcat(s," of hearts");break;
    }
    PutS(s);

}
