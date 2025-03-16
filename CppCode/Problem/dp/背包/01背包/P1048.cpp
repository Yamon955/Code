#include<iostream>
#include<cstdio>
using namespace std;
int t,m;
int w[110],v[110];
int dp[1010];
int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=m;i++){
        for(int j=t;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[t]<<endl;
    return 0;
}