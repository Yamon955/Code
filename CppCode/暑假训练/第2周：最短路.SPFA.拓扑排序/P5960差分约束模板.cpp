//洛谷P3275
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e3+5;
int n,m;
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[N*2];
int tol,h[N];
int dis[N],vis[N],cnt[N];
void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
bool SPFA(int st)
{
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    // for(int i=0;i<=n;i++){
    //     q.push(i);
    //     vis[i] = 1;
    // }
    q.push(st);
    vis[st] = 1;
    dis[st] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v]>n) return true;
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(v,u,w);
    }
    for(int i=1;i<=n;i++) add(0,i,0);
    if(SPFA(0)) cout<<"NO"<<endl;
    else{
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
    }
    return 0;
}