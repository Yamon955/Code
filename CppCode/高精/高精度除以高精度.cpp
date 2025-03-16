#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char s1[5000],s2[5000];
int a[5000],b[5000],c[5000],tmp[5000];
//实现方法->减法模拟除法
int compare(int a[],int b[])//a=b返回0，a>b返回1，a<b返回-1
{
    if(a[0]>b[0]) return 1;
    if(a[0]<b[0]) return -1;
    for(int i=a[0];i>0;i--){
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
    return 0;
}
void minu(int a[],int b[])//做高精度减法
{
    for(int i=1;i<=a[0];i++){
        if(a[i]<b[i]){
            a[i+1]--;
            a[i]=a[i]+10;
        }
        a[i]=a[i]-b[i];
    }
    while(a[a[0]]==0&&a[0]>0) a[0]--;//删除前导0
}
void numcpy(int p[],int q[],int n)//将p数组整体右移n位到q数组中
{
    for(int i=1;i<=p[0];i++) q[i+n-1]=p[i];
    q[0]=p[0]+n-1;
}
int main()
{
    cin>>s1>>s2;
    a[0]=strlen(s1);//规定数组的0号下标位置存数组的长度
    b[0]=strlen(s2);
    for(int i=0;i<a[0];i++){
        a[a[0]-i]=s1[i]-'0';
    }
    for(int i=0;i<b[0];i++){
        b[b[0]-i]=s2[i]-'0';
    }
    c[0]=a[0]-b[0]+1;//商的位数
    for(int i=c[0];i>=1;i--){
        memset(tmp,0,sizeof(tmp));
        numcpy(b,tmp,i);
        while(compare(a,tmp)>=0){
            c[i]++;
            minu(a,tmp);
        }
    }
    while(c[c[0]]==0&&c[0]>0) c[0]--;
    cout<<"商为:"<<endl;
    for(int i=c[0];i>0;i--) cout<<c[i];
    cout<<endl;
    cout<<"余数为:"<<endl;
    for(int i=a[0];i>0;i--) cout<<a[i];
    return 0;

}