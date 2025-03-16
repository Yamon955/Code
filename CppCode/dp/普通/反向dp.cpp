//HDU-1176
//从最后一秒开始考虑，每次这一秒的状态确定意味着前一秒的状态也已经确定，所以从下向上进行dp
//与数字三角形(数塔问题)相同，都是从底层开始像顶层dp

// 如果把每一刻能否得到馅饼画出来，大致就是这个样子

// 第0秒                       5                       
// 第1秒                     4 5 6
// 第2秒                   3 4 5 6 7
// 第3秒                 2 3 4 5 6 7 8
// 第4秒             0 1 2 3 4 5 6 7 8 9 10
// 第5秒             0 1 2 3 4 5 6 7 8 9 10
// 第6秒             0 1 2 3 4 5 6 7 8 9 10
// 第7秒 .................
// 如果当前位置有馅饼，dp值就是1，否则是0
// 然后就是最简单的数塔了，是取三个位置的最大值
// dp[i][j]=max{dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]}+num[i][j];
// 0和10需要特判一下因为他们只能有两个状态转移过来
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
const int N = 1e5+5;
int dp[N][15];//dp[i][j] 表示在第 i 秒在第 j 个位置上可以接到的最大馅饼数
int num[N][15];//num[i][j] 表示在第 i 秒在第 j 个位置上有几个馅饼
// 建立二维数组。一维代表时间。二维代表位置。点上的值代表馅饼的个数。
// 按时间顺序存储馅饼个数。
// 最后从底往上递推。
int n;
int main()
{
	while(scanf("%d",&n)!=EOF){
		if(n == 0) break;
		mem(num,0);//重置
		int Max_t = 0; //用来记录最大时间
		for(int i=1;i<=n;i++){
			int T,x;
			scanf("%d%d",&x,&T);
			num[T][x]++;
			Max_t = max(Max_t,T);
		}
		for(int i=0;i<=10;i++) dp[Max_t][i] = num[Max_t][i];
		for(int i=Max_t-1;i>=0;i--){  //从底向上 dp
			for(int j=0;j<=10;j++){
				if(j == 0) dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
				else if(j == 10) dp[i][j] = max(dp[i+1][j-1],dp[i+1][j])+num[i][j];
				else dp[i][j] = max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+num[i][j];
			}
		}
        //cout<<max(dp[1][4],max(dp[1][5],dp[1][6]))<<endl;
		cout<<dp[0][5]<<endl; 
	}
	return 0;
}
/*
Sample Input
6
5 1
4 1
6 1
7 2
7 2
8 3
0
Sample Output
4
*/