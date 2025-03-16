//POJ1201
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
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
        int x,y,w;
        cin>>x>>y>>w;
        y++;
        add(x,y,w);
        Min = min(Min,x);
        Max = max(Max,y);
    }
    for(int i=Max;i>=Min;i--){  //如果从Min开始建边spfa会超时,或者是从Min开始建边但是在入队时所有结点都要入队
//        add(i,i+1,0);
//        add(i+1,i,-1);
        add(i-1,i,0);
        add(i,i-1,-1);
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
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
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
        int x,y,w;
        cin>>x>>y>>w;
        y++;
        add(x,y,w);
        Min = min(Min,x);
        Max = max(Max,y);
    }
    for(int i=Min;i<Max;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    queue<int>q;
    for(int i=Min;i<=Max;i++)  //所有结点全部入队
    	q.push(i);
    memset(vis,1,sizeof vis);
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
*/