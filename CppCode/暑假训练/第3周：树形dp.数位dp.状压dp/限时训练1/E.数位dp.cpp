//LightOJ 1140
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
const int N = 12;
ll m,n;  //这里一定要开 long long 因为题目的范围是 32位无符号数
int T,a[N],len;
int dp[N][N];
ll dfs(int pos,int num,int lead,int limit)
{
	if(pos==0) return num;
	if(!lead && !limit && dp[pos][num]!=-1)
		return dp[pos][num];
	ll ans = 0;
	int up = limit?a[pos]:9;
	for(int i=0;i<=up;i++){
		if(lead && i==0) ans += dfs(pos-1,num,lead,(i==up)&&limit);
		else ans += dfs(pos-1,(i==0)?(num+1):num,0,(i==up)&&limit);
	}
	if(!lead && !limit) dp[pos][num] = ans;
	return ans;
}
ll part(ll x)  //统计的是从 1~x 含有的 0 的个数
{
	len = 0;
	while(x){
		a[++len] = x%10;
		x /= 10;
	}
	return dfs(len,0,1,1);
}
int main()
{
	cin>>T;
	int cnt = 0;
	while(T--){
		cin>>m>>n;
		memset(dp,-1,sizeof dp);
        if(m==0) //如果从 0 开始的话最后要加上 1，因为并没有part()并没有包括 0 本身
		    cout<<"Case "<<(++cnt)<<": "<<part(n)-part(m)+1<<endl;
        else cout<<"Case "<<(++cnt)<<": "<<part(n)-part(m-1)<<endl;
	}


	return 0;
}
/*
Sample Input
5
10 11
0 217
123 114514
0 19260817
233 233333333
Sample Output
Case 1: 1
Case 2: 42
Case 3: 55279
Case 4: 12523980
Case 5: 182962920
*/