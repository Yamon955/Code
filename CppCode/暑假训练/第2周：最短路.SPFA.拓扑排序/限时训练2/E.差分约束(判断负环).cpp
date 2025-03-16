//POJ1364
//xb - xa-1 >= 1+k
//xb - xa-1 <= k-1
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
int map[N][N],vis[N],dis[N],cnt[N];
bool spfa(int st)
{
    memset(cnt,0,sizeof cnt);
    memset(dis,0x3f,sizeof dis);//跑最短路，dis[]初始化为最小值
    memset(vis,0,sizeof vis);
    queue<int>q;
    q.push(st);
    dis[st] = 0;
    vis[st] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=0;i<=n+1;i++){  //这里应该是从 0 到 n+1--->一共 n+2 个点
            if(dis[i] > dis[u]+map[u][i]){
                dis[i] = dis[u]+map[u][i];
                if(!vis[i]){
                    q.push(i);
                    cnt[i]++;
                    if(cnt[i]>=n+2) return true;  //存在负环
                    vis[i] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(map,0x3f,sizeof map);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int u,inc,w;
            char op[10];
            scanf("%d %d %s %d",&u,&inc,op,&w);
            if(op[0]=='g'){
                map[u+inc][u-1] = -w-1;
            }
            else {
                map[u-1][u+inc] = w-1;
            }
        }
        for(int i=0;i<=n;i++) map[n+1][i] = 0;//建立超级源点 n+1，不能是 0 ，因为编号为0的点题目中是可能出现的
        if(spfa(n+1)) cout<<"successful conspiracy"<<endl;
        else cout<<"lamentable kingdom"<<endl;
    }
    return 0;
}
/*
Sample Input
4 2
1 2 gt 0
2 2 lt 2
1 2
1 0 gt 0
1 0 lt 0
0
Sample Output
lamentable kingdom
successful conspiracy
*/