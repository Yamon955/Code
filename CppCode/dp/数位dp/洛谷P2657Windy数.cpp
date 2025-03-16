#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 11;
int l,r;
int a[N],len;
ll dp[N][10];
ll dfs(int pos,int pre,int lead,int limit)
{
    if(pos>len) return 1;
    if(!lead && !limit && dp[pos][pre]!=-1) return dp[pos][pre];
    ll ans = 0;
    int up = limit?a[len-pos+1]:9;
    for(int i=0;i<=up;i++){
        if(lead){
            if(i==0) ans += dfs(pos+1,i,lead && i==0,(i==up)&&limit);
            else ans += dfs(pos+1,i,lead && i==0,(i==up)&&limit);
        }
        else {
            if(abs(i-pre)<2) continue;
            ans += dfs(pos+1,i,0,(i==up)&&limit);
        }

    }
    if(!lead && !limit) dp[pos][pre] = ans;
    return ans;
}
ll part(ll x)
{
    memset(dp,-1,sizeof dp);
    len = 0;
    while(x){
        a[++len] = x%10;
        x /= 10;
    }
    return dfs(1,0,1,1);
}
int main()
{
    cin>>l>>r;
    cout<<part(r)-part(l-1)<<endl;
    return 0;

}
