//CodeForces 1294F

#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
int n;
vector<int>p[200005];
int vis[200005];
int dis1[200005],dis2[200005],dis3[200005];
int x,y,z,Max;
void dfs(int idx,int step,int dis[])
{
	dis[idx] = step;
	for(int i=0;i<p[idx].size();i++){
        // if(vis[p[idx][i]]==1) continue;
        // vis[p[idx][i]]=1;
        // dfs(p[idx][i],step+1,dis);
		if(vis[p[idx][i]]==0){
			vis[p[idx][i]]=1;
			dfs(p[idx][i],step+1,dis);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	dfs(1,0,dis1);
	Max = 0;
	for(int i=1;i<=n;i++){
		if(Max < dis1[i]){
			Max = dis1[i];
			x = i;
		}
	}
	memset(vis,0,sizeof vis);
	vis[x] = 1;
	dfs(x,0,dis2);
	Max = 0;
	for(int i=1;i<=n;i++){
		if(Max < dis2[i]){
			Max = dis2[i];
			y = i;
		}
	}
	memset(vis,0,sizeof vis);
	vis[y] = 1;
	dfs(y,0,dis3);
	Max = 0;
	for(int i=1;i<=n;i++){
		if(i==x || i==y) continue;
		if(dis2[i]+dis3[i]>Max){
			Max = dis2[i]+dis3[i];
			z = i;
		}
	}
	cout<<(Max+dis2[y])/2<<endl;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		if(i==x || i==y || i==z) vis[i] = 1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]) cout<<i<<" ";
	return 0;
	
}
/*
Example
Input
8
1 3
3 4
3 2
2 6
2 5
2 7
7 8
Output
5
4 6 8
Note
样例也可以选择1,4,8这三个点。
两两之间的三条最短路径经过的五条边为
1-3
3-4
3-2
2-7
7-8
*/