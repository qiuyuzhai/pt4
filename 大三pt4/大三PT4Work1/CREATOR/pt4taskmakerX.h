#ifndef _PT4TASKMAKERX
#define _PT4TASKMAKERX

#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include "pt4taskmaker.h"

using ShortString = char[256];

/// Macro to add a task to the list of all group tasks.
///
/// Макрос для добавления задания в список всех заданий группы.
#define DefineTask(name) \
    void name(); \
    struct name ## _Registrar { \
        name ## _Registrar() { pt4taskmakerX::RegisterTaskFunction(name, #name); } \
    } name ## _registrar_instance; \
    void name()

/// Macro to obtain the name of the task group.
///
/// Макрос для получения названия группы заданий.
#define DefineGroupName \
    struct _GroupName { \
        _GroupName() { pt4taskmakerX::GetGroupName(__FILE__); } \
    } _groupname_instance;

#define alphabet "0123456789abcdefghijklmnoprstuvwxyz"
#define datmax 800
#define ErrMes1 "Error: Раздел размером более 5 строк не может содержать файловые данные."
#define ErrMes2 "Error: При наличии файловых данных раздел не может содержать более 5 строк."
#define ErrMes3 "Error: Количество исходных данных превысило 800."
#define ErrMes4 "Error: Количество результирующих данных превысило 800."
#define ErrMes5 "Error: При определении задания первой должна вызываться процедура NewTask."
#define ErrMes6 "Error: При определении задания не указаны исходные данные."
#define ErrMes7 "Error: При определении задания не указаны результирующие данные."

//Функции и переменные для внутреннего использования

extern int yd, yr, ye, nd, nr, pr, wd, dpos, rpos;
extern bool nt, ut, fd, fr, dep, rep, hide;

namespace pt4taskmakerX
{
bool CheckTT();
template<typename T>
void DataInternal(const char* s, T a, int x, int y, int w);
void DataInternal2(const char* s, int a1, int a2, int x, int y, int w);
void DataInternal2(const char* s, double a1, double a2, int x, int y, int w);
void DataInternal3(const char* s, int a1, int a2, int a3, int x, int y, int w);
void DataInternal3(const char* s, double a1, double a2, double a3, int x, int y, int w);
template<typename T>
void ResInternal(const char* s, T a, int x, int y, int w);
void ResInternal2(const char* s, int a1, int a2, int x, int y, int w);
void ResInternal2(const char* s, double a1, double a2, int x, int y, int w);
void ResInternal3(const char* s, int a1, int a2, int a3, int x, int y, int w);
void ResInternal3(const char* s, double a1, double a2, double a3, int x, int y, int w);
void ShowInfo(const string &info);

void ErrorInfo(const string& s);
int winteger(int w, int x);
int wreal(int w, double x);
bool checkPos(int pos);
bool nextPos(int oldPos, int newPos);
int Width3(int w, int a1, int a2, int a3);
int Width3(int w, double a1, double a2, double a3);

// *********************************************************M

	const int OptionUseAddition = 8;        // группа доступна только при наличии файла дополнений
	const int OptionHideExamples = 16;      // не отображать раздел с примером верного решения

	const int PosLeft = 100;
	const int PosCenter = 150;
	const int PosRight = 200;
	const int PosHide = 255;

	void RegisterTaskFunction(void (*task)(), const char* taskname);
	void GetGroupName(const char* FilePath);

	void NewTask(const char* topic, const char* tasktext, int* processcount);
	void NewTask(const char* topic, const char* tasktext);
	void NewTask(const char* tasktext);

	void Data(const char* s, bool a, int x, int y, int w);
	void Data(const char* s, int a, int x, int y, int w);
	void Data(const char* s, double a, int x, int y, int w);
	void Data(const char* s, char a, int x, int y, int w);
	void Data(const char* s, string a, int x, int y, int w);

	void DataComm(const char* comm);
	inline void Data(const char* comm) {
		DataComm(comm);
	}

	template<typename T>
	void Data(const char* comm, T a) {
		if (pt4taskmakerX::CheckTT()) return;
		if (hide) {
			pt4taskmakerX::DataInternal(comm, a, 1 - dpos, 0, wd);  // add hide data (Y == 0)
		}
		else {
		        int addpos = 0;
			if (!dep) dpos = 0;
			else if (dpos == PosCenter)
			  addpos = -PosCenter;
			++yd;
			pt4taskmakerX::DataInternal(comm, a, addpos, yd, wd);
		}
		dep = false;
		hide = false;
	}

	template<typename T>
	void Data2(const char* comm, T a1, T a2) {
		if (pt4taskmakerX::CheckTT()) return;
		if (hide) {
			pt4taskmakerX::DataInternal2(comm, a1, a2, 1 - dpos, 0, wd);  // add hide data (Y == 0)
		}
		else {
		        int addpos = 0;
			if (!dep) dpos = 0;
			else if (dpos == PosCenter)
			  addpos = -PosCenter;
			++yd;
			pt4taskmakerX::DataInternal2(comm, a1, a2, addpos, yd, wd);
		}
		dep = false;
		hide = false;
	}

