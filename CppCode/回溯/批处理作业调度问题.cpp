#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int f1[100],f2[100];
int best=0x3f3f3f3f;
int j1,j2;
int x[100];
void Swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void Backtrack(int k,int sum)
{
    if(k>n){
        if(best>sum){
            best = sum;
        }
        return;
    }
    for(int i=k;i<=n;i++){
        j1 += f1[x[i]];
        int tmp = j2;//暂存当前j2的值，以便于后面的回溯
        if(j2<=j1) j2 = j1+f2[x[i]];
        else j2 = j2+f2[x[i]];
        if(sum+j2<best){
            Swap(x[k],x[i]);
            Backtrack(k+1,sum+j2);
            Swap(x[k],x[i]);
        }
        j1 -= f1[x[i]];
        j2 = tmp;
   
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>f1[i]>>f2[i];
    for(int i=1;i<=n;i++) x[i]=i;//初始化作业调度的第一次的顺序
    Backtrack(1,0);
    cout<<best;
    return 0;
}
