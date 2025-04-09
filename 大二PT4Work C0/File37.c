#include "pt4.h"
#include<stdio.h>
void Solve(void)
{
    Task("File37");
    char name[13];
    GetS(name);
    char*name2="a.tmp";
    FILE*f=fopen(name,"rb");//在文件中打开一个现有的文件以二进制模式读取
    FILE*f2=fopen(name2,"wb");//创建一个文件以二进制模式写入
    int a;
    int sz=sizeof(int);
    while (fread(&a,sz,1,f))//从f中读取数据到a    .这里不就是把f里的数据一个个存进f2中嘛
       fwrite(&a,sz,1,f2);//把a中的数据写入f2
    int n=ftell(f)/sz;//ftell指返回到f的当前文件位置
    for (int i = n-1; i >= 0; i--)
    {
        fseek(f,i*sz,SEEK_SET);//设置f的文件位置为i*sz，i*sz是从SEEK_SET中查找的字节数
        fread(&a,sz,1,f);//从f中读取数据到a
        fwrite(&a,sz,1,f2);//把a中的数据写入f2
    }
    fclose(f);
    fclose(f2);
    remove(name);//删除文件名name,它不再被访问
    rename(name2,name);//把name2改名为name


}
