#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char s1[5005];
long long a[5005],b,x,c[5005];
//实现方法->逐位试商法
int main()
{
    cin>>s1>>b;//读入被除数和除数
    int la=strlen(s1);
    for(int i=1;i<=la;i++){
        a[i]=s1[i-1]-'0';//将被除数一位一位放入数组a中
    }
    for(int i=1;i<=la;i++){
        c[i]=(x*10+a[i])/b;
        x=(x*10+a[i])%b;
    }
    int lc=1;
    while(c[lc]==0&&lc<la) lc++;//删除前导0
    for(int i=lc;i<=la;i++){
        cout<<c[i];
    }
    return 0;
}
