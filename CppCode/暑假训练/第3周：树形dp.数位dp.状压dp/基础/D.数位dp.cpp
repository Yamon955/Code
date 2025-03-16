//HDU2089
//https://www.luogu.com.cn/blog/virus2017/shuweidp  数位dp讲的不错
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
const int N = 1e6+5;
int n,m,len;
int a[N];
int dp[20][2];
int dfs(int pos,int pre,int st,int limit)//pos代表当前是第几位(从右向左数)，pre代表当前数的前一位的数字(在本题无用)
{                                       //st表示当前数前一位是不是 6 ,limit表示当前数取值有没有限制
    if(pos==0) return 1;
    if(!limit && dp[pos][st]!=-1) return dp[pos][st];
    int ans = 0;
    int up = limit ? a[pos]:9;//up表示当前数取值的最大值
                                    //limit==1表示当前数取值有限制，那么当前数取值最大为拆分的数x在该位对应的数字即第pos位
                                    //limit==0表示当前数值取值无限制，那么最大可以取到 9
    for(int i=0;i<=up;i++){
        if(i==4 || (st && i==2)) continue;
        else ans += dfs(pos-1,i,i==6,(i==up)&&limit );
    }
    if(!limit) dp[pos][st] = ans;
    return ans;
}

int part(int x)
{
    len = 0;
    while(x){ 
        a[++len] = x%10;
        x/=10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(len,0,0,1);

}
int main()
{
    while(scanf("%d%d",&n,&m) &&( n && m)){
        printf("%d\n",part(m)-part(n-1));

    }
    return 0;
}
/*
Sample Input
1 100
0 0
Sample Output
80
*/