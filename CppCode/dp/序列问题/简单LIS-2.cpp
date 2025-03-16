//HDU-1160
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
int dp[N],pre[N],ss[N];
struct node{
	int w;
	int v;
	int idx;
}; 
node Ns[N];
bool cmp(node a,node b)
{
	return a.w < b.w || (a.w == b.w && a.v > b.v);
}

void print(int st)
{
	if(st == 0) return;
	print(pre[st]);
	cout<<Ns[st].idx<<endl;
}
int main()
{
	int cnt = 0;
	int w,v;
	while(scanf("%d%d",&w,&v)!=EOF){
		cnt ++;
		Ns[cnt].w = w;
		Ns[cnt].v = v;
		Ns[cnt].idx = cnt;
	}
	sort(Ns+1,Ns+cnt+1,cmp);
	mem(pre,0);
	int ans = 0;
	int idx;
	for(int i=1;i<=cnt;i++){
		dp[i] = 1;
		for(int j=1;j<i;j++){
			if(Ns[i].w > Ns[j].w && Ns[i].v < Ns[j].v){
				if(dp[i] < dp[j]+1) {
					dp[i] = dp[j]+1;
					pre[i] = j;
				}
			}
		}
		if(dp[i] > ans){
			ans = dp[i];
			idx = i;
		}
	}
	cout<<ans<<endl;
	int len = 0;
	while(idx != 0){
		ss[++len] = Ns[idx].idx;
		idx = pre[idx];
	}
	for(int i=len;i>=1;i--) cout<<ss[i]<<endl;
	return 0;
	
}
/*
Sample Input
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
Sample Output
4
4
5
9
7
*/