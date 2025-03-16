#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int t,n;
int dp[10010],w[510],v[510];
int main()
{
    cin>>t;
    while(t--){
        int E,F,m;
        cin>>E>>F;
        m=F-E;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>v[i]>>w[i];
        }
        for(int i=1;i<=m;i++) dp[i] = INF;
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=w[i];j<=m;j++){  
                dp[j] = min(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        if(dp[m]<INF) cout<<"The minimum amount of money in the piggy-bank is "<<dp[m]<<"."<<endl;
        else cout<<"This is impossible."<<endl;
    }
    return 0;
}
