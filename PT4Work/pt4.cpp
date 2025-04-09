//--------------------------------------------------//
//  Programming Taskbook module                     //
//  for Code::Blocks, Dev-C++ and VS Code           //
//                                                  //
//            Copyright (C) M.E.Abramyan, 2006-2023 //
//--------------------------------------------------//
//  WARNING! Altering the contents of this file     //
//  may cause Programming Taskbook to malfunction.  //
//--------------------------------------------------//

#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iterator>
using namespace std;

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

// Commom C section - begin

int prec = 2;
int width = 0;
int width1 = -1;

typedef void(WINAPI *TASK_)(const char *);
typedef void(WINAPI *GETB_)(int *);
typedef void(WINAPI *GETN_)(int *);
typedef void(WINAPI *GETR_)(double *);
typedef void(WINAPI *GETC_)(char *);
typedef void(WINAPI *GETS_)(char *);
typedef void(WINAPI *GETP_)(void **);
typedef void(WINAPI *PUTB_)(int);
typedef void(WINAPI *PUTN_)(int);
typedef void(WINAPI *PUTR_)(double);
typedef void(WINAPI *PUTC_)(char);
typedef void(WINAPI *PUTS_)(const char *);
typedef void(WINAPI *PUTP_)(void *);
typedef void(WINAPI *DISPOSEP_)(void *);
typedef void(WINAPI *STARTPT_)(int);
typedef void(WINAPI *NOPARAM_)(void);
typedef void(WINAPI *CHECKPT_)(char *, int *);
typedef void(WINAPI *RAISEPT_)(const char *, const char *);
HINSTANCE FLibHandle = 0;
TASK_ task_;
GETB_ getB_;
GETN_ getN_;
GETR_ getR_;
GETC_ getC_;
GETS_ getS_;
GETP_ getP_;
PUTB_ putB_;
PUTN_ putN_;
PUTR_ putR_;
PUTC_ putC_;
PUTS_ putS_;
PUTP_ putP_;
DISPOSEP_ disposeP_;
STARTPT_ startPT_;
NOPARAM_ freePT_;
CHECKPT_ checkPT_;
RAISEPT_ raisePT_;
PUTS_ show_;
NOPARAM_ hidetask_;
GETS_ getExename_;
RAISEPT_ ptruutf8_;
RAISEPT_ ptruansi2_;
RAISEPT_ ptutf8_;
int InfoT;
char InfoS[350];

void Task(const char *name)
{
  if (FLibHandle)
    (*task_)(name);
}

void DeleteNode(PNode p)
{
  if (FLibHandle)
    (*disposeP_)(p);
}

void MBox(const char *s)
{
  MessageBoxA(0, s, "Programming Taskbook 4", MB_ICONERROR);
}

void unloadlibPT()
{
  if (freePT_ != NULL)
    freePT_();
  if (FLibHandle)
    FreeLibrary(FLibHandle);
  FLibHandle = 0;
}

