#include "pt4taskmakerX.h"

DefineGroupName;

void __stdcall inittaskgroup()
{
  pt::NewGroup("Group description|Описание группы", "", "qwqfsdf13dfttd");
}

DefineTask(Task1)
{
  pt::NewTask(pt::Loc(
    R"(\STask name.\s Task formulation (line 1)
    Task formulation (line 2)
    \PNew paragraph of the task formulation (line 3))",

    R"(\SНазвание задания.\s Формулировка задания (строка 1)
    Формулировка задания (строка 2)
    \PНовый абзац формулировки задания (строка 3))"));
  
  int a = pt::Random(1, 9);

  pt::Data(pt::Loc("Sample input data: a = ",
    "Пример входных данных: a = "), a);

  pt::Res(pt::Loc("Sample result: 2 * a = ",
    "Пример результирующих данных: 2 * a = "), 2 * a);

  pt::SetTestCount(5);
}

