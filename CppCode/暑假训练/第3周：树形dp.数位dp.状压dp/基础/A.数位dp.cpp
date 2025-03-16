//https://vjudge.net/contest/451301  题集链接
//树形dp,数位dp,状压dp

//CF1036C
//https://blog.csdn.net/wust_zzwh/article/details/52100392
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
ll T,l,r;
int len,a[100];
int dp[20][20];
ll dfs(int pos,int st,int limit) //pos表示当前第几位(从右向左数)  st表示当前已经用了非0数字的个数  limit表示当前数字取值有没有限制
{
    if(st>3) return 0;    //如果st>3表示用的非0数字个数超过3 个，则此数字不符合题意，故返回 0
    if(pos==0) return 1; //表示数字位数用完了，st仍然没有超过 3，则此数字满足题意，故返回 1
    if(!limit && dp[pos][st]!=-1) return dp[pos][st];
    ll ans = 0;
    int up = limit?a[pos]:9;  //up表示当前数取值的最大值
                                    //limit==1表示当前数取值有限制，那么当前数取值最大为拆分的数x在该位对应的数字即第pos位
                                    //limit==0表示当前数值取值无限制，那么最大可以取到 9
    for(int i=0;i<=up;i++){
        if(i) ans += dfs(pos-1,st+1,(i==up)&&limit);
        else if(!i) ans += dfs(pos-1,st,(i==up)&&limit); 
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
    //memset(dp,-1,sizeof dp);  //只在这里初始化一次也行 因为这是遍历每一位数字
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",part(r)-part(l-1));//如果 l==0的话还要特判一下应该输出为：printf("%lld\n",part(r)-part(l)) [l==0]
    }                                    //此题明确 l>=1的所有不需要特判
    return 0;
}
/*
4
1 1000
1024 1024
65536 65536
999999 1000001
Output
1000
1
0
2
*/