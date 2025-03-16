//HDU-1260
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2e3+5;
int T,n;
int dp[N];//dp[i] 表示前 i 个人买票的最短时间
int t[N]; //t[i] 表示第 i 个人买票时间
int dt[N]; //dt[i] 表示第 i-1 个人和第 i 个人一起买票的时间

int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&t[i]);
		for(int i=2;i<=n;i++) scanf("%d",&dt[i]);
		mem(dp,0);
		dp[1] = t[1];
		for(int i=2;i<=n;i++){
			dp[i] = min(dp[i-2]+dt[i],dp[i-1]+t[i]);
		}
		int m = dp[n]/60;
		int h = m/60;
		m = m%60;
		int s = dp[n]%60;
		char ch = 'a';
		if(h>=2) {
			cout<<h+8<<":";
			if(h >= 5) ch = 'p';
		}
		else cout<<"0"<<h+8<<":";
		
		if(m>=10) cout<<m<<":";
		else cout<<"0"<<m<<":";
		
		if(s>=10) cout<<s<<" ";
		else cout<<"0"<<s<<" ";
		
		cout<<ch<<"m"<<endl;
	}
	return 0;
 } 
/*
Sample Input
2
2
20 25
40
1
8
Sample Output
08:00:40 am
08:00:08 am
*/