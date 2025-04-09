#include "pt4.h"
#include <string.h>
// Given a character C and two strings S, S0,
// insert the string S0 into the string S before each occurrence of the character C.

void Solve(void)
{
    Task("String29");
    char c;
    GetC(&c);
    char s[80], s0[80], s1[80];
    GetS(s);
    GetS(s0);
    int h = strlen(s0);
    char *p1 = s1;
    for (char *p = s; *p != 0; p++)
    {
        if (*p == c)
        {
            memcpy(p1, s0, h);
            p1 += h;
        }
        *p1++ = *p;
    }
    *p1 = 0;
    PutS(s1);
}
