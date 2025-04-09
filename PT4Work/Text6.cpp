#include <fstream>
using namespace std;

void Solve()
{
    Task("Text6");
    string s,name,name1;
    pt >> name >> name1;
    ofstream f(name , ios::app);
    fstream f1(name1);
        while (f1.peek() != EOF)
    {
        getline(f1,s);
        f << s<< endl;
    }

    f.close();
    f1.close();


}

