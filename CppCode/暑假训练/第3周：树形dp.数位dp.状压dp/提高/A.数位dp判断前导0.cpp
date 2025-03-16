//https://vjudge.net/contest/451302

//AtCoder 194F
#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;
const int mod = 1e9+7;
int n,k,len;
int a[N];
ll dp[N][17];
//dp[i][j] 表示当前正在第 i 位，当前已经使用了 j 个不同的数字
int getNum(int x)  //求出 x 的二进制表示中有几个 1
{
	int cnt = 0;
	while(x){
		if(x%2) cnt++;
		x /= 2;
	}
	return cnt;
}
//pos:正在处理第几位  lead:是否有前导0  limit:取值是否有限制
ll dfs(int pos,int used,int lead,int limit)  //used 用来标记已经使用过的数字(二进制表示)，如used = 17,其二进制表示 10001 --->第 0 位和第 4 位为 1，表示数字 0和4 已经使用过来
{
	if(getNum(used)>k) return 0;
	if(pos>len) return getNum(used)==k;
	if(!lead && !limit && dp[pos][getNum(used)]!=-1) return dp[pos][getNum(used)];
	ll ans = 0;
	int up = limit?a[pos]:15;   //16进制每位可能取值范围位 0~15
	for(int i=0;i<=up;i++){
		if(lead && i==0) ans = (ans + dfs(pos+1,used,lead&&(i==0),(i==up)&&limit)) % mod;
		else ans = (ans + dfs(pos+1,used|(1<<i),lead&&(i==0),(i==up)&&limit)) % mod;
	}
	if(!lead && !limit) dp[pos][getNum(used)] = ans;
	return ans;
}
ll part(string s)
{
	memset(dp,-1,sizeof dp);
	len = 0;
	for(int i=0;s[i]!='\0';i++){  // 16进制
		if('0'<=s[i] && s[i]<='9') a[++len] = s[i]-'0';
		else a[++len] = s[i]-'A'+10;
	}
	//for(int i=1;i<=len;i++) cout<<a[i]<<" "<<endl;
	return dfs(1,0,1,1);
}
int main()
{
	string s;
	cin>>s>>k;
	cout<<part(s);
	return 0;
}
/*
Sample Input 1
10 1
Sample Output 1
15
Sample Input 2
FF 2
Sample Output 2
225
Sample Input 3
100 2
Sample Output 3
226
Sample Input 4
1A8FD02 4
Sample Output 4
3784674
Sample Input 5
DEADBEEFDEADBEEEEEEEEF 16
Sample Output 5
153954073
*/