int LoadFunctions()
{
  task_ = (TASK_)GetProcAddress(FLibHandle, "task");
  if (task_ == 0)
    return 1;
  getB_ = (GETB_)GetProcAddress(FLibHandle, "getb");
  if (getB_ == 0)
    return 1;
  getN_ = (GETN_)GetProcAddress(FLibHandle, "getn");
  if (getN_ == 0)
    return 1;
  getR_ = (GETR_)GetProcAddress(FLibHandle, "getr");
  if (getR_ == 0)
    return 1;
  getC_ = (GETC_)GetProcAddress(FLibHandle, "getc");
  if (getC_ == 0)
    return 1;
  getS_ = (GETS_)GetProcAddress(FLibHandle, "gets");
  if (getS_ == 0)
    return 1;
  getP_ = (GETP_)GetProcAddress(FLibHandle, "getp");
  if (getP_ == 0)
    return 1;
  putB_ = (PUTB_)GetProcAddress(FLibHandle, "putb");
  if (putB_ == 0)
    return 1;
  putN_ = (PUTN_)GetProcAddress(FLibHandle, "putn");
  if (putN_ == 0)
    return 1;
  putR_ = (PUTR_)GetProcAddress(FLibHandle, "putr");
  if (putR_ == 0)
    return 1;
  putC_ = (PUTC_)GetProcAddress(FLibHandle, "putc");
  if (putC_ == 0)
    return 1;
  putS_ = (PUTS_)GetProcAddress(FLibHandle, "puts");
  if (putS_ == 0)
    return 1;
  putP_ = (PUTP_)GetProcAddress(FLibHandle, "putp");
  if (putP_ == 0)
    return 1;
  disposeP_ = (DISPOSEP_)GetProcAddress(FLibHandle, "disposep");
  if (disposeP_ == 0)
    return 1;
  startPT_ = (STARTPT_)GetProcAddress(FLibHandle, "startpt");
  if (startPT_ == 0)
    return 1;
  freePT_ = (NOPARAM_)GetProcAddress(FLibHandle, "freept");
  if (freePT_ == 0)
    return 1;
  checkPT_ = (CHECKPT_)GetProcAddress(FLibHandle, "checkpt");
  if (checkPT_ == 0)
    return 1;
  raisePT_ = (RAISEPT_)GetProcAddress(FLibHandle, "raisept");
  if (raisePT_ == 0)
    return 1;
  show_ = (PUTS_)GetProcAddress(FLibHandle, "show");
  if (show_ == 0)
    return 1;
  hidetask_ = (NOPARAM_)GetProcAddress(FLibHandle, "hidetask");
  if (hidetask_ == 0)
    return 1;
  getExename_ = (GETS_)GetProcAddress(FLibHandle, "getexename");
  if (getExename_ == 0)
    return 1;
  ptruutf8_ = (RAISEPT_)GetProcAddress(FLibHandle, "ptruutf8");
  if (ptruutf8_ == 0)
    return 1;
  ptruansi2_ = (RAISEPT_)GetProcAddress(FLibHandle, "ptruansi2");
  if (ptruansi2_ == 0)
    return 1;
  ptutf8_ = (RAISEPT_)GetProcAddress(FLibHandle, "ptutf8");
  if (ptutf8_ == 0)
    return 1;
  return 0;
}

void raisePT(const char *s1, const char *s2)
{
  if (FLibHandle)
    (*raisePT_)(s1, s2);
}

void PutB(bool a)
{
  if (FLibHandle)
  {
    if (a)
      (*putB_)(1);
    else
      (*putB_)(0);
  }
}

void PutN(int a)
{
  if (FLibHandle)
    (*putN_)(a);
}

void PutD(double a)
{
  if (FLibHandle)
    (*putR_)(a);
}

void PutC(char a)
{
  if (FLibHandle)
    (*putC_)(a);
}

void PutS(const char *a)
{
  if (FLibHandle)
    (*putS_)(a);
}

void PutP(PNode a)
{
  if (FLibHandle)
    (*putP_)(a);
}

void GetB(bool *a)
{
  int x0;
  if (FLibHandle)
  {
    x0 = 0;
    (*getB_)(&x0);
    *a = (x0 == 1);
  }
}

void GetN(int *a)
{
  int x0;
  if (FLibHandle)
  {
    x0 = 0;
    (*getN_)(&x0);
    *a = (int)x0;
  }
}

void GetD(double *a)
{
  if (FLibHandle)
    (*getR_)(a);
}

void GetC(char *a)
{
  if (FLibHandle)
    (*getC_)(a);
}

void GetS(char *a)
{
  if (FLibHandle)
  {
    InfoS[0] = '\0';
    (*getS_)(InfoS);
    strcpy(a, InfoS);
  }
}

void GetP(PNode *a)
{
  void *x0;
  if (FLibHandle)
  {
    x0 = NULL;
    (*getP_)(&x0);
    *a = (PNode)x0;
  }
}

void RuAnsi(char *result, const wchar_t *source)
{
  char *s = (char *)malloc(3 * wcslen(source) + 1);
  if (s != 0)
  {
    ptruansi2_((char *)source, s);
    strcpy(result, s);
    free(s);
  }
}

void ShowB(bool b)
{
  int w = width1 == -1 ? width : width1;
  if (b)
    sprintf(InfoS, "%*s", -w, "true ");
  else
    sprintf(InfoS, "%*s", -w, "false");
  (*show_)(InfoS);
  width1 = -1;
}

