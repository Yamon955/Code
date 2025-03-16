//CodeForces 295B
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 505;
ll dis[N][N],ans[N];
int x[N],vis[N];
int n;
void Floyed()
{
    for(int k=n;k>=1;k--){ //不断往图中加入点，并更新最短路
        vis[x[k]] = 1; //用来记录当前点是否在图中
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][x[k]]+dis[x[k]][j]);
            }
        }
        ll tmp = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) 
                if(vis[i] && vis[j]) tmp += dis[i][j];
        }
        ans[k] = tmp;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>dis[i][j];
    }
    for(int i=1;i<=n;i++) cin>>x[i];
    Floyed();
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
    
}


