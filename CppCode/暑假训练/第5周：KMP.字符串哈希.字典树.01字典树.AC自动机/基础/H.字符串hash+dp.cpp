//CF 7D
//正向hash,反向hash  两次hash
//然后 dp--> dp[i] = dp[i/2]+1;
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
typedef unsigned long long ull;//MOD对于自然溢出方法，就是 unsigned long long 整数的自然溢出（相当于MOD 是 2^{64} - 1）
const int inf = 0x3f3f3f3f;
const int N = 5e6+5;
const int Base = 233;
int dp[N],ans;
char s[N],fs[N];
ull ha[N],fha[N],pows[N];
ull get_ha(int l,int r)    //获取正向序列 s 中 [l,r] 子串的 hash 值
{ 
    return ha[r]-ha[l-1]*pows[r-l+1];
}
ull get_fha(int l,int r)  //获取反向序列 fs 中 [l,r] 子串的 hash 值
{
    return fha[r]-fha[l-1]*pows[r-l+1];
}
int main()
{
    scanf("%s",s+1);
    int len = strlen(s+1);
    for(int i=1;i<=len;i++){
        fs[len-i+1] = s[i];  //fs 存储 s 的逆序列
    }
    pows[0] = 1;
    for(int i=1;i<=len;i++){
        pows[i] = pows[i-1]*Base;
    }
    ha[0] = fha[0] = 0;
    for(int i=1;i<len;i++){
        ha[i] = ha[i-1]*Base+(s[i]-'a');
        fha[i] = fha[i-1]*Base+(fs[i]-'a');
    }
    ans = dp[1] = 1;
    for(int i=2;i<=len;i++){
        ull left = get_ha(1,i/2);
        ull right = get_fha(len-i+1,len-i+i/2);
        if(left == right){
            dp[i] = dp[i/2]+1;
        }
        ans += dp[i];
    }
    printf("%d",ans);
    return 0;
}
/*
Input
a2A
Output
1
Input
abacaba
Output
6
*/