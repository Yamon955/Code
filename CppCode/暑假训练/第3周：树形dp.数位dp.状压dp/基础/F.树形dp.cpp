//CodeForces1118F1
// 一条边是连接一个子树和树其他部分的桥，那么一条边是否是满足条件的边只需要满足这条边所对应的子树是否包含所有的红色点，
// 或者包含所有的蓝色点。所以我们dfs的时候只需要返回一下子树的蓝色点个数和红色点个数就行了。然后交给上一级统计。
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
const int N = 3e5+5;
int n,m,root;
int color[N],vis[N];
int num[3],dp[N][3];
// 0-->无色  1--->红色  2--->蓝色
//dp状态
//dp[i][1] 表示当前结点 i 的子树(也包含 i 结点本身)包含的所有红色结点数
//dp[i][2] 表示当前结点 i 的子树(也包含 i 结点本身)包含的所有蓝色结点数
struct Edge{
    int to;
    int next;
};
Edge edge[N*3];
int h[N],tol,ans;
void add(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = h[u];
    h[u] = tol++;
}
void dfs(int x)
{
    vis[x] = 1;
    for(int i=h[x];i!=-1;i=edge[i].next){
        int v = edge[i].to;
        if(vis[v]) continue;
        vis[v] = 1;   //如果标记过则代表这是它的父节点，直接跳过
        dfs(v);
        if(color[v]==1){   //v 结点为红色
            dp[v][1] += 1;
        }
        else if(color[v]==2){   //v 结点为蓝色
            dp[v][2] += 1;
        }
         if((dp[v][1] == num[1] && dp[v][2]==0) || (dp[v][2] == num[2] && dp[v][1]==0)) //表示当前节点 x 的孩子节点 v 所在子树(包含了全部的蓝色结点并且不含红色结点)或(包含了全部的红色结点并且不含蓝色结点)
            ans++;                                                              //则 x---->v 的这一条边符合要求
        dp[x][1] += dp[v][1];  //更新父节点的颜色数
        dp[x][2] += dp[v][2];
    }
}
int main()
{
    memset(h,-1,sizeof h);
    tol = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){ 
        scanf("%d",&color[i]);
        num[color[i]]++;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1);  //从任何一个结点开始遍历都行，因为这是一颗无规则数，任何一个结点都可以做根节点
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i][1]<<" "<<dp[i][2]<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}