void ShowC(char c)
{
  int w = width1 == -1 ? width : width1;
  int w0 = 3;
  char s[5] = {'\'', c, '\'', '\0', '\0'};
  if (c == '\0' || c == '\n')
  {
    w0 = 4;
    s[1] = '\\';
    s[2] = c == '\0' ? '0' : 'n';
    s[3] = '\'';
  }
  char *s2 = (char *)malloc(w <= w0 ? w0 + 1 : (w + 1));
  if (s2 != 0)
  {
    sprintf(s2, "%*s", -w, s);
    ptruutf8_(s2, InfoS);
    (*show_)(InfoS);
    free(s2);
  }
  width1 = -1;
}

void ShowN(int n)
{
  int w = width1 == -1 ? width : width1;
  sprintf(InfoS, "%*d", w, n);
  (*show_)(InfoS);
  width1 = -1;
}

void ShowD(double d)
{
  int w = width1 == -1 ? width : width1;
  if (prec > 0)
    sprintf(InfoS, "%*.*f", w, prec, d);
  else
    sprintf(InfoS, "%*.*e", w, prec == 0 ? 6 : -prec, d);
  (*show_)(InfoS);
  width1 = -1;
}

void ShowS(const char *s)
{
  int w = width1 == -1 ? width : width1;
  int n = 0, neol = 0;
  for (int i = 0; s[i] != '\0'; ++i)
  {
    ++n;
    if (s[i] == '\n')
      ++neol;
  }
  n += neol + 2;
  char *s3 = (char *)malloc(n + 1);
  if (s3 != 0)
  {
    s3[n] = '\0';
    s3[n - 1] = '"';
    for (int i = n - neol -3; i >= 0; --i)
      if (s[i] != '\n')
        s3[i + neol + 1] = s[i];
      else
      {
        s3[i + neol + 1] = 'n';
        s3[i + neol] = '\\';
        --neol;
      }
    s3[0] = '"';
    if (n < w)
      n = w;
    char *s2 = (char *)malloc(n + 1);
    if (s2 != 0)
    {
      sprintf(s2, "%*s", -w, s3);
      char *s1 = (char *)malloc(3 * n + 1);
      if (s1 != 0)
      {
        ptruutf8_(s2, s1);
        (*show_)(s1);
        free(s1);
      }
      free(s2);
    }
    free(s3);
  }
  width1 = -1;
}

void Show(const char *cmt)
{
  int n = strlen(cmt);
  char *s2 = (char *)malloc(n + 1);
  if (s2 == 0)
    return;
  strcpy(s2, cmt);
  for (int i = n - 1; i >= 0; --i)
    if (s2[i] == ' ')
      n = i;
    else
      break;
  s2[n] = '\0';
  char *s1 = (char *)malloc(3 * n + 1);
  if (s1 != 0)
  {
    ptruutf8_(s2, s1);
    (*show_)(s1);
    free(s1);
  }
  free(s2);
}

void ShowW(const wchar_t *cmt)
{
  int n = wcslen(cmt);
  wchar_t *s2 = (wchar_t *)malloc((n + 1) * 2);
  if (s2 == 0)
    return;
  wcscpy(s2, cmt);
  for (int i = n - 1; i >= 0; --i)
    if (s2[i] == L' ')
      n = i;
    else
      break;
  s2[n] = L'\0';
  char *s1 = (char *)malloc(4 * n + 1);
  if (s1 != 0)
  {
    ptutf8_((char *)s2, s1);
    (*show_)(s1);
    free(s1);
  }
  free(s2);
}

void ShowLineB(bool b)
{
  ShowB(b);
  (*show_)("\n");
}

void ShowLineN(int n)
{
  ShowN(n);
  (*show_)("\n");
}

void ShowLineD(double d)
{
  ShowD(d);
  (*show_)("\n");
}

void ShowLineC(char c)
{
  ShowC(c);
  (*show_)("\n");
}

void ShowLineS(const char *s)
{
  ShowS(s);
  (*show_)("\n");
}

void ShowLine(const char *cmt)
{
  Show(cmt);
  (*show_)("\n");
}

