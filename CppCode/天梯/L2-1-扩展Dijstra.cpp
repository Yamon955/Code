#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 505;
int map[N][N];
int n,m,s,d;
int a[N];
int vis[N],dis[N],num[N],pre[N];
int cnt[N];  // 存储到每个结点的最短路径的条数
void print(int x)
{
    if(pre[x] == s){
        return ;
    }
    print(pre[x]);
    cout<<" "<<x-1;
}
int Dij(int st)
{
    mem(dis,0x3f);
    dis[st] = 0;
    num[st] = a[st];
    cnt[st] = 1;
    for(int i=1;i<=n;i++){
        int Min = 0x3f3f3f3f,k=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && dis[j] >= dis[k]+map[k][j]){
                if(dis[j] > dis[k]+map[k][j]){
                    dis[j] = dis[k]+map[k][j];
                    num[j] = num[k] + a[j];
                    cnt[j] = cnt[k];  // 注意，到达 j 结点的方式数等于到达前驱的方式
                    pre[j] = k;
                }
                else if(dis[j] == dis[k]+map[k][j]){
                    cnt[j] = cnt[j] + cnt[k];  //注意，两种方式距离相等，则方式数相加
                    if(num[j] < num[k]+a[j]){  //能获得更大的救援，则更新 
                        num[j] = num[k]+a[j];
                        pre[j] = k;
                    }
                        
                }
                
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) map[i][j] = 0;
            else map[i][j] = inf;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        u++;
        v++;
        map[u][v] = map[v][u] = min(map[v][u],w);
    }
    Dij(s+1);
    cout<<cnt[d+1]<<" "<<num[d+1]<<endl;
    cout<<s;
    print(d+1);
}
/*
输入样例:
4 5 0 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2
结尾无空行
输出样例:
2 60
0 1 3
*/
