#include "pt4taskmakerX.h"

DefineGroupName;

void __stdcall inittaskgroup()
{
  pt::NewGroup("Group description|Описание группы", "", "qwqfsdf13dfttd");
}

DefineTask(Task1)
{
  pt::NewTask(R"(\SНазвание задания.\s Формулировка задания (строка 1)
  Формулировка задания (строка 2)
  \PНовый абзац формулировки задания (строка 3))"
  );
  int a = pt::Random(1, 9);
  pt::Data("Пример входных данных: a = ", a);
  pt::Res("Пример результирующих данных: 2 * a = ", 2 * a);
  pt::SetTestCount(5);
}

