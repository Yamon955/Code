//HDU1054
//POJ1463
//此题要注意一下输入
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
const int N = 1505;
int n,vis[N];
vector<int>v[N];
int dp[N][2];
//dp[u][0] 表示在结点 u 处不设置守卫
//dp[u][1] 表示在结点 u 处设置守卫
void dfs(int u,int fa)  //u 表示当前结点，fa为当前结点的父节点
{
    // vis[u] = 1;  vis[]标记数组与参数fa作用一样，都是为了避免重复走已经走过的点，因为树的边是按无向边处理的，但解决问题时只能走一次，保证只经过每个点一次
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int i=0;i<v[u].size();i++){
        int y = v[u][i];  //y 代表 u 的孩子结点
        if(y == fa) continue;//如果 y 是 u 的父节点(表明实际上 y 已经走过了)，直接跳过,避免重复走
        // vis[y] = 1;
        dfs(y,u);
        dp[u][0] += dp[y][1];
        dp[u][1] += min(dp[y][0],dp[y][1]);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++) v[i].clear();
        //memset(vis,0,sizeof vis);
        memset(dp,0,sizeof dp);
        int x,k;
        for(int i=0;i<n;i++){
            scanf("%d:(%d)",&x,&k);
            for(int i=1;i<=k;i++){
                int y;
                scanf("%d",&y);
                v[x].push_back(y);
                v[y].push_back(x);
            }
        }
        dfs(0,-1);
        printf("%d\n",min(dp[0][0],dp[0][1]));
    }
    return 0;
}
/*
Sample Input
4
0:(1) 1
1:(2) 2 3
2:(0)
3:(0)
5
3:(3) 1 4 2
1:(1) 0
2:(0)
0:(0)
4:(0)
Sample Output
1
2
*/