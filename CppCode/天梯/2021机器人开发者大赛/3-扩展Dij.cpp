#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#include<map>
#include<utility>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
int n,m,k;
int a[N];
struct node{
    int u,v;
    int w;
    int val;
};
node f[N][N];
int dis[N],vis[N];
int pre[N];
int ex[N];
int p[N],cnt;
void Dijstra(int st)  //堆优化 
{
	priority_queue<pair<int,int> >q;
	mem(dis,0x3f);
	mem(vis,0);
	dis[st] = 0;
	q.push(make_pair(-dis[st],st));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=1;i<=n;i++){
			if(!vis[i] && dis[i] > dis[u] + f[u][i].w){
				dis[i] = dis[u] + f[u][i].w;
				q.push(make_pair(-dis[i],i));
			}
		}
	}
}
void Dij(int st)  //朴素版会 TLE
{
    mem(dis,0x3f);
    mem(vis,0);
    dis[st] = 0;
    for(int i=1;i<=n;i++){
        int Min = inf,k=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && dis[j] > dis[k]+f[k][j].w){
                dis[j] = dis[k] + f[k][j].w;
            }
        }
    }
}
void Dij_2(int st)   //多限制 Dij
{
    mem(dis,0x3f);
    mem(vis,0);
    dis[st] = 0;
	pre[st] = -1;
    for(int i=1;i<=n;i++){
        int Min = inf,k=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
				if(dis[j] > dis[k]+f[k][j].w){
					dis[j] = dis[k] + f[k][j].w;
					pre[j] = k;
					ex[j] = ex[k]+f[k][j].val;
				}
				else if(dis[j] == dis[k]+f[k][j].w){
					if(ex[j] < ex[k]+f[k][j].val){
						ex[j] = ex[k]+f[k][j].val;
						pre[j] = k;
					}
				}
                
            }
        }
    }
}
void print(int x)
{
	if(pre[x] == -1){
		return;
	}
	print(pre[x]);
	p[cnt++] = x;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j].w = inf;
            f[i][j].val = 0;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w,val;
        cin>>u>>v>>w>>val;
        f[u][v].w = f[v][u].w = w;
        f[u][v].val = f[v][u].val = val; 
    }
    cin>>k;
    for(int i=1;i<=k;i++) cin>>a[i];
    int Min = inf,st;
    for(int i=1;i<=n;i++){
        Dijstra(i);  //跑 n 次 Dij 找出每次最大的 dis[j] 中的最小值
        int Max = 0;
        for(int j=1;j<=n;j++){
            if(Max < dis[j]){
                Max = dis[j];
            }
        }
        if(Min > Max){
            Min = Max;
            st = i;
        }
    }
    cout<<st<<endl;
	Dij_2(st);
	for(int i=1;i<=k;i++){
		cout<<st;
		cnt = 0;
		print(a[i]);
		for(int j=0;j<cnt;j++) cout<<"->"<<p[j];
		cout<<endl;
		cout<<dis[a[i]]<<" "<<ex[a[i]]<<endl;
	}

}
/*
输入样例:
6 12
1 2 10 5
2 3 16 20
3 1 4 2
2 4 20 22
4 5 2 2
5 3 12 6
4 6 8 5
6 5 10 5
6 1 20 25
1 5 8 5
2 5 2 1
2 6 8 5
4
2 3 6 5
输出样例:
5
5->2
2 1
5->1->3
12 7
5->4->6
10 7
5
0 0
*/
