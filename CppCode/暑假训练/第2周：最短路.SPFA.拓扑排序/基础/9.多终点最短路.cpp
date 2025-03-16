//ACwing 1135
// 预处理dis数组，表示出结点1以及结点abcde两两之间的距离。用dfs枚举所有可能的走法。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
const int M = 1e5+5;
int n,m;
int End[10],dis[10][N],vis[N];
int ans = inf;
typedef struct node{
    int to;
    int w;
    int next;
}Edge;
Edge edge[2*M]; //一定是 2*M 
int tol,h[N];

void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
void Dijstra(int idx) //idx为起点下标   //堆优化的Dijstra
{
    int st = End[idx];//起点
    memset(vis,0,sizeof vis);
    memset(dis[idx],0x3f,sizeof dis[idx]);
    priority_queue<pii,vector<pii>,greater<pii> >q;  //小根堆
    dis[idx][st] = 0;
    q.push(make_pair(0,st));
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        for(int i=h[v];i!=-1;i=edge[i].next){
            int to = edge[i].to;
            int w = edge[i].w;
            if(!vis[to] && dis[idx][to] > dis[idx][v]+w)
                dis[idx][to] = dis[idx][v]+w; 
                q.push(make_pair(dis[idx][to],to));  
        }
    }
}
void dfs(int cnt,int idx,int step)  //idx为下标
{
    if(cnt==5){
        ans = min(ans,step);
        return;
    }
    for(int i=2;i<=6;i++){  //全排列
        if(!vis[End[i]]){
            vis[End[i]] = 1;
            dfs(cnt+1,i,step+dis[idx][End[i]]);
            vis[End[i]] = 0;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=6;i++){
        scanf("%d",&End[i]);
    }
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    End[1] = 1;
    for(int i=1;i<=6;i++){
        Dijstra(i);
    }
    memset(vis,0,sizeof vis);
    dfs(0,1,0);
    printf("%d\n",ans);
    return 0;

}
/*
6 6
2 3 4 5 6
1 2 8
2 3 3
3 4 4
4 5 5
5 6 2
1 6 7
--->21
*/