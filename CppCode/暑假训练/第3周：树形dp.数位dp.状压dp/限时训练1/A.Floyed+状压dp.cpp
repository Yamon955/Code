//POJ 3311
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
int dp[1 << 22][N];
//dp[st][i] : 表示当前状态为 st 并且当前位于 i 点的最短时间
//用dp[i][j]表示状态i下以j结尾的最短时间。
//由于不知道每两个点之间到底怎么走时间最短，用floyd求一下最短路程，然后进行dp。
void Floyed()
{
	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF){
		if(n==0) break;
		for(int i=0;i<= (1<<(n+1));i++){
			for(int j=0;j<=n;j++) dp[i][j] = inf;  ///初始化
		}
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				cin>>dis[i][j];
			}
		}
		Floyed();  //更新dis[i][j]为从 i 到 j 的最短距离
		dp[1][0] = 0;  //初始化
		for (int st = 1; st < (1 << (n+1)); st++){  //遍历每一种状态
			for (int i=0; i<=n; i++){   //遍历该状态下每一种可能的终点
				if (!(st & (1 << i))) //找出当前状态 st 已经走过的点 i
					continue;
				if (dp[st][i] == inf)
					continue;
				for (int j = 0; j <= n; j++){  //遍历下一个可能到达的点
					if(i==j) continue;
					int nst = st | (1 << j);
					dp[nst][j] = min(dp[nst][j], dp[st][i] + dis[i][j]);  //更新最优值
				}
			}
		}
		cout<<dp[(1<<(n+1))-1][0]<<endl; //最后输出所有点都已经走完并且最后位于 0 点的最短距离
	}
	return 0;
}
/*
Sample Input
3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0
Sample Output
8
*/