//题目要求 旅行商从 1 号节点开始出发
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int map[100][100];
int vis[100];
int best=0x3f3f3f3f;
int tmp[100],ans[100];
void TSP(int x,int sum)
{
    if(x>=n){
        if(map[x-1][1]==0) return;
        else if(best>sum+map[tmp[x]][1]){
            best = sum+map[tmp[x]][1];
            for(int i=1;i<=n;i++){
                ans[i] = tmp[i];
            }
            ans[n+1] = 1;
        }
        return;
    }
    for(int i=2;i<=n;i++){
        if(map[x][i]&&vis[i]==0){
            tmp[x+1] = i;
            vis[i] = 1;
            TSP(x+1,sum+map[x][i]);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v] = map[v][u] = w;
    }
    tmp[1] = 1;
    vis[1] = 1;
    TSP(1,0);
    cout<<best<<endl;
    for(int i=1;i<=n+1;i++) cout<<ans[i]<<" ";
    return 0;
}
/*
Simple input：
3 3
1 2 2
1 3 4
2 3 10
Simple output：
16
1 2 3 1

*/