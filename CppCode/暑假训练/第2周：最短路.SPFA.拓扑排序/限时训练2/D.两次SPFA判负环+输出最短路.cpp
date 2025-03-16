//VijOs P1053
//此题要跑两边spfa
//第一遍判断有没有环，因为图可能是不连通的，所以可能存在与起点不连通的环，因此要把每个结点都当做起点都跑一遍spfa确定图中是否有环，但太麻烦
//优化一：设置一个 v[] 数组，从起点开始，只要起点能到达点s则v[s]=1,然后把v[]=0的一个点当作起点继续跑spfa,这样只需要跑图中有几个连通图就跑几次
//优化二：建立一个源点 0,并且建立从源点 0 到其他点的权值为0的单向边，这样原图就变为了连通图，只需要跑一遍spfa(0)就可以判断有没有环

//第二遍就跑出来最短路即可
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
int n,m,s;
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[N*N];
int h[N],tol,vis[N],cnt[N];
ll dis[N],ans[N];
void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
bool spfa(int st)
{
    for(int i=1;i<=n;i++) dis[i] = inf;
    memset(vis,0,sizeof vis); //结点是否在队中
    memset(cnt,0,sizeof cnt); //入队次数
    queue<int>q;
    dis[st] = 0; 
    q.push(st);
    vis[st] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;  //出队置 0 
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                if(!vis[v]){ //如果v不在队列中
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v] > n) return true;//存在负环
                    vis[v] = 1;
                }
            }
        }
    }
    return false;//没有负环
}
int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w); //单向
    }
    for(int i=1;i<=n;i++) add(0,i,0); //建一个源点 0，0到其他点的距离都是0，且都是单向边，因此加上这些边后对接下来求spfa(s)求最短路没有影响
    if(spfa(0)) cout<<"-1"<<endl;
    else{
        if(spfa(s)) {
            cout<<"-1"<<endl;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(dis[i]>=inf) cout<<"NoPath"<<endl;
            else cout<<dis[i]<<endl;
        }
    }
    return 0;
}
/*
输入数据：
6 8 1
1 3 4
1 2 6
3 4 -7
6 4 2
2 4 5
3 6 3
4 5 1
3 5 4

输出：
0
6
4
-3
-2
7
*/