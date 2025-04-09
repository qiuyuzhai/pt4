//--------------------------------------------------//
//  Programming Taskbook C-module                   //
//  for Code::Blocks, Dev-C++ and VS Code           //
//                                                  //
//                 Copyright (C) M.E.Abramyan, 2023 //
//--------------------------------------------------//
//  WARNING! Altering the contents of this file     //
//  may cause Programming Taskbook to malfunction.  //
//--------------------------------------------------//

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Node;

struct Node
{
  int Data;
  struct Node *Next;
  struct Node *Prev;
  struct Node *Left;
  struct Node *Right;
  struct Node *Parent;
};

typedef struct Node TNode;
typedef struct Node *PNode;

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
char InfoS[255];

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
  char s[] = {'\'', c, '\'', '\0'};
  char *s2 = (char *)malloc(w <= 3 ? 4 : (w + 1));
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
  if (prec < 0)
    sprintf(InfoS, "%*.*e", w, abs(prec), d);
  else
    sprintf(InfoS, "%*.*f", w, prec, d);
  (*show_)(InfoS);
  width1 = -1;
}

void ShowS(const char *s)
{
  int w = width1 == -1 ? width : width1;
  int n = strlen(s) + 2;
  char *s3 = (char *)malloc(n + 1);
  if (s3 != 0)
  {
    sprintf(s3, "\"%s\"", s);
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

void ShowCmt(const char *cmt)
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

void ShowWCmt(const wchar_t *cmt)
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

void ShowLine(void)
{
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

void PTManager_start()
{
  FLibHandle = LoadLibraryA("pt4.dll");
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
  startPT_(67108864 + 16777216 + 4194304);
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
