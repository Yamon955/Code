//https://vjudge.net/contest/450548
//HDU2544
//用链式前向星实现Dijstra----O(n^2)
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
    vis[st] = 1;
    dis[st] = 0;
    for(int i=h[st];i!=-1;i=edge[i].ne){
        dis[edge[i].to] = edge[i].w;
    }
    for(int i=1;i<n;i++){ //循环找 n-1 次
        int Min = INF;
        int k;
        for(int j=2;j<=n;j++){  //从剩下的n-1个点中每次选取距离最近的一个
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(int j=h[k];j!=-1;j=edge[j].ne){
            if(!vis[edge[j].to] && dis[edge[j].to] > dis[k]+edge[j].w){
                dis[edge[j].to] = dis[k]+edge[j].w;
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