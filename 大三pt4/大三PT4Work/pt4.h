#ifndef PT4H
#define PT4H
#include <windows.h>
#include <string>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

struct Node;

typedef Node TNode;
typedef Node *PNode;

void DeleteNode(PNode p);

struct Node
{
    int Data;
    Node *Next;
    Node *Prev;
    Node *Left;
    Node *Right;
    Node *Parent;
    static void operator delete(void *p)
    {
        DeleteNode((PNode)p);
    }
};

void Task(const char *Name);

DWORD Filter(DWORD dw);
class PTIO
{
};

PTIO &operator<<(PTIO &p, bool a);
PTIO &operator<<(PTIO &p, int a);
PTIO &operator<<(PTIO &p, double a);
PTIO &operator<<(PTIO &p, char a);
PTIO &operator<<(PTIO &p, const char *a);
PTIO &operator<<(PTIO &p, std::string a);
PTIO &operator<<(PTIO &p, PNode a);

PTIO &operator>>(PTIO &p, bool &a);
PTIO &operator>>(PTIO &p, int &a);
PTIO &operator>>(PTIO &p, double &a);
PTIO &operator>>(PTIO &p, char &a);
PTIO &operator>>(PTIO &p, char *a);
PTIO &operator>>(PTIO &p, std::string &a);
PTIO &operator>>(PTIO &p, PNode &a);

void PutB(bool a);
void PutN(int a);
void PutD(double a);
void PutC(char a);
void PutS(const char *a);
void PutS(std::string a);
void PutP(PNode a);

void GetB(bool *a);
void GetN(int *a);
void GetD(double *a);
void GetC(char *a);
void GetS(char *a);
void GetS(std::string &a);
void GetP(PNode *a);

void PutArrN(int *a, int n);
void PutArrD(double *a, int n);
void PutArrC(char *a, int n);
void PutArrS(void *a, int n, int dim2);
void GetArrN(int *a, int n);
void GetArrD(double *a, int n);
void GetArrC(char *a, int n);
void GetArrS(void *a, int n, int dim2);
void ShowArrN(int *a, int n);
void ShowArrD(double *a, int n);
void ShowArrC(char *a, int n);
void ShowArrS(void *a, int n, int dim2);

void PutMatrN(void *a, int m, int n, int dim2);
void PutMatrD(void *a, int m, int n, int dim2);
void GetMatrN(void *a, int m, int n, int dim2);
void GetMatrD(void *a, int m, int n, int dim2);
void ShowMatrN(void *a, int m, int n, int dim2);
void ShowMatrD(void *a, int m, int n, int dim2);

bool GetBool();
int GetInt();
double GetDouble();
char GetChar();
std::string GetString();
PNode GetNode();

extern PTIO pt;

void raisePT(const char *, const char *);

void ShowB(bool b);
void ShowN(int n);
void ShowD(double d);
void ShowC(char c);
void ShowS(const char *s);
void ShowS(std::string s);
void Show(const char *cmt);
void Show(std::string cmt);
void ShowW(const wchar_t *cmt);
void ShowW(std::wstring cmt);

void ShowLine(void);

void ShowLineB(bool b);
void ShowLineN(int n);
void ShowLineD(double d);
void ShowLineC(char c);
void ShowLineS(const char *s);
void ShowLineS(std::string s);
void ShowLine(const char *cmt);
void ShowLine(std::string cmt);
void ShowLineW(const wchar_t *cmt);
void ShowLineW(std::wstring cmt);

void RuAnsi(char *result, const wchar_t *source);
std::string RuAnsi(const wchar_t *source);
std::string RuAnsi(std::wstring source);

void SetPrecision(int n);
void SetWidth(int n);
void HideTask(void);
void ForceUnicode() { }

void Show(const char *cmt, bool b, int w = -1);
void Show(const char *cmt, int n, int w = -1);
void Show(const char *cmt, double d, int w = -1);
void Show(const char *cmt, char c, int w = -1);
void Show(const char *cmt, const char *s, int w = -1);
void Show(const char *cmt, std::string s, int w = -1);

