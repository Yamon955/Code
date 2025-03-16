//POJ1062
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int N = 105;
int m,n;
int L[N];
int map[N][N];  
int vis[N],dis[N],Price[N];
void Dijstra(int st)
{
    memset(dis,0x3f,sizeof dis);
    dis[st] = 0;
    vis[st] = 1;
    for(int i=2;i<=n;i++) 
        if(!vis[i])
            dis[i] = map[1][i];
    for(int i=1;i<=n;i++){
        int Min = 0x3f3f3f3f;
        int k = -1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && dis[j] < Min){
                Min = dis[j];
                k = j;
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && dis[j]>dis[k]+map[k][j])
                dis[j] = dis[k]+map[k][j];
        }
    }
}
int main()
{
    memset(map,0x3f,sizeof map);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        int p,l,x;
        cin>>p>>l>>x;
        Price[i] = p;
        L[i] = l;
        for(int j=1;j<=x;j++){
            int t,v;
            cin>>t>>v;
            map[i][t] = v;
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i= 0;i<=m;i++){
        memset(vis,0,sizeof vis);
        for(int j=2;j<=n;j++){
            if(L[j] < L[1]-m+i || L[j] > L[1]+i)
                vis[j] = 1;
        }
        Dijstra(1);
        for(int j=1;j<=n;j++){
            ans = min(ans,dis[j]+Price[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
Sample Input
1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 2 1
4 200
50 2 0
Sample Output
5250
*/