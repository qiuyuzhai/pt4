#include <cmath>
#include <random>
#include <ctime>
#include <cstring>
#include "pt4taskmakerX.h"

char GroupName[100];

string fmt;
int yd, yr, ye, nd, nr, pr, wd, dpos, rpos, vsize;
bool nt, ut, fd, fr, dep, rep, hide;

void (*tasks[1000])();
unsigned int taskGroupHash;

int TaskCount = 0;

const string alphabet_str = alphabet;

unsigned int HashString(const char *str, size_t length)
{
	unsigned int hash = 5381;
	for (size_t i = 0; i < length; ++i)
	{
		hash = ((hash << 5) + hash) + str[i];
	}
	return hash;
}

void pt4taskmakerX::RegisterTaskFunction(void (*task)(), const char *taskname)
{
	tasks[TaskCount] = task;
	taskGroupHash += HashString(taskname, strlen(taskname));
	++TaskCount;
}

// void Show(const string& s) {
//	MessageBoxA(nullptr, s.c_str(), "Error", MB_OK | MB_ICONERROR);
// }

string ErrorMessage(const string &s)
{
	return (s + string(100, ' ')).substr(0, 78);
}

void pt4taskmakerX::ErrorInfo(const string &s)
{
	pt4taskmaker::TaskText(("\\B" + ErrorMessage(s) + "\\b").c_str(), 0, ye);
	ye = ye + 1;
	if (ye > 5)
	{
		ye = 0;
	}
}

bool pt4taskmakerX::CheckTT()
{
	bool result = ut;
	if (!nt)
	{
		pt4taskmakerX::NewTask("");
		pt4taskmakerX::ErrorInfo(ErrMes5);
	}
	return result;
}

int pt4taskmakerX::wreal(int w, double x)
{
	int result = w;
	if (w == 0)
	{
		char buffer[100];
		if (fmt[0] == 'f')
		{
			int precision = std::stoi(fmt.substr(1));
			std::sprintf(buffer, "%.*f", precision, x);
		}
		else if (fmt[0] == 'e')
		{
			int exponent = std::stoi(fmt.substr(1));
			std::sprintf(buffer, "%.*e", exponent - 1, x);
		}
		result = strlen(buffer);
		// if (pr <= 0 && x >= 0) {
		//     result += 1;
		// }
	}
	return result;
}

int pt4taskmakerX::winteger(int w, int x)
{
	int result = w;
	if (w == 0)
	{
		string x_str = to_string(x);
		result = x_str.length();
	}
	return result;
}

bool pt4taskmakerX::checkPos(int pos)
{
	return ((pos > 0) && (pos < 79)) || (pos == pt4taskmakerX::PosLeft) || (pos == pt4taskmakerX::PosCenter) || (pos == pt4taskmakerX::PosRight);
}
bool pt4taskmakerX::nextPos(int oldPos, int newPos)
{
	return ((oldPos > 0) && (oldPos < 79) && (newPos > 0) && (newPos < 79) && (oldPos < newPos)) || ((oldPos >= pt4taskmakerX::PosLeft) && (newPos >= pt4taskmakerX::PosLeft) && (oldPos < newPos));
}

void pt4taskmakerX::NewTask(const char *topic, const char *tasktext, int *processcount)
{
	if (nt)
		return;
	if (processcount == NULL)
		pt4taskmaker::CreateTask(topic);
	else
		pt4taskmaker::CreateTask(topic, processcount);
	pt4taskmaker::TaskText(tasktext);
	nt = true;	 // вызвана процедура NewTask
	ut = false;	 // было подключено существующее задание (процедурой UseTask)
	ye = 1;		 // текущий номер строки для вывода сообщения об ошибке
	yd = 0;		 // текущий номер строки в разделе исходных данных
	yr = 0;		 // текущий номер строки в разделе результатов
	nd = 0;		 // количество элементов исходных данных
	nr = 0;		 // количество элементов результирующих данных
	fd = false;	 // наличие файловых данных в разделе исходных данных
	fr = false;	 // наличие файловых данных в разделе результатов
	pr = 2;		 // текущая точность вывода вещественных данных
	fmt = "f2";	 // текущий формат вывода вещественных данных
	wd = 0;		 // текущая ширина поля вывода для чисел
	dpos = 0;	 // текущая позиция исходных данных в режиме явного позиционирования
	rpos = 0;	 // текущая позиция результирующих данных в режиме явного позиционирования
	dep = false; // включен режим явного позиционирования исходных данных
	rep = false; // включен режим явного позиционирования результирующих данных
	vsize = 0;	 // число элементов вектора на одной строке
}

