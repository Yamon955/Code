//LightOJ 1032
#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 33;
int T,len,a[N];
ll n;
ll dp[N][N*N][2];
//pos:当前第几位  num:当前已经有几个相邻的 1   pre:前一位是不是 1，   limit:当前位取值有没有范围
ll dfs(int pos,int num,int pre,int limit)
{
	if(pos == 0) return num;
	if(!limit && dp[pos][num][pre]!=-1) return dp[pos][num][pre];
	ll ans = 0;
	int up = limit?a[pos]:1;//按照二进制处理的，每位都是 0或1
	for(int i=0;i<=up;i++){
		if(pre && i==1) ans += dfs(pos-1,num+1,i,(i==up)&&limit);
		else ans += dfs(pos-1,num,i,(i==up)&&limit);
	}
	if(!limit) dp[pos][num][pre] = ans;
	return ans;
 } 
ll part(ll x)
{
	len = 0;
	memset(dp,-1,sizeof dp);
	while(x){
		a[++len] = x%2; //此题不同于以前的按照十进制处理，这是按照二进制处理的
		x /= 2;
	}
	return dfs(len,0,0,1); 
}
int main()
{
	cin>>T;
	int cnt = 0;
	while(T--){
		cin>>n;
		cout<<"Case "<<(++cnt)<<": ";
		cout<<part(n)<<endl;
	}


	return 0;
}
/*
Sample Input
7
0
6
15
20
21
22
2147483647
Sample Output
Case 1: 0
Case 2: 2
Case 3: 12
Case 4: 13
Case 5: 13
Case 6: 14
Case 7: 16106127360
*/