//POJ3249
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
const int M = 1e6+5;
int n,m;
int vis[N],w[N];
ll dis[N],dp[N];
struct Edge{
    int to;
    int next;
};
Edge edge[M*2];
int h[N],tol;
int in[N];//入度
int out[N];//出度
void add(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = h[u];
    h[u] = tol++;
}
void topsort() 
{
   queue<int>q;
   for(int i=1;i<=n;i++) dp[i] = -inf;
   for(int i=1;i<=n;i++){
       if(in[i]==0) {
           q.push(i);
           dp[i] = w[i];
       }
   }
   while(!q.empty()){
       int u = q.front();
       q.pop();
       for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            dp[v] = max(dp[v],dp[u]+w[v]);
            in[v]--;
            if(in[v]==0){
               q.push(v);
            }
       }
   }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(h,-1,sizeof h);
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        tol = 0;
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            in[v]++;
            out[u]++;
        }
        ll ans = -inf;
        topsort();
        for(int i=1;i<=n;i++)
            if(out[i]==0)
                ans = max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
6 5
1
2
2
3
3
4
1 2
1 3
2 4
3 4
5 6
Sample Output
7
*/