#include "pt4.h"
#include<fstream>
using namespace std;
void Solve()
{
    Task("File32");
    string name,name1="$$.tmp";
    pt>>name;
    ifstream f(name,ios::binary);//读文件f
    ofstream f1(name1,ios::binary);//写文件f1
    f.seekg(0,ios::end);//指针指到了文件的最后
    int len=f.tellg()/sizeof(int);//文件的大小
    int size=sizeof(int);
    for (int i = len/2; i <len; i++)
    {
        f.seekg(i*size);
        int x;
        f.read((char*)&x,size);
        f1.write((char*)&x,size);
    }

    f.close();
    f1.close();
    remove(name.c_str());
    rename(name1.c_str(),name.c_str());

}
