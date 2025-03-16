//LightOJ 1068
//此题 k  的范围是1~10000，但实际上 k 只要大于 81，直接返回 0 即可，因为一个数的范围是 2^31 = 2,147,483,648 ---> 最大为 10 位
//数位和最多也才82（1999999999的情况），所以k>82直接输出0就可以了，然后这样内存还是非常充裕的。.
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
const int MOD = 2520;
int T,len,a[N],k,f[100];
ll l,r;
ll dp[N][85][85];
//dp[i][j][k]：位数为i模K结果为j且各位数之和模K结果为k的数字个数
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
ll dfs(int pos,int mod1,int mod2,int limit)
{
	if(pos==0) return (mod1==0)&&(mod2==0);
	if(!limit && dp[pos][mod1][mod2]!=-1) return dp[pos][mod1][mod2];
	ll ans = 0;
	int up = limit?a[pos]:9;
	for(int i=0;i<=up;i++){
		ans += dfs(pos-1,(mod1*10+i)%k,(mod2+i)%k,(i==up)&&limit);
	} 
	if(!limit) dp[pos][mod1][mod2] = ans;
	return ans;
} 
ll part(ll x)
{
	len = 0;
	memset(dp,-1,sizeof dp);
	while(x){
		a[++len] = x%10;
		x /= 10;
	}
	if(k>82) return 0;
	else return dfs(len,0,0,1); 
}
int main()
{
	scanf("%d",&T);
	int cnt = 0;
	while(T--){   
		cin>>l>>r>>k;
		memset(f,0,sizeof f);
		cout<<"Case "<<(++cnt)<<": ";
		cout<<part(r)-part(l-1)<<endl;
	}
	return 0;
}
/*
Sample Input
3
1 20 1
1 20 2
1 1000 4
Sample Output
Case 1: 20
Case 2: 5
Case 3: 64
*/