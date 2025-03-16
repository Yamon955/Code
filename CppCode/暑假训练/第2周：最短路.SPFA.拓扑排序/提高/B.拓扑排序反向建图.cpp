//HDU4857
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 3e4+5;
const int M = 1e5+5;
int T,n,m;
priority_queue<int>q;
int d[N],ans[N];
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[M*5];
int h[N],tol;
void add(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = h[u];
    h[u] = tol++;
}
void Targrt()
{
    int cnt = 0;
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++){
        if(d[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.top();
        ans[++cnt] = u;
        q.pop();
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            d[v]--;
            if(d[v]==0){ 
                q.push(v);
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        tol = 0;
        memset(h,-1,sizeof h);
        memset(d,0,sizeof d);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(v,u);
            d[u]++;
        }
        Targrt();
        for(int i=n;i>=2;i--) printf("%d ",ans[i]);
        printf("%d\n",ans[1]);
    }
    return 0;
}
/*
Sample Input
1
5 10
3 5
1 4
2 5
1 2
3 4
1 4
2 3
1 5
3 5
1 2
Sample Output
1 2 3 4 5


1
5 4
1 4
4 2
5 3
3 2
-->1 5 3 4 2
*/