void pt4taskmakerX::NewTask(const char *topic, const char *tasktext)
{
	pt4taskmakerX::NewTask(topic, tasktext, NULL);
}

void pt4taskmakerX::NewTask(const char *tasktext)
{
	pt4taskmakerX::NewTask("", tasktext, NULL);
}

void pt4taskmakerX::DataComm(const char *comm)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int addpos = 0;
	if (!dep)
		dpos = 0;
	else if (dpos == PosCenter)
		addpos = -PosCenter;
	++yd;
	pt4taskmaker::DataComment(comm, dpos + addpos, yd);
	dep = false;
}

void pt4taskmakerX::Data(const char *s, bool a, int x, int y, int w)
{
	pt4taskmaker::DataB(s, a, x, y);
}

void pt4taskmakerX::Data(const char *s, int a, int x, int y, int w)
{
	pt4taskmaker::DataN(s, a, x, y, pt4taskmakerX::winteger(w, a));
}
void pt4taskmakerX::Data(const char *s, double a, int x, int y, int w)
{
	pt4taskmaker::DataR(s, a, x, y, pt4taskmakerX::wreal(w, a));
}
void pt4taskmakerX::Data(const char *s, char a, int x, int y, int w)
{
	pt4taskmaker::DataC(s, a, x, y);
}
void pt4taskmakerX::Data(const char *s, string a, int x, int y, int w)
{
	pt4taskmaker::DataS(s, a.c_str(), x, y);
}

void pt4taskmakerX::Data(const std::vector<bool> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!dep)
		dpos = 0;
	++yd;
	int w = 5;
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (dep && (dpos + i * (w + 2) > 81)))
		{
			++yd;
			i = 1;
		}
		if (!dep)
		{
			pt4taskmakerX::DataInternal("", e, pt4taskmaker::Center(i, n, w, 2), yd, w);
		}
		else
		{
			pt4taskmakerX::DataInternal("", e, (i - 1) * (w + 2), yd, w);
		}
	}
	dep = false;
	dpos = 0;
}
void pt4taskmakerX::Data(const vector<int> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!dep)
		dpos = 0;
	++yd;
	int w = wd;
	if (w == 0)
	{
		auto max_length = max_element(seq.begin(), seq.end(),
									  [](int a, int b)
									  { return to_string(a).length() < to_string(b).length(); });
		w = to_string(*max_length).length();
	}
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (dep && (dpos + i * (w + 2) > 81)))
		{
			++yd;
			i = 1;
		}
		if (!dep)
		{
			pt4taskmakerX::DataInternal("", e, pt4taskmaker::Center(i, n, w, 2), yd, w);
		}
		else
		{
			pt4taskmakerX::DataInternal("", e, (i - 1) * (w + 2), yd, w);
		}
	}
	dep = false;
	dpos = 0;
}
void pt4taskmakerX::Data(const std::vector<double> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!dep)
		dpos = 0;
	++yd;
	int w = wd;
	if (w == 0)
	{
		for (double e : seq)
		{
			int currentW = pt4taskmakerX::wreal(0, e);
			w = max(w, currentW);
		}
	}
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (dep && (dpos + i * (w + 2) > 81)))
		{
			++yd;
			i = 1;
		}
		if (!dep)
		{
			pt4taskmakerX::DataInternal("", e, pt4taskmaker::Center(i, n, w, 2), yd, w);
		}
		else
		{
			pt4taskmakerX::DataInternal("", e, (i - 1) * (w + 2), yd, w);
		}
	}
	dep = false;
	dpos = 0;
}
void pt4taskmakerX::Data(const std::vector<char> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!dep)
		dpos = 0;
	++yd;
	int w = 3;
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (dep && (dpos + i * (w + 2) > 81)))
		{
			++yd;
			i = 1;
		}
		if (!dep)
		{
			pt4taskmakerX::DataInternal("", e, pt4taskmaker::Center(i, n, w, 2), yd, w);
		}
		else
		{
			pt4taskmakerX::DataInternal("", e, (i - 1) * (w + 2), yd, w);
		}
	}
	dep = false;
	dpos = 0;
}
void pt4taskmakerX::Data(const std::vector<string> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!dep)
		dpos = 0;
	++yd;
	size_t max_length = 0;
	for (auto s : seq)
	{
		max_length = max(max_length, s.length());
	}
	int w = max_length + 2;
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (dep && (dpos + i * (w + 2) > 81)))
		{
			++yd;
			i = 1;
		}
		if (!dep)
		{
			pt4taskmakerX::DataInternal("", e, pt4taskmaker::Center(i, n, w, 2), yd, w);
		}
		else
		{
			pt4taskmakerX::DataInternal("", e, (i - 1) * (w + 2), yd, w);
		}
	}
	dep = false;
	dpos = 0;
}

