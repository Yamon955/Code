//POJ3268
// 最短路径只需要从x到i的最短路径代表他们返回的最短路径，然后将所有边反过来，再从x到i的最短路径代表他们来参加聚会的最短路径，
// 这样对应相加找出一个最大值就可以了，当然其实不需要将所有边反过来，只需要将map的行和列对换一下就可以了，数据比较大，所以floyd超时
// ，用dijkstra比较好点

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
int n,m,x;

int vis[N],dis1[N],dis2[N],map[N][N],mapp[N][N];
void Dijstra(int st,int dis[],int map[][N])
{
    memset(vis,0,sizeof vis);
    //memset(dis,0x3f,sizeof dis); //不能在这里初始化，如果只在这里初始化和在调用函数之前初始化dis1[],dis2[]结果不一样
    dis[st] = 0;
    for(int i=1;i<=n;i++){
        int Min = inf,k=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && dis[j]>dis[k]+map[k][j]){
                dis[j] = dis[k]+map[k][j];
            }
        }
    }
}
int main()
{
    memset(map,0x3f,sizeof map);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v] = w;
    }
    memset(dis1,0x3f,sizeof dis1);
    Dijstra(x,dis1,map);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) mapp[i][j] = map[j][i];  //反向建边
    }
    memset(dis2,0x3f,sizeof dis2);
    Dijstra(x,dis2,mapp);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dis1[i]<inf && dis2[i]<inf){
            ans = max(ans,dis1[i]+dis2[i]);
        }
    }
    printf("%d",ans);
    return 0;
}
/*
Sample Input
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
Sample Output
10
*/