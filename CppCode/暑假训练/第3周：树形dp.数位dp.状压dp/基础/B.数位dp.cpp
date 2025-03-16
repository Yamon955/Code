//HDU3555
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
const ll N = 1e18+5;
int T,len,a[100];
ll n;
ll dp[20][2];
ll dfs(int pos,int st,int limit)//pos表示当前第几位  st表示当前数字前一位是不是 4  limit表示当前数字取值有没有限制
{
    if(pos==0) return 1;//表示数字位数用完了，仍然没有包含 49，则此数字满足题意，故返回 1
    if(!limit && dp[pos][st]!=-1) return dp[pos][st];
    ll ans = 0;
    int up = limit?a[pos]:9;//up表示当前数取值的最大值
                                    //limit==1表示当前数取值有限制，那么当前数取值最大为拆分的数x在该位对应的数字即第pos位
                                    //limit==0表示当前数值取值无限制，那么最大可以取到 9
    for(int i=0;i<=up;i++){
        if(st && i==9) continue;
        ans += dfs(pos-1,i==4,(i==up)&&limit);
    }
    if(!limit) dp[pos][st] = ans;
    return ans;
}
ll part(ll x)
{
    len = 0;
    memset(dp,-1,sizeof dp);
    while(x){
        a[++len] = x%10;
        x/=10;
    }
    return dfs(len,0,1);
}
int main()
{
    //memset(dp,-1,sizeof dp); //只在这里初始话一次也行
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        //注意dfs求出 0~n 不包含49的数字的个数
        //所以 1~n 不包含49的数字个数为 part(n)-1;
        ll a = n - (part(n)-1); //a等于1~n包含49的数字个数
        printf("%lld\n",a);

    }
    return 0;
}
/*
Sample Input
3
1
50
500
Sample Output
0
1
15
*/