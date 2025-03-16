//HDU-4745
//子串  连续
//子序列  可以不连续
//https://blog.csdn.net/qq_43603598/article/details/109402312
//https://blog.csdn.net/ldw201510803006/article/details/59518710
//可以这样考虑，用dp的方法求出从一个位置到另一个位置的最长回文子串的长度，这样等于把【1-n】个数分成两个区间【1-x】和【x+1，n】，
// 　　　　而答案就是两个区间最长回文串之和。（仔细理解这里，这是关键）。
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
const int N = 2e3+5;
int dp[N][N];//[i][j]表示把第i个数字到第j个数字之间（不包括i，j）的数字去光后得到的最小值
int n;
int a[N];
int solve() //倍增解法
{
	//，只要保证路径是一个回文子序列，两只兔子分别从两端往中间跳即可。
	//最后遍历取max的时候，要考虑两只兔子起点可以相同也可以不相同，
	for(int i=n+1;i<=n*2;i++)
		a[i] = a[i-n];
	for(int i=1;i<=n*2;i++) dp[i][i] = 1;
	for(int len=2;len<=n*2;len++){
		for(int i=1;i<=2*n-len+1;i++){
			int j = i+len-1;
			if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1]+2;
			else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
		}
	}
	int ans = 0;
	for(int i=1;i<=n+1;i++)//从不同点开始
		ans = max(ans,dp[i][i+n-1]);
	for(int i=1;i<=n+2;i++){ //从相同点开始
		ans = max(ans,dp[i][i+n-2]+1);
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		for(int i=1;i<=n;i++) cin>>a[i];
		// for(int i=1;i<=n;i++) dp[i][i] = 1;
		// for(int len=2;len<=n;len++){
		// 	for(int i=1;i<=n-len+1;i++){
		// 		int j = len+i-1;
		// 		if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1]+2;
		// 		else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
		// 	}
		// }
		// int ans = 0;
		// for(int i=1;i<=n;i++)
		// 	ans = max(ans,dp[1][i]+dp[i+1][n]);
		// cout<<ans<<endl;
		cout<<solve()<<endl;
	}
	return 0;
}
/*
Sample Input
1
1
4
1 1 2 1
6
2 1 1 2 1 3
0
 

Sample Output
1
4
5
*/