void pt4taskmakerX::ResComm(const char *comm)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int addpos = 0;
	if (!rep)
		rpos = 0;
	else if (rpos == PosCenter)
		addpos = -PosCenter;
	++yr;
	pt4taskmaker::ResultComment(comm, rpos + addpos, yr);
	rep = false;
}
void pt4taskmakerX::Res(const char *s, bool a, int x, int y, int w)
{
	pt4taskmaker::ResultB(s, a, x, y);
}

void pt4taskmakerX::Res(const char *s, int a, int x, int y, int w)
{
	pt4taskmaker::ResultN(s, a, x, y, pt4taskmakerX::winteger(w, a));
}
void pt4taskmakerX::Res(const char *s, double a, int x, int y, int w)
{
	pt4taskmaker::ResultR(s, a, x, y, pt4taskmakerX::wreal(w, a));
}
void pt4taskmakerX::Res(const char *s, char a, int x, int y, int w)
{
	pt4taskmaker::ResultC(s, a, x, y);
}
void pt4taskmakerX::Res(const char *s, string a, int x, int y, int w)
{
	pt4taskmaker::ResultS(s, a.c_str(), x, y);
}

void pt4taskmakerX::Res(const std::vector<bool> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!rep)
		rpos = 0;
	++yr;
	int w = 5;
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (rep && (rpos + i * (w + 2) > 81)))
		{
			++yr;
			i = 1;
		}
		if (!rep)
		{
			pt4taskmakerX::ResInternal("", e, pt4taskmaker::Center(i, n, w, 2), yr, w);
		}
		else
		{
			pt4taskmakerX::ResInternal("", e, (i - 1) * (w + 2), yr, w);
		}
	}
	rep = false;
	rpos = 0;
}
void pt4taskmakerX::Res(const vector<int> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	++yr;
	if (!rep)
		rpos = 0;
	int w = wd;
	if (w == 0)
	{
		auto max_length = max_element(seq.begin(), seq.end(),
									  [](int a, int b)
									  { return to_string(a).length() < to_string(b).length(); });
		w = to_string(*max_length).length();
	}
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (rep && (rpos + i * (w + 2) > 81)))
		{
			++yr;
			i = 1;
		}
		if (!rep)
		{
			pt4taskmakerX::ResInternal("", e, pt4taskmaker::Center(i, n, w, 2), yr, w);
		}
		else
		{
			pt4taskmakerX::ResInternal("", e, (i - 1) * (w + 2), yr, w);
		}
	}
	rep = false;
	rpos = 0;
}
void pt4taskmakerX::Res(const std::vector<double> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!rep)
		rpos = 0;
	++yr;
	int w = wd;
	if (w == 0)
	{
		for (double e : seq)
		{
			int currentW = pt4taskmakerX::wreal(0, e);
			w = max(w, currentW);
		}
	}
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (rep && (rpos + i * (w + 2) > 81)))
		{
			++yr;
			i = 1;
		}
		if (!rep)
		{
			pt4taskmakerX::ResInternal("", e, pt4taskmaker::Center(i, n, w, 2), yr, w);
		}
		else
		{
			pt4taskmakerX::ResInternal("", e, (i - 1) * (w + 2), yr, w);
		}
	}
	rep = false;
	rpos = 0;
}
void pt4taskmakerX::Res(const std::vector<char> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!rep)
		rpos = 0;
	++yr;
	int w = 3;
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (rep && (rpos + i * (w + 2) > 81)))
		{
			++yr;
			i = 1;
		}
		if (!rep)
		{
			pt4taskmakerX::ResInternal("", e, pt4taskmaker::Center(i, n, w, 2), yr, w);
		}
		else
		{
			pt4taskmakerX::ResInternal("", e, (i - 1) * (w + 2), yr, w);
		}
	}
	rep = false;
	rpos = 0;
}
void pt4taskmakerX::Res(const std::vector<string> &seq)
{
	if (pt4taskmakerX::CheckTT())
		return;
	int n = seq.size();
	if (n == 0)
		return;
	if (!rep)
		rpos = 0;
	++yr;
	size_t max_length = 0;
	for (auto s : seq)
	{
		max_length = max(max_length, s.length());
	}
	int w = max_length + 2;
	int wmax = 80 / (w + 2);
	if (vsize > 0 && vsize < wmax)
		wmax = vsize;
	if (n > wmax)
		n = wmax;

	int i = 0;
	for (auto e : seq)
	{
		++i;
		if (i > wmax || (rep && (rpos + i * (w + 2) > 81)))
		{
			++yr;
			i = 1;
		}
		if (!rep)
		{
			pt4taskmakerX::ResInternal("", e, pt4taskmaker::Center(i, n, w, 2), yr, w);
		}
		else
		{
			pt4taskmakerX::ResInternal("", e, (i - 1) * (w + 2), yr, w);
		}
	}
	rep = false;
	rpos = 0;
}

