//POJ 3764
 //dfs得到根到节点的异或前缀和，然后把每个点的异或前缀和插入字典树中，就可以按套路，在字典树里找对应的最大异或了。
 // a^a = 0
//  因为是一棵边缘加权树且給定n-1条边，所以肯定不成环，那么就一定有 f(u, v)=f(0, u)^f(0, v)，
//  即节点 u 和 v 之间边缘权重的异或和为：（节点 u 到根节点 0 的边缘权重异或和） xor （节点 v 到根节点 0 的边缘权重异或和）。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int T,n,m;
int val[32*N];     //点的值
int ch[32*N][2];   //边的值
int tol;           //节点个数
int xor_sum[N];   //存储每个节点到根节点的距离的疑惑和
int vis[N];
struct Edge{
    int to;
    int w;
    int next;
};
Edge edge[N*2];  //不要忘了，双向边，开的空间应不少于 顶点数*2
int h[N],tot;
void add(int u,int v,int w) //链式前向星
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = h[u];
    h[u] = tot++;
}
void init()
{
    tol = 1;
    mem(ch,0);
    mem(val,0);

    tot = 0; //链式前向星统计边数
    mem(h,-1);

    mem(xor_sum,0);
    mem(vis,0);
}
void dfs(int u)  //搜索得到每个点到根节点的路径异或和
{
    vis[u] = 1;
    for(int i=h[u];i!=-1;i=edge[i].next){
        int v = edge[i].to;
        if(vis[v]) continue;
        xor_sum[v] = xor_sum[u]^edge[i].w;
        dfs(v);
    }
}
void insert(int x)
{
    int pre = 0;
    for(int i=30;i>=0;i--){
        int v = (x>>i)&1;
        if(ch[pre][v]==0){
            ch[pre][v] = tol++;
        }
        pre = ch[pre][v];
    }
    val[pre] = x;
}
int query(int x)
{
    int ans = 0;
    int pre = 0;
    for(int i=30;i>=0;i--){
        int v = (x>>i)&1;
        if(ch[pre][v^1]){
            ans += (1<<i);
            pre = ch[pre][v^1];
        }
        else pre = ch[pre][v];
    }
    return ans;
    //return x^val[pre];
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=0;i<n-1;i++){  //树有 n-1 条边
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        dfs(0);
        for(int i=0;i<n;i++){
            insert(xor_sum[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,query(xor_sum[i]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
Sample Input
4
0 1 3
1 2 4
1 3 6
Sample Output
7
*/