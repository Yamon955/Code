//poj-2955
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
const int N = 1e2+5;
int dp[N][N];//dp[i][j]表示第i~j个字符间的最大匹配字符数
int n;
// if(s[i] 与 s[j]匹配） dp[i][j] = d[i+1][j-1] +2;

// dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
int main()



{
	char s[N];
	while(cin>>s+1){
		if(strcmp(s+1,"end") == 0) break;
		int len = strlen(s+1);
		mem(dp,0);//初始化为 0
        ////dp[i][i]不用处理，因为自己和自己不匹配就是0
		for(int w = 1;w<=len;w++){
			for(int i=1;i<=len-w;i++){
				int j = i + w ;
				//如果s[i]与s[j]匹配，那么明显的dp[i][j] = dp[i+1][j-1]+2;然后在这个基础上枚举分割点k.
				if((s[i]=='(' && s[j]==')') ||(s[i]=='[' && s[j]==']')){
					dp[i][j] = dp[i+1][j-1]+2;
				}
				for(int k=i;k<j;k++){
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
		cout<<dp[1][len]<<endl;
		
	}
}
/*
Sample Input
((()))
()()()
([]])
)[)(
([][][)
end
Sample Output
6
6
4
0
6
*/