#include<iostream>
#include<cstdio>
using namespace std;
int V,M,n;
int v[55],m[55],c[55];
int dp[410][410];
int main()
{
    cin>>V>>M>>n;
    for(int i=1;i<=n;i++) cin>>v[i]>>m[i]>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            for(int k=M;k>=m[i];k--){
                dp[j][k] = max(dp[j][k],dp[j-v[i]][k-m[i]]+c[i]);
            }
        }
    }
    cout<<dp[V][M]<<endl;
    return 0;
}