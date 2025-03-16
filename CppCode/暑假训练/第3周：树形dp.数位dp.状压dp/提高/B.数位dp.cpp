//CF55D
//一个很显然的性质是一个数若能整除所有位数上的数，则一定能整除他们的lcm。
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
const int N = 25;
const int Mod = 2520;//{1,2,3,4,5,6,7,8,9}的最小公倍数是2520
ll n,l,r;
ll dp[N][Mod+10][50];
//由于{1,2,3,4,5,6,7,8,9}的最小公倍数是2520 所以我们维护三个状态[i][j][k]表示第i位且对应 % 2520=j 最小公倍数是k的方案数
int a[N],len,idx[Mod+5];
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
ll dfs(int pos,int preMod,int preLcm,int limit)
{
    if(pos==0) return preMod%preLcm==0;
    if(!limit && dp[pos][preMod][idx[preLcm]]!=-1) return dp[pos][preMod][idx[preLcm]];
    ll ans = 0;
    int up = limit?a[pos]:9;
    for(int i=0;i<=up;i++){
        int nowMod = (preMod*10+i)%Mod;
        int nowLcm = preLcm;
        if(i) nowLcm = lcm(preLcm,i);
        ans += dfs(pos-1,nowMod,nowLcm,(i==up)&&limit);
    }
    if(!limit) dp[pos][preMod][idx[preLcm]] = ans;
    return ans;
}
ll part(ll x)
{
    len = 0;
    while(x){
        a[++len] = x%10;
        x /= 10;
    }
    return dfs(len,0,1,1);
    

}
int main()
{
    memset(dp,-1,sizeof dp);
    int tmp = 0;
    for(int i=1;i<=2520;i++) 
        if(Mod%i==0) idx[i] = tmp++;  //因为1~9中的各种数字组合的最小公倍数可能值有限，实测为48个
                                      //将可能出现的最小公倍数标号处理,这样可以避免开很大的空间
                                      //离散化处理
    cin>>n;
    while(n--){
        cin>>l>>r;
        cout<<part(r)-part(l-1)<<endl;
    }
    return 0;

}
/*
Input
1
1 9
Output
9
Input
1
12 15
Output
2
*/