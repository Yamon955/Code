//POJ-1015
//https://blog.csdn.net/lyy289065406/article/details/6671105
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 805; //这里开 800 往上
int n,m;
int dp[N][N];//取 i 个候选人，使两方差值为 j 的所有方案中总和最大的方案的总和
//dp[i][j] = -1 表示没法选 i 个人，使两方差为 j 
int p[N],d[N],S[N],D[N];
int pre[N][N];
int ans[N];
bool Judge(int i,int j,int k)
{
	while(i>0 && pre[i][j] != k){
		j -= D[pre[i][j]];
		i--;
	}
	return i?false:true;
}
int main()
{
	int Case = 0;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		for(int i=1;i<=n;i++){
			cin>>p[i]>>d[i];
			D[i] = p[i] - d[i];
			S[i] = p[i] + d[i];
		}

		mem(dp,-1);
		mem(pre,0);

		int fix = m*20; //总修正值，修正极限为从[-400,400]映射到[0,800]

		dp[0][fix] = 0;//由于修正了数值，因此dp[0][fix]才是真正的dp[0][0]

		for(int i=1;i<=m;i++){
			for(int j=0;j<=2*fix;j++){
				if(dp[i-1][j] >= 0){
					for(int k=1;k<=n;k++){//区间已平移，dp[0][fix]才是真正的dp[0][0]

						if(dp[i][j+D[k]] < dp[i-1][j]+S[k]){
							if(Judge(i-1,j,k)){
								dp[i][j+D[k]] = dp[i-1][j]+S[k];
								pre[i][j+D[k]] = k;
							}
						}
					}
				}
			}
		}
		int Min_s = 0;
		for(int i=0;i<=fix;i++){  //从中间向两边搜索最小差的位置 i
			if(dp[m][fix-i] >= 0 || dp[m][fix+i] >= 0){
				Min_s = dp[m][fix-i]>dp[m][fix+i] ? fix-i:fix+i;
				break;
			}
		}

		printf("Jury #%d\n",++Case);
        //ps + ds = dp[m][Min_s]
        //ps - dx = Min_s - fix;
        //解方程即可
		int ps = (dp[m][Min_s] + Min_s - fix)/2;
		int ds = (dp[m][Min_s] - Min_s + fix)/2;
		printf("Best jury has value %d for prosecution and value %d for defence:\n",ps,ds);
		for(int i=0,j=m,k=Min_s;i<m;i++){
			ans[i] = pre[j][k];
			k -= D[ans[i]];
			j --;
		}
		sort(ans,ans+m);//升序输出候选人编号
		for(int i=0;i<m;i++) 
			cout<<" "<<ans[i];
		cout<<endl<<endl;
	}
}
/*
Sample Input

4 2 
1 2 
2 3 
4 1 
6 2 
0 0 
Sample Output

Jury #1 
Best jury has value 6 for prosecution and value 4 for defence: 
 2 3 
 */