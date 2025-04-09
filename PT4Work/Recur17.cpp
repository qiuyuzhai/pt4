#include "pt4.h"
using namespace std;
string s;
int k;
char next_char()
{
    k ++;
    if (k < s.length())
        return s[k];
    return '0';

}
int jisuan(char c)
{
    if (c != '(')
    {
        return c - '0';
    }
        int a = jisuan(next_char());
        char op = next_char();
        int b = jisuan(next_char());
        next_char();
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        return a * b;
}

void Solve()
{
    Task("Recur17");
    pt >> s;
    k = -1;
    pt << jisuan(next_char());

}
