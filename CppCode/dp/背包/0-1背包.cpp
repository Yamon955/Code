#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[100][100];//ans[i][j]表示在第(i,i+1,i+2,.....n-1,n)件物品中选取到空间大小为j的背包的物品最大值
int w[100];//每件物品重量
int v[100];//每件物品的价值
int x[100];//值为0或1，表示第i件物品是否装入背包
int c;//背包空间大小
int n;//物品件数
int Max(int a,int b){return a>b?a:b;}
void Knapsack(int v[],int w[],int n,int ans[][100]) 
{   
    //先初始化ans第n行，，即先在最后一个物品中取
    for(int i=0;i<=c;i++){
        if(i<w[n]) ans[n][i]=0;//如果背包空间小于物品n的重量，则赋值0
        else ans[n][i]=v[n];
    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<=c;j++){
            if(w[i]>c) ans[i][j]=ans[i+1][j];
            else if(j>=w[i]) ans[i][j]=Max(ans[i+1][j],ans[i+1][j-w[i]]+v[i]);
            else if(j<w[i]) ans[i][j]=ans[i+1][j];
        }
    }
}
void Knapsack2(int v[],int w[],int fir,int ans[][100])
{
    //先初始化第一行，即先在第一个物品中取
    for(int i=0;i<=c;i++){
        if(i<w[fir]) ans[fir][i]=0;//如果背包空间小于物品n的重量，则赋值0
        else ans[fir][i]=v[fir];
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(w[j]>c) ans[i][j]==0;
            else if(j>=w[i]) ans[i][j]=Max(ans[i-1][j],ans[i-1][j-w[i]]+v[i]);
            else if(j<w[i])  ans[i][j]=ans[i-1][j];
        }
    }
}
void Traceback1(int ans[][100],int i,int s)
{
    if(i==n+1) return ;
    if(ans[i][s]!=ans[i+1][s]) x[i]=1;
    Traceback1(ans,i+1,c-w[i]);
}
void Traceback2(int ans[][100],int w[],int c,int n,int x[])
{
    for(int i=1;i<n;i++){
        if(ans[i][c]==ans[i+1][c]) x[i]=0;
        else {
            x[i]=1;
            c-=w[i];
        }
    }
    x[n]=(ans[n][c])?1:0;
}
int main()
{
    cin>>c>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    Knapsack(v,w,n,ans);
    //Knapsack2(v,w,1,ans);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=c;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    //Traceback1(ans,1,c);
    Traceback2(ans,w,c,n,x);
    for(int i=1;i<=n;i++) 
        if(x[i]==1) cout<<i<<" ";
    return 0;

}
/*
10 5
2 2 6 5 4
6 3 5 4 6
*/