void Show(std::string cmt, bool b, int w = -1);
void Show(std::string cmt, int n, int w = -1);
void Show(std::string cmt, double d, int w = -1);
void Show(std::string cmt, char c, int w = -1);
void Show(std::string cmt, const char *s, int w = -1);
void Show(std::string cmt, std::string s, int w = -1);

void Show(const wchar_t *cmt, bool b, int w = -1);
void Show(const wchar_t *cmt, int n, int w = -1);
void Show(const wchar_t *cmt, double d, int w = -1);
void Show(const wchar_t *cmt, char c, int w = -1);
void Show(const wchar_t *cmt, const char *s, int w = -1);
void Show(const wchar_t *cmt, std::string s, int w = -1);

void Show(std::wstring cmt, bool b, int w = -1);
void Show(std::wstring cmt, int n, int w = -1);
void Show(std::wstring cmt, double d, int w = -1);
void Show(std::wstring cmt, char c, int w = -1);
void Show(std::wstring cmt, const char *s, int w = -1);
void Show(std::wstring cmt, std::string s, int w = -1);

void Show(bool b, int w = -1);
void Show(int n, int w = -1);
void Show(double d, int w = -1);
void Show(char c, int w = -1);
void Show(const wchar_t *cmt);
void Show(std::wstring cmt);

void ShowLine(const char *cmt, bool b, int w = -1);
void ShowLine(const char *cmt, int n, int w = -1);
void ShowLine(const char *cmt, double d, int w = -1);
void ShowLine(const char *cmt, char c, int w = -1);
void ShowLine(const char *cmt, const char *s, int w = -1);
void ShowLine(const char *cmt, std::string s, int w = -1);

void ShowLine(std::string cmt, bool b, int w = -1);
void ShowLine(std::string cmt, int n, int w = -1);
void ShowLine(std::string cmt, double d, int w = -1);
void ShowLine(std::string cmt, char c, int w = -1);
void ShowLine(std::string cmt, const char *s, int w = -1);
void ShowLine(std::string cmt, std::string s, int w = -1);

void ShowLine(const wchar_t *cmt, bool b, int w = -1);
void ShowLine(const wchar_t *cmt, int n, int w = -1);
void ShowLine(const wchar_t *cmt, double d, int w = -1);
void ShowLine(const wchar_t *cmt, char c, int w = -1);
void ShowLine(const wchar_t *cmt, const char *s, int w = -1);
void ShowLine(const wchar_t *cmt, std::string s, int w = -1);

void ShowLine(std::wstring cmt, bool b, int w = -1);
void ShowLine(std::wstring cmt, int n, int w = -1);
void ShowLine(std::wstring cmt, double d, int w = -1);
void ShowLine(std::wstring cmt, char c, int w = -1);
void ShowLine(std::wstring cmt, const char *s, int w = -1);
void ShowLine(std::wstring cmt, std::string s, int w = -1);

void ShowLine(bool b, int w = -1);
void ShowLine(int n, int w = -1);
void ShowLine(double d, int w = -1);
void ShowLine(char c, int w = -1);
void ShowLine(const wchar_t *cmt);
void ShowLine(std::wstring cmt);

PTIO &operator<<(PTIO &p, std::size_t a);

void Show(const char *cmt, std::size_t n, int w = -1);
void Show(std::string cmt, std::size_t n, int w = -1);
void Show(const wchar_t *cmt, std::size_t n, int w = -1);
void Show(std::wstring cmt, std::size_t n, int w = -1);
void Show(std::size_t n, int w = -1);

void ShowLine(const char *cmt, std::size_t n, int w = -1);
void ShowLine(std::string cmt, std::size_t n, int w = -1);
void ShowLine(const wchar_t *cmt, std::size_t n, int w = -1);
void ShowLine(std::wstring cmt, std::size_t n, int w = -1);
void ShowLine(std::size_t n, int w = -1);

template <typename T1, typename T2>
PTIO &operator<<(PTIO &p, const std::pair<T1, T2> &a);

template <typename T>
PTIO &operator<<(PTIO &p, const std::vector<T> &a);

template <typename T>
PTIO &operator<<(PTIO &p, const std::deque<T> &a);

template <typename T>
PTIO &operator<<(PTIO &p, const std::list<T> &a);

