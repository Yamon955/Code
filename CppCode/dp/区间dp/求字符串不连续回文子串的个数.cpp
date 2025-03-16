//HDU-4632
//https://blog.csdn.net/l954688947/article/details/50620302
//https://blog.csdn.net/qq_40772692/article/details/80183248


// 状态转移方程： dp[i][j]表示i~j内最多的回文字串数目

// dp[i][j] = dp[i+1][j]+dp[i][j-1] -dp[i+1][j-1] (容斥）

// if(s[i] == s[j]) dp[i][j] = dp[i][j] +dp[i+1][j-1] +1; （思维）

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
const int N = 1e3+5;
int dp[N][N];//dp[i][j]表示从第i个到第j个有多少个回文子序列
char s[N];
const int MOD = 10007;
int main()
{
	int T;
	cin>>T;
	int Case = 0;
	while(T--){
		cin>>s+1;
		int len_s = strlen(s+1);
		mem(dp,0);
		for(int i=1;i<=len_s;i++) dp[i][i] = 1;
		
		// for(int j=1;j<=len_s;j++){
		// 	for(int i=j-1;i>=1;i--){
		// 		//状态转移方程涉及减法，直接取模有可能为负数，必须要先加一下mod
		// 		dp[i][j] = (dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+MOD)%MOD;
				
		// 		if(s[i] == s[j]) dp[i][j] = (dp[i][j]+dp[i+1][j-1]+1)%MOD;

		// 	}
		// }
        for(int len=2;len<=len_s;len++){
			for(int i=1;i<=len_s-len+1;i++){
				int j = i+len-1;
                ////状态转移方程涉及减法，直接取模有可能为负数，必须要先加一下mod
				dp[i][j] = (dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+MOD)%MOD;
				if(s[i] == s[j]) dp[i][j] = (dp[i][j] + dp[i+1][j-1]+1)%MOD;

			}
		}
		printf("Case %d: %d\n",++Case,dp[1][len_s]);
	}
}
/*
Sample Input
4
a
aaaaa
goodafternooneveryone
welcometoooxxourproblems
Sample Output
Case 1: 1
Case 2: 31
Case 3: 421
Case 4: 960
*/