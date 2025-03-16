//HDU3790
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1005;
const int M = 100005;
int n,m,st,et;
int vis[N];
int map[N][N],cost[N][N];
void Dijstra(int st)
{
    memset(vis,0,sizeof vis);
    vis[st] = 1;
    for(int i=2;i<=n;i++){
        int Min = 0x3f3f3f3f,Min_cost;
        int k;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > map[st][j]){
                Min = map[st][j];
                Min_cost = cost[st][j];
                k = j;
            }
        }
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && map[st][j] > map[st][k]+map[k][j]){
                map[st][j] = map[st][k]+map[k][j];
                cost[st][j] = cost[st][k]+cost[k][j];
            }
            else if(!vis[j] && map[st][j] == map[st][k]+map[k][j]){  //最短距离相同时更新最小花费
                cost[st][j] = min(cost[st][j],cost[st][k]+cost[k][j]);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        if(m==0 && n==0) break;
        memset(map,0x3f,sizeof map);
        memset(cost,0x3f,sizeof cost);
        for(int i=1;i<=m;i++){
            int a,b,d,p;
            scanf("%d%d%d%d",&a,&b,&d,&p);
            if(map[a][b]>d){
                map[a][b] = map[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }
            else if(map[a][b]==d){
                cost[a][b] = cost[b][a] = min(cost[b][a],p);
            }
        }
        cin>>st>>et;
		Dijstra(st);
        printf("%d %d\n",map[st][et],cost[st][et]);
    }
    return 0;
}
/*
2 2
1 2 5 10
2 1 4 12
1 2
4 12

4 4
1 2 5 6
2 3 4 5
1 4 5 10
4 3 4 2
1 3
9 11

6 7
1 2 5 6
1 3 5 1
2 6 2 1
3 4 1 1
4 2 1 1
4 5 1 1
5 2 3 1
5 6
4 3
*/