void pt4taskmakerX::SetWidth(int n)
{
	if ((n >= 0) && (n <= 20))
	{
		wd = n;
	}
}
void pt4taskmakerX::SetPrecision(int n)
{
	if (pt4taskmakerX::CheckTT())
		return;
	if (abs(n) > 10)
		return;
	pr = n;
	if (n < 0)
	{
		fmt = "e" + to_string(-n);
		n = 0;
	}
	else if (n == 0)
	{
		fmt = "e6";
	}
	else
	{
		fmt = 'f' + to_string(n);
	}
	pt4taskmaker::SetPrecision(n);
}
void pt4taskmakerX::SetTestCount(int n)
{
	if (pt4taskmakerX::CheckTT())
		return;
	pt4taskmaker::SetTestCount(n);
}
void pt4taskmakerX::SetRequiredDataCount(int n)
{
	if (pt4taskmakerX::CheckTT())
		return;
	pt4taskmaker::SetRequiredDataCount(n);
}

int pt4taskmakerX::CurrentTest()
{
	if (pt4taskmakerX::CheckTT())
		return 0;
	return pt4taskmaker::CurrentTest();
}

void pt4taskmakerX::ShowInfo(const string &info)
{
	pt4taskmaker::ShowInfo(info.c_str());
}

int pt4taskmakerX::Random(int M, int N)
{
	return pt4taskmaker::RandomN(M, N);
}
double pt4taskmakerX::Random()
{
	return (double)rand() / (double)RAND_MAX;
}
double pt4taskmakerX::Random(double A, double B)
{
	return pt4taskmaker::RandomR(A, B);
}
double pt4taskmakerX::Random1(double A, double B)
{
	return Random(round(A * 10), round(B * 10)) / 10 + Random() * 1.0e-7;
}
double pt4taskmakerX::Random2(double A, double B)
{
	return Random(round(A * 100), round(B * 100)) / 100 + Random() * 1.0e-7;
}

string pt4taskmakerX::RandomName(int len)
{
	string result;
	int n = alphabet_str.length();

	for (int i = 0; i < len; ++i)
	{
		result.push_back(alphabet_str[pt4taskmakerX::Random(0, n - 1)]);
	}

	return result;
}

void pt4taskmakerX::GetGroupName(const char *FilePath)
{

	// удаление пути и расширения
	string str(FilePath);
	size_t lastSlash = str.find_last_of("/\\");
	size_t lastDot = str.find_last_of('.');
	string result;

	if (lastDot != std::string::npos && (lastSlash == std::string::npos || lastDot > lastSlash))
	{
		result = str.substr(lastSlash + 1, lastDot - lastSlash - 1);
	}
	else
	{
		result = str.substr(lastSlash + 1);
	}

	// приведение префикса к верхнему регистру
	string prefix = result.substr(0, 3);
	for (size_t i = 0; i < prefix.size(); ++i)
	{
		if (prefix[i] >= 'a' && prefix[i] <= 'z')
		{
			prefix[i] -= ('a' - 'A');
		}
	}
	if (prefix == "PT4")
	{
		// удаление префикса PT4
		result.erase(0, 3);
	}

	// удаление суффикса, определяющего язык интерфейса
	size_t underscorePos = result.find('_');
	if (underscorePos != std::string::npos)
	{
		result.erase(underscorePos);
	}
	strcpy(GroupName, result.c_str());
}

void __stdcall RunTask(int num)
{
	bool ut0;
	try
	{
		if ((num > 0) && (num <= TaskCount))
		{
			tasks[num - 1]();
		}
	}
	catch (const std::exception &e)
	{
		pt4taskmakerX::ShowInfo(e.what());
	}
	nt = false;
	ut0 = ut;
	ut = false;

	if (ut0)
		return;
	if (nd == 0 && !fd)
	{
		pt4taskmakerX::ShowInfo(ErrMes6);
	}
	if (nr == 0 && !fr)
	{
		pt4taskmakerX::ShowInfo(ErrMes7);
	}
}

