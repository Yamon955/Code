//POJ2983
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
const int M = 1e5+5;
int n,m;
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[M*3];
int h[N],tol,vis[N],dis[N],cnt[N];
void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
bool spfa()
{
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    queue<int>q;
    for(int i=1;i<=n;i++) {
        q.push(i);
        vis[i] = 1;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v] < dis[u]+w){
                dis[v] = dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v]>=n) return true;
                    vis[v] = 1;
                }
            }
        }
    }
    return false;

}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(h,-1,sizeof h);
        tol = 0;
        for(int i=1;i<=m;i++){
            int u,v,w;
            char op[5];
            scanf("%s",op);
            if(*op=='P'){
                scanf("%d%d%d",&u,&v,&w);  
                add(u,v,-w);
                add(v,u,w);
            }
            else{
                scanf("%d%d",&u,&v);
                cin>>u>>v;
                add(v,u,1);
            }
        }
        if(spfa()) cout<<"Unreliable"<<endl;
        else cout<<"Reliable"<<endl;
    }
    return 0;
}