template <typename T, typename Comp>
PTIO &operator<<(PTIO &p, const std::set<T, Comp> &a);

template <typename T, typename Comp>
PTIO &operator<<(PTIO &p, const std::multiset<T, Comp> &a);

template <typename T1, typename T2, typename Comp>
PTIO &operator<<(PTIO &p, const std::map<T1, T2, Comp> &a);

template <typename T1, typename T2, typename Comp>
PTIO &operator<<(PTIO &p, const std::multimap<T1, T2, Comp> &a);

template <typename T>
class ptin_iterator : public std::iterator<std::input_iterator_tag, T>
{
private:
    int state_;
    bool end_;
    T value_;

    void getNext()
    {
        end_ = state_ == 0;
        if (end_)
            return;
        --state_;
        pt >> value_;
    }

public:
    bool operator==(const ptin_iterator &it) const
    {
        return end_ && end_ == it.end_;
    }

    bool operator!=(const ptin_iterator &it) const
    {
        return !(*this == it);
    }

    ptin_iterator(int count) : value_(T())
    {
        state_ = count;
        if (state_ == 0)
            pt >> state_;
        if (state_ < 0)
            state_ = 0;
        getNext();
    }

    ptin_iterator() : state_(0), end_(true), value_(T())
    {
    }

    const T &operator*()
    {
        return value_;
    }

    const T *operator->()
    {
        return &value_;
    }

    ptin_iterator &operator++()
    {
        getNext();
        return *this;
    }

    ptin_iterator operator++(int)
    {
        ptin_iterator<T> prev = *this;
        getNext();
        return prev;
    }
};

template <typename T>
class ptout_iterator : public std::iterator<std::output_iterator_tag, T>
{
public:
    ptout_iterator &operator*()
    {
        return *this;
    }

    ptout_iterator &operator=(const T &value)
    {
        pt << value;
        return *this;
    }

    ptout_iterator &operator++()
    {
        return *this;
    }

    ptout_iterator &operator++(int)
    {
        return *this;
    }
};

template <typename T>
void Show(const char *cmt, std::vector<T> &cont);
template <typename T>
void Show(const char *cmt, std::deque<T> &cont);
template <typename T>
void Show(const char *cmt, std::list<T> &cont);
template <typename T, typename Comp>
void Show(const char *cmt, std::set<T, Comp> &cont);
template <typename T, typename Comp>
void Show(const char *cmt, std::multiset<T, Comp> &cont);
template <typename T1, typename T2, typename Comp>
void Show(const char *cmt, std::map<T1, T2, Comp> &cont);
template <typename T1, typename T2, typename Comp>
void Show(const char *cmt, std::multimap<T1, T2, Comp> &cont);
template <typename T1, typename T2>
void Show(const char *cmt, std::pair<T1, T2> &a);


template <typename T1, typename T2>
void Show(std::pair<T1, T2> &a)
{
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")");
}

template <typename T1, typename T2>
void ShowLine(std::pair<T1, T2> &a)
{
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")\n");
}

template <typename T1, typename T2>
void Show(const char *cmt, std::pair<T1, T2> &a)
{
    Show(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")");
}

template <typename T1, typename T2>
void Show(std::string cmt, std::pair<T1, T2> &a)
{
    Show(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")");
}

template <typename T1, typename T2>
void Show(const wchar_t *cmt, std::pair<T1, T2> &a)
{
    ShowW(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")");
}

template <typename T1, typename T2>
void Show(std::wstring cmt, std::pair<T1, T2> &a)
{
    ShowW(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")");
}

template <typename T1, typename T2>
void ShowLine(const char *cmt, std::pair<T1, T2> &a)
{
    Show(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")\n");
}

template <typename T1, typename T2>
void ShowLine(std::string cmt, std::pair<T1, T2> &a)
{
    Show(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")\n");
}

template <typename T1, typename T2>
void ShowLine(const wchar_t *cmt, std::pair<T1, T2> &a)
{
    ShowW(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")\n");
}

template <typename T1, typename T2>
void ShowLine(std::wstring cmt, std::pair<T1, T2> &a)
{
    ShowW(cmt);
    Show("(");
    Show("", a.first);
    Show(",");
    Show("", a.second);
    Show(")\n");
}

