#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n,m,w;
int map[105][105];
int dis[105],vis[105];
int main()
{
    while(1){
        cin>>n;
        m = n*(n-1)/2;
        if(n==0) break;
        memset(dis,0x3f,sizeof dis);
        memset(vis,0,sizeof vis);
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            map[u][v] = map[v][u] = w;
        }
        dis[1] = 0;
        for(int i=1;i<=n;i++){
            int Min = 1e9,k;
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
        int ans = 0;
        for(int i=1;i<=n;i++) ans += dis[i];
        cout<<ans<<endl;
    }
    return 0;
}