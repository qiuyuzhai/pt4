#include "pt4.h"
#include <fstream>
using namespace std;
fstream fs;
int n;
void fun(string a, int sum)
{
	if (a.length() == n + 1)
	{
		if (sum == 0)
		{
			fs << a << endl;
		}
		return;
	}
	if (a[a.length() - 1] == 'D')
	{
		fun(a + "A", sum + 1);
		fun(a + "B", sum);
		fun(a + "C", sum - 1);
	}
	else if (a[a.length() - 1] == 'A')
	{
		fun(a + "B", sum);
		fun(a + "C", sum - 1);
	}
	else if (a[a.length() - 1] == 'B')
	{
		fun(a + "A", sum + 1);
		fun(a + "C", sum - 1);
	}
	else if (a[a.length() - 1] == 'C')
	{
		fun(a + "A", sum + 1);
		fun(a + "B", sum);
	}
}

void Solve()
{
    Task("Recur30");
    string f;
	pt >> n >> f;
	fs.open(f, std::ios::out);
	fun("D", 0);
	fs.close();
    

}
