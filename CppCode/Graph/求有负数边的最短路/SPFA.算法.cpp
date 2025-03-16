/*
洛谷P3385判断负环
// SPFA判负环
// ⚫ 任一节点进队次数大于等于总结点数，则说明存在负环
// ⚫ 统计当前每个点的最短路所包含的边数，如果该值 >= 点数，则说明存在负环


AC wing---851
注意：在负权图上使用该算法，在正权图上不要使用
当题目存在边权为负数的情况时考虑两种算法-->Bellman_ford算法和SPFA算法
正负权边都能用SPFA算法
SPFA算法O(m)-O(nm)
    dist[b]>dist[a]+w
流程(类似与bfs){
    1.创建一个不存在重复元素的队列q
    2.起点入队
    while(q不空){
        t<--q
        用t更新其他点{
            如果点i的dist被更新，并且队列中没有i，则点i入队
        }
    }
}
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N = 2e3+5;
const int M = 3e3+5;
int T,n,m;
int map[N][N];
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[M*2]; //别忘了乘以二
int tol;//记录边的条数  实际是给每一条边编号
int h[N];
void add(int u,int v,int w){ //链式前向星
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}

// 任一节点进队次数大于等于总结点数，则说明存在负环
bool SPFA_n(int st)
{
    int vis[N],dis[N],cnt[N];
    memset(vis,0,sizeof vis);    //记录当前结点是否在队列里面
    memset(cnt,0,sizeof cnt);    //记录每个结点的入队次数
    memset(dis,0x3f,sizeof dis); //记录st到其他结点最短距离
    queue<int>q;
    //for(int i=1;i<=n;i++) q.push(i);   //初始入队所有点，因为负环不一定从开始结点出现
    //例如一个图3个结点123，两条单向边(2->3)=-2,(3->2)=-2,此图存在负环，但是如果开始结点为 1，只把结点 1 入队的话结果为没有负环，但是可能存在开始结点1不能到达的负环(不连通)
    //因此针对于这样的题 要先把所有结点入队 ---->参考例题 ACwing 852
    //对于本道题来说题目要求求出从开始结点1出发能到达的负环，因此只需要将 1 入队即可
    q.push(st);
    dis[st] = 0;
    vis[st] = 1;
    cnt[st] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=h[u];i!=-1;i=edge[i].next){ // i 实际上是每一条边的编号
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;  //松弛操作
                if(!vis[v]){
                    q.push(v);
                    cnt[v]++;//注意就是这个位置的判断。一定要保证在判vis之后，即判入队次数；而不是在判vis之前，即判松弛次数！！！
                    if(cnt[v] >= n) return true;  //存在负环
                    vis[v] = 1;
                }
            }
        }
    }
    return false; //无负环
}

// 统计当前每个点的最短路所包含的边数，如果该值 >= 点数，则说明存在负环(效率更高)
bool SPFA_e(int st)
{
    int vis[N],dis[N],cnt[N];
    memset(vis,0,sizeof vis);    //记录当前结点是否在队列里面
    memset(cnt,0,sizeof cnt);    //记录st到其他结点的最短路径包含的边的条数
    memset(dis,0x3f,sizeof dis); //记录st到其他结点最短距离
    queue<int>q;
    //for(int i=1;i<=n;i++) q.push(i);
    q.push(st);
    dis[st] = 0;
    vis[st] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=h[u];i!=-1;i=edge[i].next){ // i 实际上是每一条边的编号
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;  //松弛操作
                cnt[v] = cnt[u]+1;
                if(cnt[v] >= n) return true;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false; //无负环
}
int main()
{
    cin>>T;
    while(T--){
        memset(map,0x3f,sizeof map);
        memset(h,-1,sizeof h);
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(w>=0) {
                add(u,v,w);
                add(v,u,w);
            }
            else add(u,v,w);
        }
        if(SPFA_e(1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}