//HDU3709`
#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <stack>
#include<vector>
#include <queue>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 20;
ll T,x,y;
int len,a[N];
ll dp[N][N][2005];
ll dfs(int pos,int po,int val,int limit)//pos当前位置,po支点,val力矩,lim是否有上限
{
    if(pos==0)  return val==0;
    if(val<0) return 0;  //不写也行，相当于一个剪枝
    if(!limit && dp[pos][po][val]!=-1) return dp[pos][po][val];
    ll ans = 0;
    int up = limit?a[pos]:9;
    for(int i=0;i<=up;i++){
        ans += dfs(pos-1,po,(pos-po)*i+val,(i==up)&&limit);
    }
    if(!limit) dp[pos][po][val] = ans;
    return ans;
    
} 
ll part(ll x)
{
    if(x==-1) return 0;
    len = 0;
    memset(dp,-1,sizeof dp);
    while(x){
        a[++len] = x%10;
        x /= 10;
    }
    ll ans = 0;
    for(int i=1;i<=len;i++) ans += dfs(len,i,0,1);  //遍历每一位当支点的情况
    ans = ans - (1ll*len-1);//最后需要去除全是0的情况，因为全是0的话，中心点可随意枚举没，所以需要减去(len-1)。
    return ans;
}
int main()
{
    //memset(dp,-1,sizeof dp);  只在这里初始化一次也行
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",part(y)-part(x-1));
    }
    return 0;
}
/*
Sample Input
2
0 9
7604 24324
Sample Output
10
897
*/