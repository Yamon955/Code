//HDU-1087
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
const int N = 1e3+5;
ll dp[N]; //dp[j] 代表前 i 个数中以第 j 个数为结尾的最长上升子序列的最大和
ll a[N];
int n;
int main()
{
	while(scanf("%d",&n)!=EOF){
		if(n == 0) break;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		mem(dp,0);
		dp[1] = a[1]; //初始前 1 个数并且以第 1 个数结尾的上升序列的最大值肯定就是 a[1]
		ll Max;
		for(int i=2;i<=n;i++){  //dp[j] 代表前 i 个数中以第 j 个数为结尾的最长上升子序列的最大和
			Max = 0;
			for(int j=1;j<i;j++){
				if(a[i] > a[j]){
					Max = max(Max,dp[j]+a[i]);
				}
			}
            //dp[i] = Max;   这样是错误的，因为可能 i 之前的 i-1 个数都大于 a[i] ,如果这样赋值的话，dp[i] = 0,而实际上 dp[i] = a[i]
			dp[i] = max(Max,a[i]);  //这里要注意，
		}
		Max = 0;
		for(int i=1;i<=n;i++){
			Max = max(Max,dp[i]);
		}
		cout<<Max<<endl;
	}
	return 0;
}
/*
Sample Input
3 1 3 2
4 1 2 3 4
4 3 3 2 1
0
Sample Output
4
10
3
*/