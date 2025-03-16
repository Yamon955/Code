//prim算法  O(n^2)

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n,m,w,ans;
int map[55][55];
int dis[55],vis[55];
int main()
{
    while(1){
        cin>>n;
        if(n==0) break;
        cin>>m;
        memset(map,0x3f,sizeof(map));
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        int ans = 0;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            map[u][v] = min(map[u][v],w);
            map[v][u] = min(map[v][u],w);
        }
        dis[1] = 0;
        for(int i=1;i<=n;i++){
            int Min = 500,k;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&dis[j]<Min){
                    Min = dis[j];
                    k = j;
                }
            }
            vis[k] = 1;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&dis[j]>map[k][j]) dis[j] = map[k][j];
            }
        }
        for(int i=1;i<=n;i++) ans += dis[i];
        cout<<ans<<endl;
    }
    return 0;
}