void ShowLineW(const wchar_t *cmt)
{
  ShowW(cmt);
  (*show_)("\n");
}

void HideTask()
{
  (*hidetask_)();
}

void SetPrecision(int n)
{
  if (abs(n) <= 16)
    prec = n;
}

void SetWidth(int n)
{
  if (n >= 0 && n <= 100)
    width = n;
}

void SetW(int n)
{
  if (n >= 0 && n <= 100)
    width1 = n;
}

// Commom C section - end

class PTIO
{
};

PTIO &operator<<(PTIO &p, bool a)
{
  PutB(a);
  return p;
}

PTIO &operator<<(PTIO &p, int a)
{
  PutN(a);
  return p;
}

PTIO &operator<<(PTIO &p, double a)
{
  PutD(a);
  return p;
}

PTIO &operator<<(PTIO &p, char a)
{
  PutC(a);
  return p;
}

void PutS(string a)
{
  PutS(a.c_str());
}

PTIO &operator<<(PTIO &p, const char *a)
{
  PutS(a);
  return p;
}

PTIO &operator<<(PTIO &p, string a)
{
  PutS(a);
  return p;
}

PTIO &operator<<(PTIO &p, PNode a)
{
  PutP(a);
  return p;
}

PTIO &operator>>(PTIO &p, bool &a)
{
  GetB(&a);
  return p;
}

PTIO &operator>>(PTIO &p, int &a)
{
  GetN(&a);
  return p;
}

PTIO &operator>>(PTIO &p, double &a)
{
  GetD(&a);
  return p;
}

PTIO &operator>>(PTIO &p, char &a)
{
  GetC(&a);
  return p;
}

void GetS(string &a)
{
  GetS(InfoS);
  a = InfoS;
}

PTIO &operator>>(PTIO &p, char *a)
{
  GetS(a);
  return p;
}

PTIO &operator>>(PTIO &p, string &a)
{
  GetS(a);
  return p;
}

PTIO &operator>>(PTIO &p, PNode &a)
{
  GetP(&a);
  return p;
}

bool GetBool()
{
  bool a;
  GetB(&a);
  return a;
}

int GetInt()
{
  int a;
  GetN(&a);
  return a;
}

double GetDouble()
{
  double a;
  GetD(&a);
  return a;
}

char GetChar()
{
  char a;
  GetC(&a);
  return a;
}

string GetString()
{
  string a;
  GetS(a);
  return a;
}

PNode GetNode()
{
  PNode a;
  GetP(&a);
  return a;
}

string RuAnsi(const wchar_t *source)
{
  string res;
  char *s = (char *)malloc(3 * wcslen(source) + 1);
  if (s != 0)
  {
    ptruansi2_((char *)source, s);
    res = s;
    free(s);
  }
  return res;
}

string RuAnsi(wstring source)
{
  return RuAnsi(source.c_str());
}

void ShowS(string s)
{
  ShowS(s.c_str());
}

void Show(string cmt)
{
  Show(cmt.c_str());
}

void ShowW(wstring cmt)
{
  ShowW(cmt.c_str());
}

void ShowLineS(string s)
{
  ShowLineS(s.c_str());
}

void ShowLine(string cmt)
{
  ShowLine(cmt.c_str());
}

void ShowLineW(wstring cmt)
{
  ShowLineW(cmt.c_str());
}

void ShowLine(void)
{
  Show("\n");
}

void Show(const char *cmt, bool b, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowB(b);
}
void Show(const char *cmt, int n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowN(n);
}
void Show(const char *cmt, double d, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowD(d);
}
void Show(const char *cmt, char c, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowC(c);
}
void Show(const char *cmt, const char *s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowS(s);
}
void Show(const char *cmt, std::string s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowS(s);
}

void Show(std::string cmt, bool b, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowB(b);
}
void Show(std::string cmt, int n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowN(n);
}
void Show(std::string cmt, double d, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowD(d);
}
void Show(std::string cmt, char c, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowC(c);
}
void Show(std::string cmt, const char *s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowS(s);
}
void Show(std::string cmt, std::string s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowS(s);
}

