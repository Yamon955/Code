//HDU3538
#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 25;
int n,m;
int dis[N][N];
int f[N];
int dp[1 << 25][N]; //dp[st] [ u ] 表示已经走过的状态为state ， 且当前的节点处于 u 

int main()
{
	while (scanf("%d%d", &n, &m) != EOF){
		for(int i=0;i< (1<<n);i++){
			for(int j=0;j<=n;j++) dp[i][j] = inf;
		}
		memset(f,0,sizeof f);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &dis[i][j]);
			}
		}
		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			f[b] |= (1 << a);
            //限制条件是 a必须在 b 之前出现，那么开一个数组 f[b] = f[b] | (1 << a) ，这样b 的所以限制条件，
            //都表示在 f[b] 里面 ， 用二进制形式呈现， 递推的时候，我们在拓展下个节点 v 的时候，就可以
            //用这样 if( f[v] == st & f[v] ) ？ 这个语句的意思是 ，f[v] 存在的位置，state也必须存在，
            //那么就满足了限制条件，再拓展。

		}
		dp[1][0] = 0; //初始
		for (int st = 1; st < (1 << n); st++){  //遍历所有状态
			for (int i = 0; i < n; i++){ //当前状态 st 遍历已经走过的点
				if (!(st & (1 << i))) //找出当前状态 st 已经走过的点 i,如果当前 i 点没有走过的话就不用向下进行了
					continue;
				if (dp[st][i] == inf)  //
					continue;
				for (int j = 0; j < n; j++){  //遍历未走过的点
					if (dis[i][j] == -1)  //如果 i--->j 没有路径的
						continue;
					if (st & (1 << j))  //判断当前 j 点有没有走过，如果已经走过则返回
						continue;
					if (f[j] != (st & f[j]))   //判断 j 点之前的必经点有没有走完
						continue;
					int nst = st | (1 << j);   //将 j 点加入到状态中--->形成新的状态 nst
					dp[nst][j] = min(dp[nst][j], dp[st][i] + dis[i][j]);    //更新最短路径
				}
			}
		}
		int ans = inf;
		for (int i = 0; i < n; i++){
			ans = min(ans, dp[(1 << n)-1][i]);
		}
		if (ans == inf)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
/*
Sample Input
3 0
-1 2 4
-1 -1 2
1 3 -1
4 3
-1 2 -1 1
2 -1 2 1
4 3 -1 1
3 2 3 -1
1 3
0 1
2 3
Sample Output
4
5

*/
