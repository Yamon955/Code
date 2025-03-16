#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[3];

//memset-->一般只进行0,-1,0x3f三个值的赋值
int main()
{
    memset(f,0,sizeof(f));//字节层面的赋值,每一个Int4个字节，每个字节占4位，赋值0000
    //--->一般只有赋值为 0,-1,0x3f(int下接近无限大)才正确
    for(int i=0;i<=2;i++) cout<<f[i]<<" ";
    cout<<endl;
    memset(f,-1,sizeof(f));
    for(int i=0;i<=2;i++) cout<<f[i]<<" ";
    cout<<endl;
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<=2;i++) cout<<f[i]<<" ";
    cout<<endl;

    memset(f,1,sizeof(f));//错误
    //字节层面的赋值,每一个Int4个字节，每个字节占4位，赋值0001
    //赋值之后f[i]=0001 0001 0001 0001= 16843009
    for(int i=0;i<=2;i++) cout<<f[i]<<" ";
    cout<<endl;
     memset(f,0xff,sizeof(f));//错误
    for(int i=0;i<=2;i++) cout<<f[i]<<" ";
    cout<<endl; 
    return 0;
}