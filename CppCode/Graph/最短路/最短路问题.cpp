//AC wing--849
#include<iostream>
#include<cstdio>
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
int map[510][510];
int S[510],dis[510];
void Dijkstra(int x)
{
    for(int i=1;i<=n;i++){
         dis[i]=map[x][i];
    }
    dis[x]=INF;
    S[x]=1;
    for(int j=1;j<=n-1;j++){
        int u;
        int Min=INF;
        for(int i=1;i<=n;i++){
            if(dis[i]<=Min&&S[i]==0){
                 Min=dis[i];
                 u=i;
            }
        }
        S[u]=1;
        for(int k=1;k<=n;k++){
            if(dis[k]>Min+map[u][k]&&S[k]==0){
                dis[k]=Min+map[u][k];
            } 
        }
    }
    

}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) map[i][j]=INF;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a][b]=min(map[a][b],c);
    }
    Dijkstra(1);
    if(dis[n]>=INF) cout<<"-1"<<endl;
    else cout<<dis[n]<<endl;
    return 0;
}