template <typename InIter>
void Show(InIter first, InIter last)
{
    for (; first != last;)
        Show("", *first++);
    ShowLine();
}

template <typename InIter>
void Show(InIter first, InIter last, const char *cmt)
{
    Show(cmt);
    for (; first != last;)
        Show("", *first++);
    ShowLine();
}

template <typename InIter>
void Show(InIter first, InIter last, std::string cmt)
{
    Show(cmt);
    for (; first != last;)
        Show("", *first++);
    ShowLine();
}

template <typename InIter>
void Show(InIter first, InIter last, const wchar_t *cmt)
{
    ShowW(cmt);
    for (; first != last;)
        Show("", *first++);
    ShowLine();
}

template <typename InIter>
void Show(InIter first, InIter last, std::wstring cmt)
{
    ShowW(cmt);
    for (; first != last;)
        Show("", *first++);
    ShowLine();
}

template <typename InIter>
void ShowLine(InIter first, InIter last)
{
    for (; first != last;)
    {
        Show("", *first++);
        ShowLine();
    }
}

template <typename InIter>
void ShowLine(InIter first, InIter last, const char *cmt)
{
    Show(cmt);
    ShowLine();
    for (; first != last;)
    {
        Show("", *first++);
        ShowLine();
    }
}

template <typename InIter>
void ShowLine(InIter first, InIter last, std::string cmt)
{
    Show(cmt);
    ShowLine();
    for (; first != last;)
    {
        Show("", *first++);
        ShowLine();
    }
}

template <typename InIter>
void ShowLine(InIter first, InIter last, const wchar_t *cmt)
{
    ShowW(cmt);
    ShowLine();
    for (; first != last;)
    {
        Show("", *first++);
        ShowLine();
    }
}

template <typename InIter>
void ShowLine(InIter first, InIter last, std::wstring cmt)
{
    ShowW(cmt);
    ShowLine();
    for (; first != last;)
    {
        Show("", *first++);
        ShowLine();
    }
}

template <typename T>
void Show(const char *cmt, std::vector<T> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}

template <typename T>
void Show(const char *cmt, std::deque<T> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}

template <typename T>
void Show(const char *cmt, std::list<T> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}

template <typename T, typename Comp>
void Show(const char *cmt, std::set<T, Comp> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}

template <typename T, typename Comp>
void Show(const char *cmt, std::multiset<T, Comp> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}

template <typename T1, typename T2, typename Comp>
void Show(const char *cmt, std::map<T1, T2, Comp> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}

template <typename T1, typename T2, typename Comp>
void Show(const char *cmt, std::multimap<T1, T2, Comp> &cont)
{
    Show(cmt);
    for (auto e : cont)
        Show("", e);
}


template <typename T1, typename T2>
PTIO &operator<<(PTIO &p, const std::pair<T1, T2> &a)
{
    return p << a.first << a.second;
}

template <typename T>
PTIO &operator<<(PTIO &p, const std::vector<T> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

template <typename T>
PTIO &operator<<(PTIO &p, const std::deque<T> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

template <typename T>
PTIO &operator<<(PTIO &p, const std::list<T> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

template <typename T, typename Comp>
PTIO &operator<<(PTIO &p, const std::set<T, Comp> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

template <typename T, typename Comp>
PTIO &operator<<(PTIO &p, const std::multiset<T, Comp> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

template <typename T1, typename T2, typename Comp>
PTIO &operator<<(PTIO &p, const std::map<T1, T2, Comp> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

template <typename T1, typename T2, typename Comp>
PTIO &operator<<(PTIO &p, const std::multimap<T1, T2, Comp> &a)
{
    for (auto e : a)
        p << e;
    return p;
}

void Solve();

#include "seh.h"

void PTManager_start();
void PTManager_free();

int main()
{
    PTManager_start();
    try
    {
        __seh_try { Solve(); }
        __seh_except(Filter(GetExceptionCode1())) {}
        __seh_end_except
    }
    catch (const std::exception &e)
    {
        raisePT(e.what(), "");
    }
    PTManager_free();
    return 0;
}

#define MPICH_SKIP_MPICXX 1

std::string GetExename();

#endif
