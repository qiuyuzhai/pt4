#include "pt4taskmakerX.h"

DefineGroupName;

void __stdcall inittaskgroup()
{
  pt::NewGroup("Group description|�������� ������", "", "qwqfsdf13dfttd");
}

DefineTask(Task1)
{
  pt::NewTask(R"(\S�������� �������.\s ������������ ������� (������ 1)
  ������������ ������� (������ 2)
  \P����� ����� ������������ ������� (������ 3))"
  );
  int a = pt::Random(1, 9);
  pt::Data("������ ������� ������: a = ", a);
  pt::Res("������ �������������� ������: 2 * a = ", 2 * a);
  pt::SetTestCount(5);
}

