#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int w[110];
int dp[110][10010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    //dp[1][w[1]]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==w[i]) dp[i][j] = dp[i-1][j]+1;
            else if(j<w[i]) dp[i][j] = dp[i-1][j];
            else if(j>w[i]) dp[i][j] = dp[i-1][j] + dp[i-1][j-w[i]];
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}
//dfs
// #include<iostream>
// #include<cstdio>
// using namespace std;
// int n,m;
// int w[110];
// int dp[10010];
// int ans;
// void dfs(int x,int sum)
// {
//     //if(sum>m) return;
    
//     if(sum==0){
//         ans++;
//         return ;
//     }
//     if(x==n+1) return;
//         if(sum>=w[x])   dfs(x+1,sum-w[x]);
//         dfs(x+1,sum);
// }
// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         cin>>w[i];
//     }
//     dfs(1,m);
//     cout<<ans<<endl;
//     return 0;
// }