void Show(const wchar_t *cmt, bool b, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowB(b);
}
void Show(const wchar_t *cmt, int n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowN(n);
}
void Show(const wchar_t *cmt, double d, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowD(d);
}
void Show(const wchar_t *cmt, char c, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowC(c);
}
void Show(const wchar_t *cmt, const char *s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowS(s);
}
void Show(const wchar_t *cmt, std::string s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowS(s);
}

void Show(std::wstring cmt, bool b, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowB(b);
}
void Show(std::wstring cmt, int n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowN(n);
}
void Show(std::wstring cmt, double d, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowD(d);
}
void Show(std::wstring cmt, char c, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowC(c);
}
void Show(std::wstring cmt, const char *s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowS(s);
}
void Show(std::wstring cmt, std::string s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowS(s);
}

void Show(bool b, int w = -1)
{
  SetW(w);
  ShowB(b);
}
void Show(int n, int w = -1)
{
  SetW(w);
  ShowN(n);
}
void Show(double d, int w = -1)
{
  SetW(w);
  ShowD(d);
}
void Show(char c, int w = -1)
{
  SetW(w);
  ShowC(c);
}
void Show(const wchar_t *cmt)
{
  ShowW(cmt);
}
void Show(std::wstring cmt)
{
  ShowW(cmt.c_str());
}

