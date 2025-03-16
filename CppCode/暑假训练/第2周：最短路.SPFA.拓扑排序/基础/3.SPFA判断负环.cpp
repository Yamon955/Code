//POJ3259
//SPFA算法是求单源最短路径的一种算法，它是Bellman-ford的队列优化，它是一种十分高效的最短路算法。
//但是，SPFA算法稳定性较差，在稠密图中SPFA算法时间复杂度会退化。

// 实现方法：建立一个队列，初始时队列里只有起始点，在建立一个表格记录起始点到所有点的最短路径（该表格的初始值要赋为极大值，该点
//     到他本身的路径赋为0）。然后执行松弛操作，用队列里有的点去刷新起始点到所有点的最短路，如果刷新成功且被刷新点不在队列中则
//     把该点加入到队列最后。重复执行直到队列为空。

// SPFA判负环
// ⚫ 任一节点进队次数大于等于总结点数，则说明存在负环
// ⚫ 统计当前每个点的最短路所包含的边数，如果该值 >= 点数，则说明存在负环

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int Maxe = 2710;
const int Maxn = 510;
const int INF = 0x3f3f3f3f;
int T,n,m,k;
int map[Maxn][Maxn];
int vis[Maxn],cnt[Maxn],dis[Maxn];
bool SPFA_1(int st)  //通过最短路径包含的边的条数大于等于 n 来判断是否存在负环
{
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    q.push(st);
    vis[st] = 1;
    dis[st] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=1;i<=n;i++){
            if(dis[i]>dis[u]+map[u][i]){
                dis[i] = dis[u]+map[u][i];
                cnt[i] = cnt[u]+1;
                if(cnt[i]>=n) return true; //存在负环
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
    return false;//没有负环
}
bool SPFA_2(int st)  //通过任一节点进队次数大于总结点数来判断是否存在负环
{
    memset(vis,0,sizeof vis); //用来记录结点是否在队列中
    memset(cnt,0,sizeof cnt); //cnt[]用来存储每个结点的进队次数
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    //for(int i=1;i<=n;i++) q.push(i);
    q.push(st);
    vis[st] = 1;
    dis[st] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for(int i=1;i<=n;i++){
            if(dis[i] > dis[v]+map[v][i]){
                dis[i] = dis[v]+map[v][i];
                if(!vis[i]){   //如果已经在队列中就没有必要加入了
                    q.push(i);
                    vis[i] = 1;
                    if(++cnt[i] > n) return true;//存在负环
                }
            }
        }
    }
    return false;//没有负环
}
int main()
{
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        memset(map,0x3f,sizeof map);
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            map[u][v] = map[v][u] = min(map[v][u],w);
        }
        for(int i=1;i<=k;i++){
            int u,v,w;
            cin>>u>>v>>w;
            map[u][v] = -w;
        }
        if(SPFA_1(1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
Sample Input
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
Sample Output
NO
YES
*/