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
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[N*N];
int h[N],tol;
void add(int u,int v,int w)
{
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = h[u];
    h[u] = tol++;
}
bool spfa(int st)
{
    memset(cnt,0,sizeof cnt);
    memset(dis,-0x3f,sizeof dis);//跑最长路，dis[]初始化为最小值，实际上对于只判断负环来说，dis[]初值不重要
    memset(vis,0,sizeof vis);
    queue<int>q;
    for(int i=0;i<=n;i++){  //此图可能是不连通图，因此每个点都需要入队来判断有没有正环
        q.push(i);          //千万不要忘了 0 这个点
        vis[i] = 1;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[v] < dis[u]+w){
                dis[v] = dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v]>n+1) return true;  //存在正环
                    vis[v] = 1;
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
        memset(h,-1,sizeof h);
        tol = 0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int u,inc,w;
            char op[10];
            scanf("%d %d %s %d",&u,&inc,op,&w);
            if(op[0]=='g'){
                add(u-1,u+inc,w+1);
            }
            else {
                add(u+inc,u-1,1-w);
            }
        }
       // for(int i=1;i<=n;i++) map[0][i] = 0;//建立超级源点  这里不能建立超级源点0，因为0号点是题目可能出现的点，
       // for(int i=1;i<=n;i++) map[0][i] = 0;//如果非要建立的话应该建立编号为n+1的超级源点                                   
        if(spfa(1)) cout<<"successful conspiracy"<<endl;
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