#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char s1[2005],s2[2005];
int a[2005],b[2005],c[2005];
int main()
{
    cin>>s1>>s2;
    int la,lb,lc;
    la=strlen(s1);
    lb=strlen(s2);
    for(int i=0;i<la;i++){
        a[la-i]=s1[i]-'0';
    }
    for(int i=0;i<lb;i++){
        b[lb-i]=s2[i]-'0';
    }
    lc=la+lb;
    for(int i=1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            c[i+j-1]+=a[i]*b[j];
            c[i+j]+=c[i+j-1]/10;
            c[i+j-1]=c[i+j-1]%10;
        }
    }
    while(c[lc]==0&&lc>1) lc--;
    for(int i=lc;i>0;i--) cout<<c[i];
    return 0;
}