string GenerateGroupKey()
{
	taskGroupHash += HashString(GroupName, strlen(GroupName));
	string res = "GK";
	res += to_string(taskGroupHash);
	return res;
}

bool IsEnglish(string &s)
{
	for (auto c : s)
		if (c > 127 || c < 32)
			return false;
	return true;
}

void Trim(string &s)
{
	while (s[0] == ' ')
		s.erase(0, 1);
	while (s[s.size() - 1] == ' ')
		s.erase(s.size() - 1, 1);
}

void pt4taskmakerX::NewGroup(const char *GroupDescription, const char *GroupAuthor, const char *GroupKey, int Options)
{
	if (TaskCount == 0)
	{
		pt4taskmakerX::ShowInfo("Группа " + string(GroupName) + " не содержит заданий.");
		return;
	}
	if (TaskCount > 999)
	{
		pt4taskmakerX::ShowInfo("Группа " + string(GroupName) + " содержит более 999 заданий.");
		return;
	}
	string EnGD(GroupDescription);
	string RuGD(EnGD);
	size_t p = EnGD.find('|');
	if (p != string::npos)
	{
		EnGD.erase(p);
		Trim(EnGD);
		if (EnGD == "")
		{
			pt4taskmakerX::ShowInfo("Английское описание группы " + string(GroupName) + " является пустым.\r\nИспользуйте следующий формат для параметра GroupDescription: \"Английское описание|Русское описание\". Фрагмент с русским описанием можно не указывать.");
			return;
		}
		RuGD = RuGD.substr(p + 1);
	}
	p = RuGD.find('|');
	while (p != string::npos)
	{
		RuGD.erase(p, 1);
		p = RuGD.find('|');
	}
	Trim(RuGD);
	if (RuGD == "")
		RuGD = EnGD;
	if (!IsEnglish(EnGD))
	{
		pt4taskmakerX::ShowInfo("Английское описание группы " + string(GroupName) + " содержит недопустимые символы: \"" + EnGD +
								"\".\r\nИспользуйте следующий формат для параметра GroupDescription: \"Английское описание|Русское описание\". Фрагмент с русским описанием можно не указывать.");
		;
		return;
	}
	string GK = GroupKey;
	if ((Options & OptionUseAddition) == OptionUseAddition)
		GK += "#UseAddition#";
	if ((Options & OptionHideExamples) == OptionHideExamples)
		GK += "#HideExamples#";
	GK += "#EnTopic<" + EnGD + ">#";
	const char *GD = pt4taskmakerX::CurrentLocale() == "en" ? EnGD.c_str() : RuGD.c_str();
	pt4taskmaker::CreateGroup(GroupName, GD, GroupAuthor, GK.c_str(), TaskCount, RunTask);
}

void pt4taskmakerX::UseTask(const char *GroupName, int TaskNumber)
{
	if (ut)
		return;
	pt4taskmaker::UseTask(GroupName, TaskNumber);
	ut = true;
}
void pt4taskmakerX::UseTask(const char *GroupName, int TaskNumber, const char *TopicDescription)
{
	if (ut)
		return;
	pt4taskmaker::UseTask(GroupName, TaskNumber, TopicDescription);
	ut = true;
}

int pt4taskmakerX::CurrentLanguage()
{
	return pt4taskmaker::CurrentLanguage();
}

string pt4taskmakerX::CurrentLocale()
{
	return pt4taskmaker::CurrentLocale();
}

string pt4taskmakerX::CurrentVersion()
{ // добавлено в версии 4.10
	return pt4taskmaker::CurrentVersion();
}


string RemoveLF(const string &s)
{
	string res(s);
	for (int i = res.size() - 1; i >= 0; i--)
		if (res[i] == '\r')
			res.erase(i, 1);
	return res;
}

