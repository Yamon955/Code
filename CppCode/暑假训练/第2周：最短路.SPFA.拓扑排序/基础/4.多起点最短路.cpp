//HDU2680
// 思路一：因为有多个起点可以选择，但只有一个终点，所以自己可以再加上一个点作为起点，编号为0，这个点和题中给的那些起点之间的距离为0。
//          这样题目就转化为了求单源最短路径问题。
// 思路二：反向图。把终点作为反向图的起点，题中的起点作为要到达的终点，每条路的起点和终点交换。然后用Dijkstra求单源最短路，
//          记录最小值即可。
//注意此题为单向边（坑）

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1005;
const int M = 20005;
int n,m,s,k;
int vis[N];
int map[N][N],dis[N];
void Dijstra(int st)
{
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i] = map[st][i];
    vis[st] = 1;
    for(int i=1;i<=n;i++){
        int Min=0x3f3f3f3f;
        int k;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && dis[j] > dis[k]+map[k][j]) 
                dis[j] = dis[k]+map[k][j];
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&s)!=EOF){
        memset(map,0x3f,sizeof map);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            map[u][v] = min(map[u][v],w);
        }
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
           int v;
           scanf("%d",&v);
           map[0][v] = 0;
        }
        Dijstra(0);
        if(dis[s]<0x3f3f3f3f) printf("%d\n",dis[s]);
        else printf("-1\n");
    }
    return 0;
}
/*
Sample Input
5 8 5
1 2 2
1 5 3
1 3 4
2 4 7
2 5 6
2 3 5
3 5 1
4 5 1
2
2 3
4 3 4
1 2 3
1 3 4
2 3 2
1
1
Sample Output
1
-1
*/