#include "pt4.h"
using namespace std;

void Solve()
{
    Task("File6");
    int k;
    string name;
    pt>>k>>name;
    ifstream f(name,ios::binary);
    int a=-1;
    int sz=sizeof(int);
    f.seekg(0,ios::end);
    int n=f.tellg()/sz;
    if (k<=n)
    {
        f.seekg((k-1)*sz);
        f.read((char*)&a,sz);
    }
    f.close();
    pt<<a;
    
    int k;
    GetN(&k);
    char name[13];
    GetS(name);
    FILE*f=fopen(name,"rb");
    fseek(f,0,SEEK_END);//这就是把文件f先从头到尾走了个遍
    int n=ftell(f)/sz;//这个n是这个文件f的大小
    if (k<=n)
    {
        fseek(f,(k-1)*sz,SEEK_SET);
        fread(&a,sz,1,f);
    }
    fclose(f);
    PutN(a);
    
//例：fseek(fp,100L,0);把fp指针移动到离文件开头100字节处；
//SEEK_SET： 文件开头（0）
// SEEK_CUR： 当前位置（1）
// SEEK_END： 文件结尾（2）



}
// C++中seep()和seekg()函数功能
// seekp：设置输出文件流的文件流指针位置
// seekg：设置输入文件流的文件流指针位置
// 每个枚举常量的含义：
// ios::beg：文件流的起始位置
// ios::cur：文件流的当前位置
// ios::end：文件流的结束位置
//seekg(offset, place);
// 这个输入流类的成员函数的名字 seekg 由两部分组成。首先是 seek(寻找)到文件中的某个地方，其次是 "g" 表示 "get"，指示函数在输入流上工作，因为要从输入流获取数据。
// 要查找的文件中的新位置由两个形参给出：新位置将从由 place 给出的起始位置开始，偏移 offset 个字节。offset 形参是一个 long 类型的整数，而 place 可以是 ios 类中定义的 3 个值之一。起始位置可能是文件的开头、文件的当前位置或文件的末尾，这些地方分别由常量 ios::beg、ios::cur 和 ios::end 表示。
// 有关在文件中移动的更多信息将在后面的章节中给出，目前先来关注如何移动到文件的开头。要移到文件的开始位置，可以使用以下语句：
// seekg(0L,ios::beg);
// 以上语句表示从文件的开头位置开始，移动 0 字节，实际上就是指移动到文件开头。