vector<string> pt4taskmakerX::GetWords()
{
	vector<string> result;
	int n = pt4taskmaker::WordCount();
	for (int i = 0; i < n; ++i)
	{
		result.push_back(pt4taskmaker::WordSample(i));
	}
	return result;
}
string pt4taskmakerX::RandomWord()
{
	return pt4taskmaker::WordSample(pt4taskmaker::RandomN(0, pt4taskmaker::WordCount() - 1));
}
vector<string> pt4taskmakerX::GetEnWords()
{
	vector<string> result;
	int n = pt4taskmaker::EnWordCount();
	for (int i = 0; i < n; ++i)
	{
		result.push_back(pt4taskmaker::EnWordSample(i));
	}
	return result;
}
string pt4taskmakerX::RandomEnWord()
{
	return pt4taskmaker::EnWordSample(pt4taskmaker::RandomN(0, pt4taskmaker::EnWordCount() - 1));
}
vector<string> pt4taskmakerX::GetSentences()
{
	vector<string> result;
	int n = pt4taskmaker::SentenceCount();
	for (int i = 0; i < n; ++i)
	{
		result.push_back(pt4taskmaker::SentenceSample(i));
	}
	return result;
}
string pt4taskmakerX::RandomSentence()
{
	return pt4taskmaker::SentenceSample(pt4taskmaker::RandomN(0, pt4taskmaker::SentenceCount() - 1));
}
vector<string> pt4taskmakerX::GetEnSentences()
{
	vector<string> result;
	int n = pt4taskmaker::EnSentenceCount();
	for (int i = 0; i < n; ++i)
	{
		result.push_back(pt4taskmaker::EnSentenceSample(i));
	}
	return result;
}
string pt4taskmakerX::RandomEnSentence()
{
	return pt4taskmaker::EnSentenceSample(pt4taskmaker::RandomN(0, pt4taskmaker::EnSentenceCount() - 1));
}
vector<string> pt4taskmakerX::GetTexts()
{
	vector<string> result;
	int n = pt4taskmaker::TextCount();
	for (int i = 0; i < n; ++i)
	{
		result.push_back(RemoveLF(pt4taskmaker::TextSample(i)));
	}
	return result;
}
string pt4taskmakerX::RandomText()
{
	return RemoveLF(pt4taskmaker::TextSample(pt4taskmaker::RandomN(0, pt4taskmaker::TextCount() - 1)));
}
vector<string> pt4taskmakerX::GetEnTexts()
{
	vector<string> result;
	int n = pt4taskmaker::EnTextCount();
	for (int i = 0; i < n; ++i)
	{
		result.push_back(RemoveLF(pt4taskmaker::EnTextSample(i)));
	}
	return result;
}
string pt4taskmakerX::RandomEnText()
{
	return RemoveLF(pt4taskmaker::EnTextSample(pt4taskmaker::RandomN(0, pt4taskmaker::EnTextCount() - 1)));
}

