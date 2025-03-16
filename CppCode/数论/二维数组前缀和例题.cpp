#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N=5010;
int f[5010][5010];//f[i][j]--->(0,0)->(i,j)二维矩阵中的元素值的和即前缀和
int a[5010][5010];//地图
int n,r;
//题目ac wing P99
int main()
{
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        a[x+1][y+1]+=w;//下标从1开始
    }
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];//求前缀和公式
    int ans=0;
    if(r>=n) ans=f[N-1][N-1];
    else {
           for(int i=r;i<N;i++)
                for(int j=r;j<N;j++){
                    ans=max(ans,f[i][j]-f[i-r][j]-f[i][j-r]+f[i-r][j-r]);
                }
    }
    cout<<ans;
    return 0;
}