#include "pt4.h"
using namespace std;
#include<fstream>
void Solve()
{
    Task("File25");
    fstream f(GetString(),ios::binary|ios::in|ios::out);//标准模式应该是fstream f(name,ios::binary|ios::in|ios::out)即打开二进制文件读和写
    f.seekg(0,ios::end);//ios::end是代表流的结尾，0代表偏移量。f.seekg(0, ios::end);意思是直接跳到当前流的结尾，略过流内的所有数据
    int len=f.tellf(),//通过调用 ftell 函数确定指针位置 ;
    //获取文件大小的代码示例 : 打开文件后 , 直接使用 fseek 跳转到文件末尾 , 然后使用 ftell 获取当前指针 , 打印出指针位置 ;
        size=sizeof(double);
    f.seekg(0);//新的文件流指针的位置值
    for (int i = 0; i < len/size; i++)
    {
        f.seekg(f.tellg());//tellg（）它返回当前定位指针的位置，也代表着输入流的大小。
        double x;
        f.read((char*)&x,size);//通过read函数将文件中的数据按照一定的长度读取出来并且存放在新的数组中。函数前参数是读取字节的位置，后者是读取数量
        //这句话的意思是，read()()成员函数的第一个参数是一个字符指针（即char *类型），而x是一个double变量，
        //所以在传递之前要先进行类型转换，首先取x的地址（也就是&x的作用），然后再把这个地址转换为char *类型，所以要写成(char *)&x
        x=x*x;
        f.seekf(size*i);
        f.write((char*)&x,size);
    }
    f.close();
    

        


}
