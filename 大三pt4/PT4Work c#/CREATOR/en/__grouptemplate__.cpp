#include "pt4taskmakerX.h"

DefineGroupName;

void __stdcall inittaskgroup()
{
  pt::NewGroup("Group description", "", "qwqfsdf13dfttd");
}

DefineTask(Task1)
{
  pt::NewTask(R"(\STask name.\s Task formulation (line 1)
  Task formulation (line 2)
  \PNew paragraph of the task formulation (line 3))"
  );
  int a = pt::Random(1, 9);
  pt::Data("Sample input data: a = ", a);
  pt::Res("Sample result: 2 * a = ", 2 * a);
  pt::SetTestCount(5);
}

