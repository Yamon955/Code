#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,d;
int ta[25],tb[25],tc[25],td[25];
int Time;
//将每个科目分成两部分，最优解肯定是这两部分大小最接近，假设需要总时间为t,其中一部分需要时间为w,则另一部分需要时间为t-w   ans=max(w,t-w)
//类似于0 1 背包，背包大小为每个科目总的时间的一半
//解题思路：尽可能的将所需总时间的一半用完
void dp(int w[],int n,int v)
{
    int f[25][2000];
    int Max = 0;
    for(int k = 0; k <= v/2; k ++) f[0][k]=0;
    for(int i = 1; i <= n; i ++){
        for(int k = 0; k <= v/2; k ++){
            if(k >= w[i]) f[i][k] = max(f[i-1][k],f[i-1][k-w[i]] + w[i]);
            else f[i][k] = f[i-1][k];
            Max = max(Max,f[i][k]);
        }
    }
    Time += max(Max,v - Max);
}
int Left,Right,Min;
void dfs(int w[],int x,int y)//暴力做法
{
    if(x > y){
        Min = min(Min,max(Left,Right));
    }
    Left += w[x];
    dfs(w,x + 1, y);
    Left -= w[x];
    Right += w[x];
    dfs(w,x + 1,y);
    Right -=w[x];
}
int main()
{
    cin>>a>>b>>c>>d;
    int v=0;
    for(int i = 1; i <= a; i ++) cin>>ta[i],v += ta[i];
    dp(ta,a,v);
    v = 0;
    for(int i = 1; i <= b; i ++) cin>>tb[i],v += tb[i];
    dp(tb,b,v);
    v = 0;
    for(int i = 1; i <= c; i ++) cin>>tc[i],v += tc[i];
    dp(tc,c,v);
    v = 0;
    for(int i = 1; i <= d; i ++) cin>>td[i],v += td[i];
    dp(td,d,v);
    cout<<Time<<endl;
    return 0;

}
/*
1 2 1 3		
5
4 3
6
2 4 3
*/