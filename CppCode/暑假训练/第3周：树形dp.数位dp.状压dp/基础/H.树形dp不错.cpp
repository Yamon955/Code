//CF1084D
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 3e5+5;
int val[N],n;
struct Edge{
	int to;
	int w;
	int next;
};
Edge edge[N*3];
int h[N],tol,vis[N];
ll dp[N],ans;
void add(int u,int v,int w)
{
	edge[tol].to = v;
	edge[tol].w = w;
	edge[tol].next = h[u];
	h[u] = tol++;
}
void dfs(int u,int fa)
{
	dp[u] = val[u];
	ans = max(ans,dp[u]);
	for(int i=h[u];i!=-1;i=edge[i].next){
		int v = edge[i].to;
		int w = edge[i].w;
		if(v==fa) continue;
		dfs(v,u);
		ans = max(ans,dp[u]+dp[v]-w);
		dp[u] = max(dp[u],dp[v]+val[u]-w);
//首先v是u的子节点，搜索了v之后，就知道了v的信息（往叶节点方向走（注意只是叶节点方向并不一定走到叶节点）得到的最大的那条路dp[v]，以及ans：由v的子树们组成的最长的路）。
//这样就可以用dp[v]来更新ans（此时ans为由u的子树们组成的最长的路 ans=max(ans,dp[u]+dp[v]-val);）与dp[u]（即u往叶节点走的最大路dp[u]=max(dp[u],dp[v]+a[u]-val);）。
//这种非常巧妙的代码是非常棒的！再次膜大佬。
//相当于从 u 出发(如果经过 u 的话，u 就作为了中转点）找到了子树的最大值和次大值

	}
}
int main()
{
	memset(h,-1,sizeof h);
	tol = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<n;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
Input
3
1 3 3
1 2 2
1 3 2
Output
3
Input
5
6 3 2 5 0
1 2 10
2 3 3
2 4 1
1 5 1
Output
7
*/