//HDU-1024、
//https://blog.csdn.net/weixin_41863129/article/details/85539776
//https://blog.csdn.net/qq_43235540/article/details/103748827
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
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
/*
二维数组 dp[N][N] 很显然会爆内存
dp[i][j] 表示前j个数划分成i段的最大值
决策取决于j是否属于第i段
假设当前数为第 j 个，该数有2种可能：
第一种是第j个数属于第 i 块的第一个，dp[i] [j] = 前 j-1 个数中构成i-1块的最大和 + a[j]
第二种是第j个数属于第 i 块但不是第一个。dp[i][j] = dp[i][j-1]+a[j]
*/
ll dp[N],dp_2[N];
int m,n;
ll a[N];
int main()
{
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			dp[i] = 0;
			dp_2[i] = 0;
		} 
		ll tmp;
		for(int i=1;i<=m;i++){//计算分成i块
			tmp = -inf;  //表示前j个分i块的最大值。
			for(int j=i;j<=n;j++){//把前j个分成i块
				dp[j] = max(dp[j-1]+a[j],dp_2[j-1]+a[j]);
				dp_2[j-1] = tmp;
                //dp_2 用于在下一轮i中，而这一轮i中，此时的dp_2[j]是下一轮的dp_2[j-1],故还会被使用，故要借助tmp。dp_2[j-1]=tem;
				tmp = max(tmp,dp[j]);
			}
		}
		cout<<tmp<<endl;
	}
}
/*
Sample Input
1 3 1 2 3
2 6 -1 4 -2 3 -2 3
 

Sample Output
6
8
*/