#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int m,n;
long long  dp[1010][1010];

int main()
{
    cin>>m>>n;
    dp[m+1][1] = 1;
    dp[m+2][1] = 2; 
    int len = 1;
    for(int i=m+3;i<=n;i++){
        for(int j=1;j<=len;j++){
            dp[i][j] = dp[i-1][j]+dp[i-2][j];
        }
        for(int j=1;j<=len;j++){
            if(dp[i][j]>9){
                dp[i][j+1] += dp[i][j]/10;
                dp[i][j] %= 10;
            }
        }
        if(dp[i][len+1]) len++;
    }
    for(int i=len;i>=1;i--) cout<<dp[n][i];
    return 0;

}
/*
1 14
-->377

1 1000
*/