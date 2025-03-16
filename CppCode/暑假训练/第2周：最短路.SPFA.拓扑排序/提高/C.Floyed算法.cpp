//HDU1869
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
int n,m;
int map[N][N];
int dis[N][N];
void Floyed()
{
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(map,0x3f,sizeof map);
        for(int i=0;i<=n;i++) map[i][i] = 0;
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            map[u][v] = map[v][u]=1;
        }
        Floyed();
        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<map[i][j]<<"  ";
                if(map[i][j]>7){
                    flag = 1;
                    break;
                }
            }
            //cout<<endl;
        }
        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
