#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int w[30],v[30];
int dp[30010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        w[i] = a;
        v[i] =a*b;
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}