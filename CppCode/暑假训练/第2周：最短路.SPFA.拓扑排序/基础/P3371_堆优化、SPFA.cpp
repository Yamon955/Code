//https://www.luogu.com.cn/problem/P3371
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 5e5+50,M=1e9+7;

int n,m,s;
int dis[N],vis[N];
typedef struct point{
	int v,w;
	bool operator<(const point &a)const{
		return w > a.w;
	}
}Po;
priority_queue<point>q;
typedef struct node{
	int to;
	int w;
	int ne;
}Edge;
Edge no[N];
int h[N];
int tol = 1;

void add(int u,int v,int w)
{
	no[tol].to = v;
	no[tol].w = w;
	no[tol].ne = h[u];
	h[u] = tol++;
}
void dij(int st)
{
	dis[st] = 0;
	for(int i=1;i<=n;i++){
		int Min = inf;
		int k = -1;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j] < Min){
				Min = dis[j];
				k = j;
			}
		}
		if(k == -1) break;
		vis[k] = 1;
		for(int i=h[k];i!=-1;i=no[i].ne){
			int v = no[i].to;
			int w = no[i].w;
			if(vis[v]==0 && dis[v] > dis[k]+w)
				dis[v] = dis[k]+w;
		}
	}
}
void dij_2(int st)  //堆优化 
{
	dis[st] = 0;
//	point start;
//	start.v = st;
//	start.w = 0;
//	q.push(start);
	q.push(point{st,0});
	while(!q.empty()){
		int k = q.top().v;
		q.pop();
		if(vis[k]) continue;
		vis[k] = 1;
		for(int i=h[k];i!=-1;i=no[i].ne){
			int v = no[i].to;
			int w = no[i].w;
			if(!vis[v] && dis[v] > dis[k]+w){
				dis[v] = dis[k]+w;
//				point tmp;
//				tmp.v = v;
//				tmp.w = dis[v];
//				q.push(tmp);
				q.push(point{v,dis[v]});
			}
		}
	}
 } 

void spfa(int st)
{
	queue<int>qq;
	dis[st] = 0;
	vis[st] = 1;
	qq.push(st);
	while(!qq.empty()){
		int k = qq.front();
		qq.pop();
		vis[k] = 0;
		for(int i=h[k];i!=-1;i=no[i].ne){
			int v = no[i].to;
			int w = no[i].w;
			if(dis[v] > dis[k]+w){
				dis[v] = dis[k]+w;
				if(!vis[v]) {
					qq.push(v);
					vis[v] = 1;
				}
			}
		}
	}
 } 
int main()
{
	cin>>n>>m>>s;
	mem(dis,0x3f);
	mem(vis,0);
	mem(h,-1);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
//	dij(s);
//	dij_2(s); 
	spfa(s);
	for(int i=1;i<=n;i++){
		if(dis[i] < inf) cout<<dis[i]<<" ";
		else cout<<(ll)pow(2,31)-1<<" ";
	}
	
	
}