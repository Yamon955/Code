//CF 985F
//这个题自然溢出似乎被卡
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
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;
const ll Base = 131;
const ll MOD = 1e9+7;
int n,m;
ll ha[N][30];//比如ha[i][1]表示第i个字符为a的哈希值
ll pows[N];
char s[N];
void init()//初始化ha和pows数组
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            ha[i][j] = ( ha[i-1][j]*Base%MOD+(ll)(s[i]==('a'+j-1)) )%MOD;
        }
    }
    pows[0] = 1;
    for(int i=1;i<=n;i++){
        pows[i] = pows[i-1] * Base % MOD;
    }
}
bool check(int l,int r,int len)
{
    ll a[27],b[27];
    for(int i=1;i<=26;i++){
        a[i] =( ha[l+len-1][i] - (ha[l-1][i]*pows[len])%MOD + MOD ) %MOD;
        b[i] =( ha[r+len-1][i] - (ha[r-1][i]*pows[len])%MOD + MOD ) %MOD;
    }
    sort(a+1,a+27);
    sort(b+1,b+27);
    for(int i=1;i<=26;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    init();
    while(m--){
        int l,r,len;
        scanf("%d%d%d",&l,&r,&len);
        if(check(l,r,len)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
Input
7 4
abacaba
1 1 1
1 4 2
2 1 3
2 4 3
Output
YES
YES
NO
YES
*/