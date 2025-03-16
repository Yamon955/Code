//https://vjudge.net/contest/450548
//最短路 ，SPFA,拓扑排序


//HDU2544
//用堆优化Dijstra----O(nlogn)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int Maxe = 1e4+5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int n,m;
int vis[105],dis[105];
priority_queue<pair<int,int> >q; // 关于prir中第一个元素值的大根堆
typedef struct node{
    int to; //记录该边的终点
    int w;  //记录改边的权值
    int ne; 
}Edge;
Edge edge[Maxe];
int h[Maxe];//头节点，全都初始化为 -1，每个 h 都指向该链的最后一条边的编号
int tol = 1;//记录边的条数
void add(int u,int v,int w)  //链式前向星--->即邻接表存储图
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].ne = h[u];  
    h[u] = tol++; //头插法
}
void Dijstra(int st)
{
    //vis[st] = 1;  //这里一定不能将起点设置为已访问,否则起点出栈就直接结束了
    dis[st] = 0;
    q.push(make_pair(-dis[st],st));
    while(!q.empty()){
        int k = q.top().second;// 取出当前已经确定的最短距离的点
        q.pop();
        if(vis[k]) continue;  // 如果已经被标记过，说明当前的点的边是比较长的重边，直接跳过。
        vis[k] = 1;
        for(int j=h[k];j!=-1;j=edge[j].ne){
            int v = edge[j].to;
            int w = edge[j].w;
            if(!vis[v] && dis[v] > dis[k]+w){
                dis[v] = dis[k]+w;
                q.push(make_pair(-dis[v],v)); //这里一定是插入负的权值，以最终实现在大根堆中优先输出权值最小的边
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        if(m==0 && n==0) break;
        tol = 1;
        memset(h,-1,sizeof h);
        memset(vis,0,sizeof vis);
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        Dijstra(1);
        printf("%d\n",dis[n]);
    }
    return 0;
}
/*
Sample Input
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
Sample Output
3
2
*/