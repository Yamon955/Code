//POJ1716
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e4+5;
int n;
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[N*5];
int h[N],tol,dis[N],vis[N];
void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    memset(dis,-0x3f,sizeof dis);
    int Min = inf,Max = 0;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        y++;
        add(x,y,2);      //y-x>=2
        Min = min(Min,x);
        Max = max(Max,y);
    }
    for(int i=Min;i<Max;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    queue<int>q;
    q.push(Min);
    vis[Min] = 1;
    dis[Min] = 0;
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
                    vis[v] = 1;
                }
            }
        }
    }
    cout<<dis[Max]<<endl;
    return 0;
}