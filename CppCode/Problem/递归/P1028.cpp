#include<iostream>
#include<cstdio>
using namespace std;
int f[1010];
void work(int n)
{
    for(int i=0;i<=n;i++){
        if(i==0||i==1) f[i]=1;
        else {
            for(int j=1;j<=i/2;j++) f[i]+=f[j];
            f[i]+=1;
        }
    }
       
}
int main()
{
    int n;
    cin>>n;
    work(n);
    cout<<f[n]<<endl;
    return 0;
}


/*
f[1]=1
f[2]=2=f[1]+1
f[3]=2=f[1]+1
f[4]=4=f[1]+f[2]+1
f[5]=4=f[1]+f[2]+1
*/