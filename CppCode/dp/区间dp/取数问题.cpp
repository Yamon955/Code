//poj-1651
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int N = 1e2+5;
int dp[N][N];//[i][j]表示把第i个数字到第j个数字之间（不包括i，j）的数字去光后得到的最小值
int n;
int a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	mem(dp,0);
	
	for(int len=2;len<=n-1;len++){ //len = j - i
		for(int i=1;i<=n-len;i++){
			int j = i+len;
            if(len==2)
                dp[i][j]=a[i]*a[i+2]*a[i+1];
            else
                for(int k=i+1;k<j;k++){
                    if(dp[i][j]==0)
                        dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
                    else
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
				}
		}
	}
	cout<<dp[1][n]<<endl;
	
}
/*
Sample Input
6
10 1 50 50 20 5
Sample Output
3650
*/