void pt4taskmakerX::DataFileInt(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yd;
	dep = false;
	dpos = 0;
	if (yd > 5)
	{
		DataComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	int w = wd;
	if (w == 0)
	{
		try
		{
			FILE *file = std::fopen(FileName.c_str(), "rb");
			if (file != nullptr)
			{
				int a;
				while (std::fread(&a, sizeof(int), 1, file) == 1)
				{
					char buffer[100];
					std::sprintf(buffer, "%d", a);
					size_t len = std::strlen(buffer);
					if ((int)len > w)
					{
						w = len;
					}
				}
				std::fclose(file);
			}
		}
		catch (const std::exception &ex)
		{
			string fname(FileName);
			DataComm(("\\B" + ErrorMessage("FileError(" + fname + "): ") + ex.what()).c_str());
			return;
		}
	}
	fd = true;
	pt4taskmaker::DataFileN(FileName.c_str(), yd, w + 2);
}
void pt4taskmakerX::DataFileDouble(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yd;
	dep = false;
	dpos = 0;
	if (yd > 5)
	{
		DataComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	int w = wd;
	if (w == 0)
	{
		try
		{
			FILE *file = std::fopen(FileName.c_str(), "rb");
			if (file != nullptr)
			{
				double a;
				while (std::fread(&a, sizeof(double), 1, file) == 1)
				{
					int s = pt4taskmakerX::wreal(0, a);
					if (s > w)
					{
						w = s;
					}
				}
				std::fclose(file);
			}
		}
		catch (const std::exception &ex)
		{
			string fname(FileName);
			DataComm(("\\B" + ErrorMessage("FileError(" + fname + "): ") + ex.what()).c_str());
			return;
		}
	}
	fd = true;
	pt4taskmaker::DataFileR(FileName.c_str(), yd, w + 2);
}
void pt4taskmakerX::DataFileChar(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yd;
	dep = false;
	dpos = 0;
	if (yd > 5)
	{
		DataComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	fd = true;
	pt4taskmaker::DataFileC(FileName.c_str(), yd, 5);
}
void pt4taskmakerX::DataFileShortString(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yd;
	dep = false;
	dpos = 0;
	if (yd > 5)
	{
		DataComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	size_t w = 0;
	try
	{
		FILE *file = std::fopen(FileName.c_str(), "rb");
		if (file != nullptr)
		{
			ShortString a;
			while (std::fread(&a, sizeof(ShortString), 1, file) == 1)
			{
				size_t len = (int)a[0];
				if (len > w)
					w = len;
			}
			std::fclose(file);
		}
	}
	catch (const std::exception &ex)
	{
		string fname(FileName);
		DataComm(("\\B" + ErrorMessage("FileError(" + fname + "): ") + ex.what()).c_str());
		return;
	}
	fd = true;
	pt4taskmaker::DataFileS(FileName.c_str(), yd, w + 4);
}
void pt4taskmakerX::DataFileText(string FileName, int LineCount)
{
	if (pt4taskmakerX::CheckTT())
		return;
	dep = false;
	dpos = 0;
	if (LineCount > 0)
	{
		++yd;
		if (yd > 5)
		{
			DataComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
			return;
		}
		fd = true;
		int yd2 = yd + LineCount - 1;
		if (yd2 > 5)
		{
			yd2 = 5;
		}
		pt4taskmaker::DataFileT(FileName.c_str(), yd, yd2);
		yd = yd2;
	}
	else
	{
		pt4taskmaker::DataFileT(FileName.c_str(), 0, 0);
	}
}
void pt4taskmakerX::ResFileInt(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yr;
	rep = false;
	rpos = 0;
	if (yr > 5)
	{
		ResComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	int w = wd;
	if (w == 0)
	{
		try
		{
			FILE *file = std::fopen(FileName.c_str(), "rb");
			if (file != nullptr)
			{
				int a;
				while (std::fread(&a, sizeof(int), 1, file) == 1)
				{
					std::string s = std::to_string(a);
					size_t len = s.length();
					if ((int)len > w)
						w = len;
				}
				std::fclose(file);
			}
		}
		catch (const std::exception &ex)
		{
			string fname(FileName);
			ResComm(("\\B" + ErrorMessage("FileError(" + fname + "): ") + ex.what()).c_str());
			return;
		}
	}
	fr = true;
	pt4taskmaker::ResultFileN(FileName.c_str(), yr, w + 2);
}
void pt4taskmakerX::ResFileDouble(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	ResComm(fmt.c_str());
	++yr;
	rep = false;
	rpos = 0;
	if (yr > 5)
	{
		ResComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	int w = wd;
	if (w == 0)
	{
		try
		{
			FILE *file = std::fopen(FileName.c_str(), "rb");
			if (file != nullptr)
			{
				double a;
				while (std::fread(&a, sizeof(double), 1, file) == 1)
				{
					int s = pt4taskmakerX::wreal(0, a);
					if (s > w)
					{
						w = s;
					}
				}
				std::fclose(file);
			}
		}
		catch (const std::exception &ex)
		{
			string fname(FileName);
			ResComm(("\\B" + ErrorMessage("FileError(" + fname + "): ") + ex.what()).c_str());
			return;
		}
	}
	fr = true;
	pt4taskmaker::ResultFileR(FileName.c_str(), yr, w + 2);
}
void pt4taskmakerX::ResFileChar(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yr;
	rep = false;
	rpos = 0;
	if (yr > 5)
	{
		ResComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	fr = true;
	pt4taskmaker::ResultFileC(FileName.c_str(), yr, 5);
}
void pt4taskmakerX::ResFileShortString(string FileName)
{
	if (pt4taskmakerX::CheckTT())
		return;
	++yr;
	rep = false;
	rpos = 0;
	if (yr > 5)
	{
		ResComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
		return;
	}
	size_t w = 0;
	try
	{
		FILE *file = std::fopen(FileName.c_str(), "rb");
		if (file != nullptr)
		{
			ShortString a;
			while (std::fread(&a, sizeof(ShortString), 1, file) == 1)
			{
				size_t len = (int)a[0];
				if (len > w)
					w = len;
			}
			std::fclose(file);
		}
	}
	catch (const std::exception &ex)
	{
		string fname(FileName);
		ResComm(("\\B" + ErrorMessage("FileError(" + fname + "): ") + ex.what()).c_str());
		return;
	}
	fr = true;
	pt4taskmaker::ResultFileS(FileName.c_str(), yr, w + 4);
}
void pt4taskmakerX::ResFileText(string FileName, int LineCount)
{
	if (pt4taskmakerX::CheckTT())
		return;
	rep = false;
	rpos = 0;
	if (LineCount > 0)
	{
		++yr;
		if (yr > 5)
		{
			ResComm(("\\B" + ErrorMessage(ErrMes1) + "\b").c_str());
			return;
		}
		fr = true;
		int yr2 = yr + LineCount - 1;
		if (yr2 > 5)
		{
			yr2 = 5;
		}
		pt4taskmaker::ResultFileT(FileName.c_str(), yr, yr2);
		yr = yr2;
	}
	else
	{
		pt4taskmaker::ResultFileT(FileName.c_str(), 0, 0);
	}
}

void pt4taskmakerX::ConvertToShortString(string s, ShortString buf)
{
	buf[0] = (char)s.length();
	for (size_t i = 1; i <= s.length(); i++)
		buf[i] = s[i - 1];
}

int pt4taskmakerX::Width3(int w, int a1, int a2, int a3)
{
	int res = w;
	if (res > 0)
		return res + 2;
	int a[]{a1, a2, a3};
	for (int i = 0; i < 3; i++)
	{
		int w0 = pt4taskmakerX::winteger(w, a[i]);
		if (res < w0)
			res = w0;
	}
	return res + 2;
}

int pt4taskmakerX::Width3(int w, double a1, double a2, double a3)
{
	int res = w;
	if (res > 0)
		return res + 2;
	double a[]{a1, a2, a3};
	for (int i = 0; i < 3; i++)
	{
		int w0 = pt4taskmakerX::wreal(w, a[i]);
		if (res < w0)
			res = w0;
	}
	return res + 2;
}

void pt4taskmakerX::DataInternal2(const char *s, int a1, int a2, int x, int y, int w)
{
	if ((y > 5) && fd)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nd;
	if (nd > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes3);
		return;
	}
	pt4taskmaker::DataN2(s, a1, a2, x + dpos, y, pt4taskmakerX::Width3(w, a1, a2, 0));
}

void pt4taskmakerX::DataInternal3(const char *s, int a1, int a2, int a3, int x, int y, int w)
{
	if ((y > 5) && fd)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nd;
	if (nd > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes3);
		return;
	}
	pt4taskmaker::DataN3(s, a1, a2, a3, x + dpos, y, pt4taskmakerX::Width3(w, a1, a2, a3));
}

void pt4taskmakerX::DataInternal2(const char *s, double a1, double a2, int x, int y, int w)
{
	if ((y > 5) && fd)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nd;
	if (nd > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes3);
		return;
	}
	pt4taskmaker::DataR2(s, a1, a2, x + dpos, y, pt4taskmakerX::Width3(w, a1, a2, 0.0));
}

void pt4taskmakerX::DataInternal3(const char *s, double a1, double a2, double a3, int x, int y, int w)
{
	if ((y > 5) && fd)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nd;
	if (nd > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes3);
		return;
	}
	pt4taskmaker::DataR3(s, a1, a2, a3, x + dpos, y, pt4taskmakerX::Width3(w, a1, a2, a3));
}

void pt4taskmakerX::ResInternal2(const char *s, int a1, int a2, int x, int y, int w)
{
	if ((y > 5) && fr)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes4);
		return;
	}
	pt4taskmaker::ResultN2(s, a1, a2, x + rpos, y, pt4taskmakerX::Width3(w, a1, a2, 0));
}

void pt4taskmakerX::ResInternal3(const char *s, int a1, int a2, int a3, int x, int y, int w)
{
	if ((y > 5) && fr)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes4);
		return;
	}
	pt4taskmaker::ResultN3(s, a1, a2, a3, x + rpos, y, pt4taskmakerX::Width3(w, a1, a2, a3));
}

void pt4taskmakerX::ResInternal2(const char *s, double a1, double a2, int x, int y, int w)
{
	if ((y > 5) && fr)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes4);
		return;
	}

	pt4taskmaker::ResultR2(s, a1, a2, x + rpos, y, pt4taskmakerX::Width3(w, a1, a2, 0.0));
}

void pt4taskmakerX::ResInternal3(const char *s, double a1, double a2, double a3, int x, int y, int w)
{
	if ((y > 5) && fr)
	{
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > datmax)
	{
		pt4taskmakerX::ErrorInfo(ErrMes4);
		return;
	}
	pt4taskmaker::ResultR3(s, a1, a2, a3, x + rpos, y, pt4taskmakerX::Width3(w, a1, a2, a3));
}

void pt4taskmakerX::SetFileRowSize(int n)
{
	pt4taskmaker::SetFileRow(n);
}

void pt4taskmakerX::SetSeqRowSize(int n)
{
	if (n >= 0)
		vsize = n;
}
