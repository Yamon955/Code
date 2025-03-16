//POJ3342
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 205;
int n,cnt;
map<string,int>mp;
vector<int>v[N];
int dp[N][2];
//dp[i][0] : 第 i 个结点不去参加
//dp[i][1] : 第 i 个结点去参加
int f[N][2];
//f[i][0] : 以 i 为根的子树当 i 结点不去参加时 去参加的最大人数是否唯一
//f[i][1] : 以 i 为根的子树当 i 结点去参加时 去参加的最大人数是否唯一
//等于 1 表示该子树去参加的最大人数不唯一
void dfs(int u,int fa)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int i=0;i<v[u].size();i++){
        int y = v[u][i];  //y 是 u 的孩子结点
        if(y==fa) continue;
        dfs(y,u);
		//当 u 结点不参加时 
        if(dp[y][0]==dp[y][1]) {  //当d[v][0]和d[v][1]值相同的时候，选择哪一个都行，那么就不唯一了
            dp[u][0] += dp[y][1];
            f[u][0] = 1;
        }
		//若是选择的其中大的那个不唯一，那么f[u][0]也不唯一。
        else if(dp[y][0]>dp[y][1]){
            dp[u][0] += dp[y][0];
			if(f[y][0]) f[u][0] = 1; //
        }
        else {
            dp[u][0] += dp[y][1];
			if(f[y][1]) f[u][0] = 1;
        }
		//当 u 结点参加时，
        dp[u][1] += dp[y][0];
		//当 u 结点参加时，只要有一个 f[y][0] 不唯一，那么以 u 为根的子树当 u 结点去参加时 去参加的最大人数就不唯一
		if(f[y][0]) f[u][1] = 1;
    }
}
int main()
{
    while(scanf("%d",&n) && n){
        cnt = 0;
        string s;
        memset(dp,0,sizeof dp);
		memset(f,0,sizeof f);
        mp.clear();
        for(int i=0;i<=n;i++){
            v[i].clear();
        }
        cin>>s;
        mp[s] = ++cnt;
        for(int i=1;i<n;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(!mp.count(s1)) mp[s1] = ++cnt;
            if(!mp.count(s2)) mp[s2] = ++cnt;
            v[mp[s1]].push_back(mp[s2]);
            v[mp[s2]].push_back(mp[s1]);
        }
        dfs(1,0);
        if(dp[1][0]==dp[1][1]) printf("%d No\n",dp[1][0]);
        else if(dp[1][0]>dp[1][1]){
            if(f[1][0]) printf("%d No\n",dp[1][0]);
            else printf("%d Yes\n",dp[1][0]);
        }
        else {
            if(f[1][1]) printf("%d No\n",dp[1][1]);
            else printf("%d Yes\n",dp[1][1]);
        }
    }
    return 0;
}
/*
Sample Input
6
Jason
Jack Jason
Joe Jack
Jill Jason
John Jack
Jim Jill
2
Ming
Cho Ming
0
Sample Output
4 Yes
1 No
*/