	template<typename T>
	void Data3(const char* comm, T a1, T a2, T a3) {
		if (pt4taskmakerX::CheckTT()) return;
		if (hide) {
			pt4taskmakerX::DataInternal3(comm, a1, a2, a3, 1 - dpos, 0, wd);  // add hide data (Y == 0)
		}
		else {
		        int addpos = 0;
			if (!dep) dpos = 0;
			else if (dpos == PosCenter)
			  addpos = -PosCenter;
			++yd;
			pt4taskmakerX::DataInternal3(comm, a1, a2, a3, addpos, yd, wd);
		}
		dep = false;
		hide = false;
	}

	template<typename T>
	void Data(const char* comm1, T a1, const char* comm2) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!dep) dpos = 0;
		++yd;
		pt4taskmakerX::DataInternal(comm1, a1, xLeft, yd, wd);
		pt4taskmaker::DataComment(comm2, xRight, yd);
		dep = false;
	}

	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!dep) dpos = 0;
		++yd;
		pt4taskmakerX::DataInternal(comm1, a1, xLeft, yd, wd);
		pt4taskmakerX::DataInternal(comm2, a2, xRight, yd, wd);
		dep = false;
	}

	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!dep) dpos = 0;
		++yd;
		pt4taskmakerX::DataInternal(comm1, a1, xLeft, yd, wd);
		pt4taskmakerX::DataInternal(comm2, a2, 0, yd, wd);
		pt4taskmaker::DataComment(comm3, xRight, yd);
		dep = false;
	}

	template<typename T1, typename T2, typename T3>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!dep) dpos = 0;
		++yd;
		pt4taskmakerX::DataInternal(comm1, a1, xLeft, yd, wd);
		pt4taskmakerX::DataInternal(comm2, a2, 0, yd, wd);
		pt4taskmakerX::DataInternal(comm3, a3, xRight, yd, wd);
		dep = false;
	}

	void Data(const std::vector<bool>& seq);
	void Data(const std::vector<int>& seq);
	void Data(const std::vector<double>& seq);
	void Data(const std::vector<char>& seq);
	void Data(const std::vector<string>& seq);

	inline void DataPos(const char* comm, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(dpos, pos) && (yd > 0) && (dpos != 0)) {
				--yd; // остаемся на текущей строке
			}
			dpos = pos;
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция исходных данных должна быть больше 0 и меньше 79");
			return;
		}
		dep = true;
		Data(comm);
	}

	template<typename T>
	void DataPos(const char* comm, T a, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(dpos, pos) && (yd > 0) && (dpos != 0)) {
				--yd; // остаемся на текущей строке
			}
			dpos = pos;
		}
		else if (pos == PosHide) {
			hide = true;  
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция исходных данных должна быть больше 0 и меньше 79");
			return;
		}
		dep = true;
		Data(comm, a);
	}

	template<typename T>
	void DataPos(const char* comm, T a1, T a2, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(dpos, pos) && (yd > 0) && (dpos != 0)) {
				--yd; // остаемся на текущей строке
			}
			dpos = pos;
		}
		else if (pos == PosHide) {
			hide = true;  
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция исходных данных должна быть больше 0 и меньше 79");
			return;
		}
		dep = true;
		Data2(comm, a1, a2);
	}

	template<typename T>
	void DataPos(const char* comm, T a1, T a2, T a3, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(dpos, pos) && (yd > 0) && (dpos != 0)) {
				--yd; // остаемся на текущей строке
			}
			dpos = pos;
		}
		else if (pos == PosHide) {
			hide = true;  
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция исходных данных должна быть больше 0 и меньше 79");
			return;
		}
		dep = true;
		Data3(comm, a1, a2, a3);
	}


	template<typename Container>
	void DataPos(const Container& seq, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		int n = seq.size();
		if (n == 0) return;

		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(dpos, pos) && (yd > 0) && (dpos != 0)) {
				--yd; // остаемся на текущей строке
			}
			dpos = pos;
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция исходных данных должна быть больше 0 и меньше 79");
			return;
		}
		dep = true;
		Data((vector<typename Container::value_type>)seq);
	}

	void Res(const char* s, bool a, int x, int y, int w);
	void Res(const char* s, int a, int x, int y, int w);
	void Res(const char* s, double a, int x, int y, int w);
	void Res(const char* s, char a, int x, int y, int w);
	void Res(const char* s, string a, int x, int y, int w);

	void ResComm(const char* comm);
	inline void Res(const char* comm) {
		ResComm(comm);
	}

	template<typename T>
	void Res(const char* comm, T a) {
		if (pt4taskmakerX::CheckTT()) return;
		if (hide) {
			pt4taskmakerX::ResInternal(comm, a, 1 - rpos, 0, wd);  // add hide result data (Y == 0)
		}
		else {
		        int addpos = 0;
			if (!rep) rpos = 0;
			else if (rpos == PosCenter)
			  addpos = -PosCenter;
			++yr;
			pt4taskmakerX::ResInternal(comm, a, addpos, yr, wd);
		}
		rep = false;
		hide = false;
	}

	template<typename T>
	void Res2(const char* comm, T a1, T a2) {
		if (pt4taskmakerX::CheckTT()) return;
		if (hide) {
			pt4taskmakerX::ResInternal2(comm, a1, a2,  1 - rpos, 0, wd);  // add hide result data (Y == 0)
		}
		else {
		        int addpos = 0;
			if (!rep) rpos = 0;
			else if (rpos == PosCenter)
			  addpos = -PosCenter;
			++yr;
			pt4taskmakerX::ResInternal2(comm, a1, a2, addpos, yr, wd);
		}
		rep = false;
		hide = false;
	}

	template<typename T>
	void Res3(const char* comm, T a1, T a2, T a3) {
		if (pt4taskmakerX::CheckTT()) return;
		if (hide) {
			pt4taskmakerX::ResInternal3(comm, a1, a2, a3, 1 - rpos, 0, wd);  // add hide result data (Y == 0)
		}
		else {
		        int addpos = 0;
			if (!rep) rpos = 0;
			else if (rpos == PosCenter)
			  addpos = -PosCenter;
			++yr;
			pt4taskmakerX::ResInternal3(comm, a1, a2, a3, addpos, yr, wd);
		}
		rep = false;
		hide = false;
	}

	template<typename T>
	void Res(const char* comm1, T a1, const char* comm2) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!rep) rpos = 0;
		++yr;
		pt4taskmakerX::ResInternal(comm1, a1, xLeft, yr, wd);
		pt4taskmaker::ResultComment(comm2, xRight, yr);
		rep = false;
	}

	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!rep) rpos = 0;
		++yr;
		pt4taskmakerX::ResInternal(comm1, a1, xLeft, yr, wd);
		pt4taskmakerX::ResInternal(comm2, a2, xRight, yr, wd);
		rep = false;
	}

	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!rep) rpos = 0;
		++yr;
		pt4taskmakerX::ResInternal(comm1, a1, xLeft, yr, wd);
		pt4taskmakerX::ResInternal(comm2, a2, 0, yr, wd);
		pt4taskmaker::ResultComment(comm3, xRight, yr);
		rep = false;
	}

	template<typename T1, typename T2, typename T3>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
		if (pt4taskmakerX::CheckTT()) return;
		if (!rep) rpos = 0;
		++yr;
		pt4taskmakerX::ResInternal(comm1, a1, xLeft, yr, wd);
		pt4taskmakerX::ResInternal(comm2, a2, 0, yd, wd);
		pt4taskmakerX::ResInternal(comm3, a3, xRight, yr, wd);
		rep = false;
	}

	void Res(const std::vector<bool>& seq);
	void Res(const std::vector<int>& seq);
	void Res(const std::vector<double>& seq);
	void Res(const std::vector<char>& seq);
	void Res(const std::vector<string>& seq);

	inline void ResPos(const char* comm, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(rpos, pos) && (yr > 0) && (rpos != 0)) {
				--yr; // остаемся на текущей строке
			}
			rpos = pos;
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция результирующих данных должна быть больше 0 и меньше 79");
			return;
		}
		rep = true;
		Res(comm);
	}

	template<typename T>
	void ResPos(const char* comm, T a, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(rpos, pos) && (yr > 0) && (rpos != 0)) {
				--yr; // остаемся на текущей строке
			}
			rpos = pos;
		}
		else if (pos == PosHide) {
			hide = true;  
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция результирующих данных должна быть больше 0 и меньше 79");
			return;
		}
		rep = true;
		Res(comm, a);
	}

	template<typename T>
	void ResPos(const char* comm, T a1, T a2, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(rpos, pos) && (yr > 0) && (rpos != 0)) {
				--yr; // остаемся на текущей строке
			}
			rpos = pos;
		}
		else if (pos == PosHide) {
			hide = true;  
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция результирующих данных должна быть больше 0 и меньше 79");
			return;
		}
		rep = true;
		Res2(comm, a1, a2);
	}

	template<typename T>
	void ResPos(const char* comm, T a1, T a2, T a3, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(rpos, pos) && (yr > 0) && (rpos != 0)) {
				--yr; // остаемся на текущей строке
			}
			rpos = pos;
		}
		else if (pos == PosHide) {
			hide = true;  
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция результирующих данных должна быть больше 0 и меньше 79");
			return;
		}
		rep = true;
		Res3(comm, a1, a2, a3);
	}

	template<typename Container>
	void ResPos(const Container& seq, int pos) {
		if (pt4taskmakerX::CheckTT())
		return;
		int n = seq.size();
		if (n == 0) return;

		if (pt4taskmakerX::checkPos(pos)) {
			if (pt4taskmakerX::nextPos(rpos, pos) && (yr > 0) && (rpos != 0)) {
				--yr; // остаемся на текущей строке
			}
			rpos = pos;
		}
		else {
			pt4taskmakerX::ErrorInfo("Error: Позиция результирующих данных должна быть больше 0 и меньше 79");
			return;
		}
		rep = true;
		Res((vector<typename Container::value_type>)seq);
	}

	void SetWidth(int n);
	void SetPrecision(int n);
	void SetTestCount(int n);
	void SetRequiredDataCount(int n);
	int CurrentTest();
	void ShowInfo(const string &info);
	void SetFileRowSize(int n);
	void SetSeqRowSize(int n);


	int Random(int M, int N);
	double Random(); 
	double Random(double A, double B);
	double Random1(double A, double B);
	double Random2(double A, double B);
	string RandomName(int len);

	void NewGroup(const char* GroupDescription, const char* GroupAuthor, const char* GroupKey, int Options = 0);
	void UseTask(const char* GroupName, int TaskNumber);
	void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription);

	int CurrentLanguage();

	string CurrentLocale();

	string CurrentVersion();  // добавлено в версии 4.10

	vector<string> GetWords();
	vector<string> GetEnWords();
	vector<string> GetSentences();
	vector<string> GetEnSentences();
	vector<string> GetTexts();
	vector<string> GetEnTexts();

	string RandomWord();
	string RandomEnWord();
	string RandomSentence();
	string RandomEnSentence();
	string RandomText();
	string RandomEnText();

	void DataFileInt(string FileName);
	void DataFileDouble(string FileName);
	void DataFileChar(string FileName);
	void DataFileShortString(string FileName);
	void DataFileText(string FileName, int LineCount = 5);

	void ResFileInt(string FileName);
	void ResFileDouble(string FileName);
	void ResFileChar(string FileName);
	void ResFileShortString(string FileName);
	void ResFileText(string FileName, int LineCount = 5);

	void ConvertToShortString(string s, ShortString buf);

	void SetProcess(int ProcessRank);

}
	class pt {
	public:
		/// Additional option for the NewGroup function: the task group is available only if there exists a related add-on file.
		///
		/// Дополнительная опция для функции NewGroup: группа доступна только при наличии связанного с ней файла дополнений.
		static const int OptionUseAddition = pt4taskmakerX::OptionUseAddition;

		/// Additional option for the NewGroup function: in the tasks of the group, an example of the right solution will not be displayed.
		///
		/// Дополнительная опция для функции NewGroup: в заданиях данной группы не будет отображаться пример верного решения.
		static const int OptionHideExamples = pt4taskmakerX::OptionHideExamples;

		/// Special value for the pos parameter: the data item is centered in the left half of the taskbook window.
		///
		/// Специальное значение для параметра pos: злемент данных центрируется относительно левой половины окна задачника.
		static const int PosLeft = pt4taskmakerX::PosLeft;

		/// Special value for the pos parameter: the data item is centered horizontally relative to the task window.
		///
		/// Специальное значение для параметра pos: элемент данных центрируется по горизонтали относительно окна задачника.
		static const int PosCenter = pt4taskmakerX::PosCenter;

		/// Special value for the pos parameter: the data item is centered in the right half of the taskbook window.
		///
		/// Специальное значение для параметра pos: злемент данных центрируется относительно правой половины окна задачника.
		static const int PosRight = pt4taskmakerX::PosRight;

		/// Special value for the pos parameter: the data item is not displayed in the taskbook window.
		///
		/// Специальное значение для параметра pos: злемент данных не отображается в окне задачника.
		static const int PosHide = pt4taskmakerX::PosHide;

		/// Function to start defining a new task; must be called in the DefineTask macro.
		/// The Topic parameter defines the name of the subgroup (can be an empty string).
		/// The TaskText parameter contains the wording of the task; it is recommended to use the verbatim strings R"(text)".
		/// The ProcessCount parameter defines the number of processes; it is required only in parallel MPI programming tasks.
		///
		/// Функция, с которой начинается определение нового задания; должна вызываться в макросе DefineTask.
		/// Параметр Topic определяет имя подгруппы (может быть пустой строкой).
		/// Параметр TaskText содержит формулировку задания; рекомендуется использовать дословные строки R"(текст)".
		/// Параметр ProcessCount определяет число процессов; требуется только в заданиях на паралелльное MPI-программирование.
		static void NewTask(const char* Topic, const char* TaskText, int* ProcessCount) {
			pt4taskmakerX::NewTask(Topic, TaskText, ProcessCount);
		}

		/// Function to start defining a new task; must be called in the DefineTask macro.
		/// The Topic parameter defines the name of the subgroup (can be an empty string).
		/// The TaskText parameter contains the wording of the task; it is recommended to use the verbatim strings R"(text)".
		///
		/// Функция, с которой начинается определение нового задания; должна вызываться в макросе DefineTask.
		/// Параметр Topic определяет имя подгруппы (может быть пустой строкой).
		/// Параметр TaskText содержит формулировку задания; рекомендуется использовать дословные строки R"(текст)".
		static void NewTask(const char* Topic, const char* TaskText) {
			pt4taskmakerX::NewTask(Topic, TaskText);
		}

		/// Function to start defining a new task; must be called in the DefineTask macro.
		/// The TaskText parameter contains the wording of the task; it is recommended to use the verbatim strings R"(text)".
		///
		/// Функция, с которой начинается определение нового задания; должна вызываться в макросе DefineTask.
		/// Параметр TaskText содержит формулировку задания; рекомендуется использовать дословные строки R"(текст)".
		static void NewTask(const char* TaskText) {
			pt4taskmakerX::NewTask(TaskText);
		}

		/// Adds a data item and its comment to a new line of the source data section.
		///
		/// Добавляет элемент данных и его комментарий в новой строке раздела исходных данных.
		template<typename T>
		static void Data(const char* comm, T a) {
			pt4taskmakerX::Data(comm, a);
		}

		/// Adds a comment to a new line of the source data section.
		///
		/// Добавляет комментарий в новой строке раздела исходных данных.
		static void Data(const char* comm) {
			pt4taskmakerX::DataComm(comm);
		}

		/// Adds a data item, its comment and an additional comment to a new line of the source data section.
		///
		/// Добавляет элемент данных, его комментарий и дополнительный комментарий в новой строке раздела исходных данных.
		template<typename T>
		static void Data(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Data(comm1, a1, comm2);
		}

		/// Adds two data items and their comments to a new line of the source data section.
		///
		/// Добавляет два элемента данных и их комментарии в новой строке раздела исходных данных.
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2);
		}

		/// Adds two data items, their comments and additional comment to a new line of the source data section.
		///
		/// Добавляет два элемента данных, их комментарии и дополнительный комментарий в новой строке раздела исходных данных.
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3);
		}

		/// Adds three data items and their comments to a new line of the source data section.
		///
		/// Добавляет три элемента данных и их комментарии в новой строке раздела исходных данных.
		template<typename T1, typename T2, typename T3>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3, a3);
		}

		/// Adds a sequence of logical data to the source data section.
		///
		/// Добавляет последовательность логических данных в раздел исходных данных.
		static void Data(const std::vector<bool>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Adds a sequence of integers to the source data section.
		///
		/// Добавляет последовательность целых чисел в раздел исходных данных.
		static void Data(const std::vector<int>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Adds a sequence of real numbers to the source data section.
		///
		/// Добавляет последовательность вещественных чисел в раздел исходных данных.
		static void Data(const std::vector<double>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Adds a sequence of characters to the source data section.
		///
		/// Добавляет последовательность символов в раздел исходных данных.
		static void Data(const std::vector<char>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Adds a sequence of strings to the source data section.
		///
		/// Добавляет последовательность строк в раздел исходных данных.
		static void Data(const std::vector<string>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Adds a comment to the source data section, starting at the specified pos position.
		///
		/// Добавляет комментарий в раздел исходных данных, начиная с указанной позиции pos.
		static void DataPos(const char* comm, int pos) {
			pt4taskmakerX::DataPos(comm, pos);
		}

		/// Adds a data item and its comment to the source data section, starting at the specified pos position.
		///
		/// Добавляет элемент данных и его комментарий в раздел исходных данных, начиная с указанной позиции pos.
		template<typename T>
		static void DataPos(const char* comm, T a, int pos) {
			pt4taskmakerX::DataPos(comm, a ,pos);
		}

		/// Adds two data items and their common comment to the source data section, starting at the specified pos position.
		///
		/// Добавляет два элемента данных и их общий комментарий в раздел исходных данных, начиная с указанной позиции pos.
		template<typename T>
		static void DataPos(const char* comm, T a1, T a2, int pos) {
			pt4taskmakerX::DataPos(comm, a1, a2, pos);
		}

		/// Adds three data items and their common comment to the source data section, starting at the specified pos position.
		///
		/// Добавляет три элемента данных и их общий комментарий в раздел исходных данных, начиная с указанной позиции pos.
		template<typename T>
		static void DataPos(const char* comm, T a1, T a2, T a3, int pos) {
			pt4taskmakerX::DataPos(comm, a1, a2, a3, pos);
		}

		/// Adds a sequence of data to the source data section, starting at the specified pos position.
		///
		/// Добавляет последовательность данных в раздел исходных данных, начиная с указанной позиции pos.
		template<typename Container>
		static void DataPos(const Container& seq, int pos) {
			pt4taskmakerX::DataPos(seq, pos);
		}

		/// Adds a data item and its comment to a new line of the results section.
		///
		/// Добавляет элемент данных и его комментарий в новой строке раздела результатов.
		template<typename T>
		static void Res(const char* comm, T a) {
			pt4taskmakerX::Res(comm, a);
		}

		/// Adds a comment to a new line of the results section.
		///
		/// Добавляет комментарий в новой строке раздела результатов.
		static void Res(const char* comm) {
			pt4taskmakerX::ResComm(comm);
		}

		/// Adds a data item, its comment and an additional comment to a new line of the results section.
		///
		/// Добавляет элемент данных, его комментарий и дополнительный комментарий в новой строке раздела результатов.
		template<typename T>
		static void Res(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Res(comm1, a1, comm2);
		}

		/// Adds two data items and their comments to a new line of the results section.
		///
		/// Добавляет два элемента данных и их комментарии в новой строке раздела результатов.
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2);
		}

		/// Adds two data items, their comments and additional comment to a new line of the results section.
		///
		/// Добавляет два элемента данных, их комментарии и дополнительный комментарий в новой строке раздела результатов.
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3);
		}

		/// Adds three data items and their comments to a new line of the results section.
		///
		/// Добавляет три элемента данных и их комментарии в новой строке раздела результатов.
		template<typename T1, typename T2, typename T3>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3, a3);
		}

		/// Adds a sequence of logical data to the results section.
		///
		/// Добавляет последовательность логических данных в раздел результатов.
		static void Res(const std::vector<bool>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Adds a sequence of integers to the results section.
		///
		/// Добавляет последовательность целых чисел в раздел результатов.
		static void Res(const std::vector<int>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Adds a sequence of real numbers to the results section.
		///
		/// Добавляет последовательность вещественных чисел в раздел результатов.
		static void Res(const std::vector<double>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Adds a sequence of characters to the results section.
		///
		/// Добавляет последовательность символов в раздел результатов.
		static void Res(const std::vector<char>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Adds a sequence of strings to the results section.
		///
		/// Добавляет последовательность строк в раздел результатов.
		static void Res(const std::vector<string>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Adds a data item and its comment to the results section, starting at the specified pos position.
		///
		/// Добавляет элемент данных и его комментарий в раздел результатов, начиная с указанной позиции pos.
		template<typename T>
		static void ResPos(const char* comm, T a, int pos) {
			pt4taskmakerX::ResPos(comm, a ,pos);
		}

		/// Adds a comment to the results section, starting at the specified pos position.
		///
		/// Добавляет комментарий в раздел результатов, начиная с указанной позиции pos.
		static void ResPos(const char* comm, int pos) {
			pt4taskmakerX::ResPos(comm, pos);
		}

		/// Adds two data items and their common comment to the results section, starting at the specified pos position.
		///
		/// Добавляет два элемента данных и их общий комментарий в раздел результатов, начиная с указанной позиции pos.
		template<typename T>
		static void ResPos(const char* comm, T a1, T a2, int pos) {
			pt4taskmakerX::ResPos(comm, a1, a2, pos);
		}

		/// Adds three data items and their common comment to the results section, starting at the specified pos position.
		///
		/// Добавляет три элемента данных и их общий комментарий в раздел результатов, начиная с указанной позиции pos.
		template<typename T>
		static void ResPos(const char* comm, T a1, T a2, T a3, int pos) {
			pt4taskmakerX::ResPos(comm, a1, a2, a3, pos);
		}

		/// Adds a sequence of data to the results section, starting at the specified pos position.
		///
		/// Добавляет последовательность данных в раздел результатов, начиная с указанной позиции pos.
		template<typename Container>
		static void ResPos(const Container& seq, int pos) {
			pt4taskmakerX::ResPos(seq, pos);
		}

		/// Sets the minimum output field width for numeric data (0..10).
		///
		/// Задает минимальную ширину поля вывода для числовых данных (0..10).
		static void SetWidth(int n) {
			pt4taskmakerX::SetWidth(n);
		}

		/// Sets the display format for real numbers: fixed-point and n fractional digits (1..10), floating-point (-10..0); n = 2 by default.
		///
		/// Задает формат отображения вещественных чисел: с фиксированной точкой и n дробными знаками (1..10), с плавающей точкой (-10..0);  по умолчанию n = 2.
		static void SetPrecision(int n) {
			pt4taskmakerX::SetPrecision(n);
		}

		/// Sets the number of test runs to check the program correctness (2..10); default is 5.
		///
		/// Задает количество тестовых запусков для проверки правильности программы (2..10); по умолчанию 5.
		static void SetTestCount(int n) {
			pt4taskmakerX::SetTestCount(n);
		}

		/// Sets the minimum number of input data items required to solve the task (by default, all data must be input).
		///
		/// Задает минимально необходимое количество элементов исходных данных, требуемое для решения задачи (по умолчанию надо ввести все исходные данные).
		static void SetRequiredDataCount(int n) {
			pt4taskmakerX::SetRequiredDataCount(n);
		}

		/// Returns the number of the current test run (runs are numbered from 1; returns 0 for demo run).
		///
		/// Возвращает номер текущего тестового запуска (запуски нумеруются от 1; при демо-запуске возвращает 0).
		static int CurrentTest() {
			return pt4taskmakerX::CurrentTest();
		}

		/// Generates a random integer in the range from M to N inclusive. If M >= N, then returns M.
		///
		/// Генерирует случайное целое число в диапазоне от M до N включительно. Если M >= N, то возвращает M.
		static int Random(int M, int N) {
			return pt4taskmakerX::Random(M, N);
		}

		/// Generates a random real number on the semi-interval [0.0, 1.0).
		///
		/// Генерирует случайное вещественное число на промежутке [0.0, 1.0).
		static double Random() {
			return pt4taskmakerX::Random();
		}

		/// Generates a random real number on the semi-interval [A, B). If A >= B, then returns M.
		///
		/// Генерирует случайное вещественное число на промежутке [A, B). Если A >= B, то возвращает A.
		static double Random(double A, double B) {
			return pt4taskmakerX::Random(A, B);
		}

		/// Generates a random real number on the interval [A, B) with one fractional digit and a random additive of order 1.0e-7. If A >= B, then returns A converted in the same way.
		///
		/// Генерирует случайное вещественное число на промежутке [A, B) с одним дробным знаком и случайной добавкой порядка 1.0e-7. Если A >= B, то возвращает A, преобразованное аналогичным образом.
		static double Random1(double A, double B) {
			return pt4taskmakerX::Random1(A, B);
		}

		/// Generates a random real number on the interval [A, B) with two fractional digits and a random additive of order 1.0e-7. If A >= B, then returns A converted in the same way.
		///
		/// Генерирует случайное вещественное число на промежутке [A, B) с двумя дробными знаками и случайной добавкой порядка 1.0e-7. Если A >= B, то возвращает A, преобразованное аналогичным образом.
		static double Random2(double A, double B) {
			return pt4taskmakerX::Random2(A, B);
		}

		/// Generates a random string of length len consisting of digits and lowercase Latin letters.
		///
		/// Генерирует случайную строку длины len, состоящую из цифр и строчных латинских букв.
		static string RandomName(int len) {
			return pt4taskmakerX::RandomName(len);
		}

		/// Creates a new group with a short description GroupDescription, author information GroupAuthor, group key GroupKey and a set of optional options. The NewGroup function must be called in the inittaskgroup function without parameters.
		///
		/// Создает новую группу с кратким описанием GroupDescription, информацией об авторе GroupAuthor, ключом группы GroupKey и набором необязательных опций. Функция NewGroup должна быть вызвана в функции inittaskgroup без параметров.
		static void NewGroup(const char* GroupDescription, const char* GroupAuthor, const char* GroupKey, int Options = 0) {
			pt4taskmakerX::NewGroup(GroupDescription, GroupAuthor, GroupKey, Options);
		}

		/// Imports an existing task from GroupName group with TaskNumber number. The TopicDescription parameter allows you to change the title of the group or subgroup associated with the imported task.
		///
		/// Импортирует в создаваемую группу существующее задание из группы GroupName с номером TaskNumber. Параметр TopicDescription позволяет изменить заголовок группы или подгруппы, связанной с импортируемым заданием.

		static void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber, TopicDescription);
		}

		/// Imports an existing task from GroupName group with TaskNumber number.
		///
		/// Импортирует в создаваемую группу существующее задание из группы GroupName с номером TaskNumber.
		static void UseTask(const char* GroupName, int TaskNumber) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber);
		}


		/// Returns the current programming language selected for the taskbook (one of lgXXX constants).
		///
		/// Возвращает текущий язык программирования, выбранный для задачника в виде одной из констант lgXXX.
		static int CurrentLanguage() {
			return pt4taskmakerX::CurrentLanguage();
		}

		/// Returns a two-letter string describing the current locale ("ru" or "en")
		///
		/// Возвращает двухбуквенную строку с описанием текущей локали ("ru", либо "en")
		static string CurrentLocale() {
			return pt4taskmakerX::CurrentLocale();
		}

		/// Returns the number of the current version of the taskbook in the format "d.dd"
		///
		/// Возвращает номер текущей версии задачника в формате "d.dd"
		static string CurrentVersion() {
			return pt4taskmakerX::CurrentVersion();
		}

		/// Returns a set of 116 words (English for English locale, Russian for Russian locale).
		///
		/// Возвращает набор из 116 слов (английских для английской локали, русских для русской).
		static vector<string> Words() {
			return pt4taskmakerX::GetWords();
		}
		/// Returns a set of 116 English words.
		///
		/// Возвращает набор из 116 английских слов.
		static vector<string> EnWords() {
			return pt4taskmakerX::GetEnWords();
		}

		/// Returns a set of 61 sentences (English for English locale, Russian for Russian locale).
		///
		/// Возвращает набор из 61 предложения (на английском языке для английской локали, на русском языке для русской).
		static vector<string> Sentences() {
			return pt4taskmakerX::GetSentences();
		}

		/// Returns a set of 61 English sentences.
		///
		/// Возвращает набор из 61 английского предложения.
		static vector<string> EnSentences() {
			return pt4taskmakerX::GetEnSentences();
		}

		/// Returns a set of 85 multiline texts (English for English locale, Russian for Russian locale). The text lines are separated by \\n character.
		///
		/// Возвращает набор из 85 многострочных текстов (на английском языке для английской локали, на русском языке для русской). Строки текста разделяются символом \\n.
		static vector<string> Texts() {
			return pt4taskmakerX::GetTexts();
		}

		/// Returns a set of 85 English multiline texts. The text lines are separated by \\n character.
		///
		/// Возвращает набор из 85 английских многострочных текстов. Строки текста разделяются символом \\n.
		static vector<string> EnTexts() {
			return pt4taskmakerX::GetEnTexts();
		}

		/// Returns a random word from the Words set.
		///
		/// Возвращает случайное слово из набора Words.
		static string RandomWord() {
			return pt4taskmakerX::RandomWord();
		}

		/// Returns a random word from the EnWords set.
		///
		/// Возвращает случайное слово из набора EnWords.
		static string RandomEnWord() {
			return pt4taskmakerX::RandomEnWord();
		}

		/// Returns a random sentence from the Sentences set.
		///
		/// Возвращает случайное слово из набора Sentences.
		static string RandomSentence() {
			return pt4taskmakerX::RandomSentence();
		}

		/// Returns a random sentence from the EnSentences set.
		///
		/// Возвращает случайное слово из набора EnSentences.
		static string RandomEnSentence() {
			return pt4taskmakerX::RandomEnSentence();
		}

		/// Returns a random multiline text from the Texts set.
		///
		/// Возвращает случайный многострочный текст из набора Texts.
		static string RandomText() {
			return pt4taskmakerX::RandomText();
		}

		/// Returns a random multiline text from the EnTexts set.
		///
		/// Возвращает случайный многострочный текст из набора EnTexts.
		static string RandomEnText() {
			return pt4taskmakerX::RandomEnText();
		}

		/// Adds a binary file named FileName with integers to the source data set.
		///
		/// Добавляет в набор исходных данных двоичный файл целых чисел с именем FileName.
		static void DataFileInt(const string &FileName) {
			pt4taskmakerX::DataFileInt(FileName);
		}

		/// Adds a binary file named FileName with real numbers to the source data set.
		///
		/// Добавляет в набор исходных данных двоичный файл вещественных чисел с именем FileName.
		static void DataFileDouble(const string &FileName) {
			pt4taskmakerX::DataFileDouble(FileName);
		}

		/// Adds a binary file named FileName with characters to the source data set.
		///
		/// Добавляет в набор исходных данных двоичный символьный файл с именем FileName.
		static void DataFileChar(const string &FileName) {
			pt4taskmakerX::DataFileChar(FileName);
		}

		/// Adds a binary file named FileName with Pascalstrings of ShortString type to the source data set. The length of file items must not exceed 70 characters.
		///
		/// Добавляет в набор исходных данных двоичный строковый файл с именем FileName, содержащий Pascal-строки типа ShortString. Длина файловых строк не должна превосходить 70 символов.
		static void DataFileShortString(const string &FileName) {
			pt4taskmakerX::DataFileShortString(FileName);
		}

		/// Adds a text file named FileName to the source data set. The length of file lines must not exceed 70 characters. The LineCount parameter (1..5) defines the number of lines of the file when it is displayed in the collapsed mode.
		///
		/// Добавляет в набор исходных данных текстовый файл с именем FileName. Длина строк не должна превосходить 70 символов. Параметр LineCount (1..5) определяет число строк файла при его отображении в сокращенном режиме.
		static void DataFileText(const string &FileName, int LineCount = 5) {
			pt4taskmakerX::DataFileText(FileName, LineCount);
		}

		/// Adds a binary file named FileName with integers to the result set.
		///
		/// Добавляет в набор результатов двоичный файл целых чисел с именем FileName.
		static void ResFileInt(string FileName) {
			pt4taskmakerX::ResFileInt(FileName);
		}

		/// Adds a binary file named FileName with real numbers to the result set.
		///
		/// Добавляет в набор результатов двоичный файл вещественных чисел с именем FileName.
		static void ResFileDouble(const string &FileName) {
			pt4taskmakerX::ResFileDouble(FileName);
		}

		/// Adds a binary file named FileName with characters to the result set.
		///
		/// Добавляет в набор результатов двоичный символьный файл с именем FileName.
		static void ResFileChar(const string &FileName) {
			pt4taskmakerX::ResFileChar(FileName);
		}

		/// Adds a binary file named FileName with Pascal strings of ShortString type to the result set. The length of file items must not exceed 70 characters.
		///
		/// Добавляет в набор результатов двоичный строковый файл с именем FileName, содержащий Pascal-строки типа ShortString. Длина файловых строк не должна превосходить 70 символов.
		static void ResFileShortString(const string &FileName) {
			pt4taskmakerX::ResFileShortString(FileName);
		}

		/// Adds a text file named FileName to the result set. The length of file lines must not exceed 70 characters. The LineCount parameter (1..5) defines the number of lines of the file when it is displayed in the collapsed mode.
		///
		/// Добавляет в набор результатов текстовый файл с именем FileName. Длина строк не должна превосходить 70 символов. Параметр LineCount (1..5) определяет число строк файла при его отображении в сокращенном режиме.
		static void ResFileText(const string &FileName, int LineCount = 5) {
			pt4taskmakerX::ResFileText(FileName, LineCount);
		}
		
		/// Converts a regular string to a Pascal string (of type ShortString).
		///
		/// Конвертирует обычную строку в Pascal-строку (типа ShortString).
		static void ConvertToShortString(const string &s, ShortString buf) {
			pt4taskmakerX::ConvertToShortString(s, buf);
		}

		/// Sets the current process for further transfer of numerical data to it. Used for parallel MPI programming tasks.
		///
		/// Устанавливает текущий процесс для последующей передачи ему числовых данных. Используется для заданий по параллельному MPI-программированию.
		static void SetProcess(int ProcessRank) {
			pt4taskmakerX::SetProcess(ProcessRank);
		}

		/// Outputs debugging information in a pop-up dialog box.
		///
		/// Выводит отладочную информацию во всплывающем диалоговом окне.
		static void ShowInfo(const string &info) {
			pt4taskmakerX::ShowInfo(info);
		}

		/// Sets the number of binary file items displayed on one screen line (to set the maximum possible number of items, specify 0).
		///
		/// Задает количество элементов двоичного файла, отображаемых на одной экранной строке (для задания максимально возможного количества элементов следует указать 0).
		static void SetFileRowSize(int n) {
			pt4taskmakerX::SetFileRowSize(n);
		}

		/// Sets the number of sequence items displayed on one screen line (to set the maximum possible number of items, specify 0).
		///
		/// Задает количество элементов последовательности, отображаемых на одной экранной строке (для задания максимально возможного количества элементов следует указать 0).
		static void SetSeqRowSize(int n) {
			pt4taskmakerX::SetSeqRowSize(n);
		}

		/// Checks the current locale of the taskbook and returns EnText in case of English locale, otherwise returns RuText.
		///
		/// Проверяет текущую локаль задачника и в случае английской локали возвращает EnText, иначе возвращает RuText.
		static const char *Loc(const char *EnText, const char *RuText) {
			return pt4taskmakerX::CurrentLocale() == "en" ? EnText : RuText;
		}
	};

template<typename T>
void pt4taskmakerX::DataInternal(const char* s, T a, int x, int y, int w) {
    if ((y > 5) && fd) {
        pt4taskmakerX::ErrorInfo(ErrMes2);
        return;
    }
    ++nd;
    if (nd > datmax) {
        pt4taskmakerX::ErrorInfo(ErrMes3);
        return;
    }
    pt4taskmakerX::Data(s, a, x + dpos, y, w);
}

template<typename T>
void pt4taskmakerX::ResInternal(const char* s, T a, int x, int y, int w) {
	if ((y > 5) && fr) {
		pt4taskmakerX::ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > datmax) {
		pt4taskmakerX::ErrorInfo(ErrMes4);
		return;
	}
    pt4taskmakerX::Res(s, a, x + rpos, y, w);
}


#endif // _PT4TASKMAKERX
