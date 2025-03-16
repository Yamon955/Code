//洛谷P3275
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int n,k;
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[N*5];
int tol,h[N];
void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
int dis[N],vis[N],cnt[N];
bool spfa(int st)
{
    queue<int>q;
    for(int i=0;i<=n;i++){
        q.push(i);
        vis[i] =1;
    }
    dis[st] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v] < dis[u]+w){  //最长路
                dis[v] = dis[u]+w;
                cnt[v] = cnt[u]+1;
                if(cnt[v]>n) return true;  //存在正环
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    memset(h,-1,sizeof h);//链式前向星一定不要忘记初始化所有头节点为-1
    memset(dis,0xf3,sizeof dis);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);
        if(x==1) {
            add(a,b,0);
            add(b,a,0);
        }
        else if(x==2) add(a,b,1);
        else if(x==3) add(b,a,0);
        else if(x==4) add(b,a,1);
        else if(x==5) add(a,b,0);
        if(x%2==0 && a==b) {  //对a->a的正环剪枝，不剪枝最后一个测试点会TLE
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++) add(0,i,1); //建立一个虚拟源点 0，因为每个小朋友都要分到糖果，故建立从源点0到其他顶点的单向边，权值为1
    if(spfa(0)) cout<<"-1";
    else{
        long long ans = 0;
        for(int i=1;i<=n;i++) ans+=dis[i];
        cout<<ans<<endl;
    }
    
    return 0;
}
/*
5 7
1 1 2
2 3 2
4 4 1
3 4 5
5 4 5
2 3 5
4 5 1
--->11
*/