void ShowLine(const char *cmt, bool b, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineB(b);
}
void ShowLine(const char *cmt, int n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(const char *cmt, double d, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineD(d);
}
void ShowLine(const char *cmt, char c, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineC(c);
}
void ShowLine(const char *cmt, const char *s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineS(s);
}
void ShowLine(const char *cmt, std::string s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineS(s);
}

void ShowLine(std::string cmt, bool b, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineB(b);
}
void ShowLine(std::string cmt, int n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(std::string cmt, double d, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineD(d);
}
void ShowLine(std::string cmt, char c, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineC(c);
}
void ShowLine(std::string cmt, const char *s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineS(s);
}
void ShowLine(std::string cmt, std::string s, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineS(s);
}

void ShowLine(const wchar_t *cmt, bool b, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineB(b);
}
void ShowLine(const wchar_t *cmt, int n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(const wchar_t *cmt, double d, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineD(d);
}
void ShowLine(const wchar_t *cmt, char c, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineC(c);
}
void ShowLine(const wchar_t *cmt, const char *s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineS(s);
}
void ShowLine(const wchar_t *cmt, std::string s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineS(s);
}

void ShowLine(std::wstring cmt, bool b, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineB(b);
}
void ShowLine(std::wstring cmt, int n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(std::wstring cmt, double d, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineD(d);
}
void ShowLine(std::wstring cmt, char c, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineC(c);
}
void ShowLine(std::wstring cmt, const char *s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineS(s);
}
void ShowLine(std::wstring cmt, std::string s, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineS(s);
}

void ShowLine(bool b, int w = -1)
{
  SetW(w);
  ShowLineB(b);
}
void ShowLine(int n, int w = -1)
{
  SetW(w);
  ShowLineN(n);
}
void ShowLine(double d, int w = -1)
{
  SetW(w);
  ShowLineD(d);
}
void ShowLine(char c, int w = -1)
{
  SetW(w);
  ShowLineC(c);
}
void ShowLine(const wchar_t *cmt)
{
  ShowLineW(cmt);
}
void ShowLine(std::wstring cmt)
{
  ShowLineW(cmt.c_str());
}

PTIO &operator<<(PTIO &p, std::size_t a)
{
  PutN(a);
  return p;
}

void Show(const char *cmt, std::size_t n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowN(n);
}
void Show(std::string cmt, std::size_t n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowN(n);
}
void Show(const wchar_t *cmt, std::size_t n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowN(n);
}
void Show(std::wstring cmt, std::size_t n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowN(n);
}
void Show(std::size_t n, int w = -1)
{
  SetW(w);
  ShowN(n);
}

void ShowLine(const char *cmt, std::size_t n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(std::string cmt, std::size_t n, int w = -1)
{
  Show(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(const wchar_t *cmt, std::size_t n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(std::wstring cmt, std::size_t n, int w = -1)
{
  ShowW(cmt);
  SetW(w);
  ShowLineN(n);
}
void ShowLine(std::size_t n, int w = -1)
{
  SetW(w);
  ShowLineN(n);
}

string GetExename()
{
  char _getExename_[255];
  if (getExename_ == 0)
    _getExename_[0] = '\0';
  else
    getExename_(_getExename_);
  return string(_getExename_);
}

PTIO pt;

DWORD Filter(DWORD dw)
{
  if (dw == EXCEPTION_ACCESS_VIOLATION)
  {
    raisePT("ACCESS_VIOLATION", "");
  }
  if (dw == EXCEPTION_INT_DIVIDE_BY_ZERO)
  {
    raisePT("INT_DIVIDE_BY_ZERO", "");
  }
  if (dw == EXCEPTION_ARRAY_BOUNDS_EXCEEDED)
  {
    raisePT("ARRAY_BOUNDS_EXCEEDED", "");
  }
  if (dw == EXCEPTION_DATATYPE_MISALIGNMENT)
  {
    raisePT("DATATYPE_MISALIGNMENT", "");
  }
  if (dw == EXCEPTION_FLT_DENORMAL_OPERAND)
  {
    raisePT("FLT_DENORMAL_OPERAND", "");
  }
  if (dw == EXCEPTION_FLT_DIVIDE_BY_ZERO)
  {
    raisePT("FLT_DIVIDE_BY_ZERO", "");
  }
  if (dw == EXCEPTION_FLT_INEXACT_RESULT)
  {
    raisePT("FLT_INEXACT_RESULT", "");
  }
  if (dw == EXCEPTION_FLT_INVALID_OPERATION)
  {
    raisePT("FLT_INVALID_OPERATION", "");
  }
  if (dw == EXCEPTION_FLT_OVERFLOW)
  {
    raisePT("FLT_OVERFLOW", "");
  }
  if (dw == EXCEPTION_FLT_STACK_CHECK)
  {
    raisePT("FLT_STACK_CHECK", "");
  }
  if (dw == EXCEPTION_FLT_UNDERFLOW)
  {
    raisePT("FLT_UNDERFLOW", "");
  }
  if (dw == EXCEPTION_ILLEGAL_INSTRUCTION)
  {
    raisePT("ILLEGAL_INSTRUCTION", "");
  }
  if (dw == EXCEPTION_IN_PAGE_ERROR)
  {
    raisePT("IN_PAGE_ERROR", "");
  }
  if (dw == EXCEPTION_INT_OVERFLOW)
  {
    raisePT("INT_OVERFLOW", "");
  }
  if (dw == EXCEPTION_INVALID_DISPOSITION)
  {
    raisePT("INVALID_DISPOSITION", "");
  }
  if (dw == EXCEPTION_NONCONTINUABLE_EXCEPTION)
  {
    raisePT("NONCONTINUABLE_EXCEPTION", "");
  }
  if (dw == EXCEPTION_PRIV_INSTRUCTION)
  {
    raisePT("PRIV_INSTRUCTION", "");
  }
  if (dw == EXCEPTION_SINGLE_STEP)
  {
    raisePT("SINGLE_STEP", "");
  }
  if (dw == EXCEPTION_STACK_OVERFLOW)
  {
    raisePT("STACK_OVERFLOW", "");
  }
  return EXCEPTION_EXECUTE_HANDLER;
}

void PTManager_start()
{
  FLibHandle = ::LoadLibraryA("pt4.dll");
  if (FLibHandle == 0)
  {
    unloadlibPT();
    MBox("Could not load PT4.DLL. You should reinstall Programming Taskbook.");
    return;
  }
  if (LoadFunctions() == 1)
  {
    unloadlibPT();
    MBox("Wrong or corrupted version of PT4.DLL. You should reinstall Programming Taskbook.");
    return;
  }
  startPT_(8 + 16777216);
}

void PTManager_free()
{
  if (FLibHandle)
  {
    InfoS[0] = '\0';
    InfoT = 0;
    checkPT_(InfoS, &InfoT);
    if ((InfoT == 0) && (strcmp(InfoS, "")) != 0)
      MBox(InfoS);
    unloadlibPT();
  }
}

