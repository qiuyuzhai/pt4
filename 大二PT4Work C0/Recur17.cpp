#include "pt4.h"
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<char> op; 
stack<int> num; 
unordered_map<char, int> pr = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} }; 

void eval() 
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    int x;
    if (c == '*') x = a * b;
    else if (c == '/') x = a / b;
    else if (c == '+') x = a + b;
    else x = a - b;
    num.push(x);
}

void Solve()
{
    Task("Recur17");
    string s;
    pt >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c)) 
        {
            int x = 0;
            int j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            num.push(x);
            i = j - 1;
        }
        else if (c == '(') op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(') eval();
            op.pop();
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }

    while (op.size()) eval();
    pt << num.top(); 
}


