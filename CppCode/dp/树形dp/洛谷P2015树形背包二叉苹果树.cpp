#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
int n,q;
int f[N][2],vis[N],val[N][N],dp[N][N];
struct Edge{
    int to;
    int next;
};
Edge edge[N*3];
int h[N],tol;
void add(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = h[u];
    h[u] = tol++;
}
void dfs(int x)
{
    vis[x] = 1;//防止死循环做的标记		
    for(int i=h[x];i!=-1;i=edge[i].next){
        int v = edge[i].to;  //v 表示 x 的孩子结点
        if(vis[v]) continue;//如果标记过则代表这是它的父节点，直接跳过
        vis[v] = 1;
        dfs(v); 
        //类似于 01 背包
        for(int j=q;j>=1;j--){  //当前父节点 x 一共可以取的分支(边)数
            for(int k=j-1;k>=0;k--){  //遍历当前孩子所在子树可以取到的分支数，理解这句话
            //k 值最大取到 q-1,即对每一个 j 来说,k 每次最大取到 j-1, 因为 k 值代表在当前节点 x 的其中一个孩子结点 v 所在
            //子树(即左子树或右子树)上取的分支数，但是还需要一条分支用来连接 x和v 因此 0<= k <= j-1 ，因此在此子树上一共取了(k+1)条边

            //剩下的 j-k-1 是在 当前节点 x 的另外的子树上取的
            //因此 结点 x 选择了 j 条边的分布为：在 孩子结点 v 所在子树选择了 k 条边, 选择了连接 x和v 的一条边，在 x 的其他子树上选择了 j-k-1 条边
                dp[x][j] = max(dp[x][j],dp[v][k]+val[x][v]+dp[x][j-k-1]);
                //dp[v][k] 表示在 x 的孩子结点 v 所在子树上取 k 条分支的值
                //val[x][v] 表示连接 x和v 的这一条分支的值
                //dp[x][j-k-1] 表示还剩下 j-k-1 条分支供 x 的其他子树选择(类似于 01 背包的剩余空间)
            }
        }
    }
}
int main()
{
    memset(h,-1,sizeof h);
    tol = 0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v);
        add(v,u);
        val[u][v] = val[v][u] = w;
    }
    dfs(1);
    printf("%d",dp[1][q]);
    return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20
---->21
*/