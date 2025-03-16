//https://vjudge.net/problem/HDU-1423
//https://www.cnblogs.com/-Ackerman/p/11232960.html LCIS博客
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e3+105,M=1e9+7;

int n,m;
int a[N],b[N];
int f[N][N];

int get_LCIS()  //O(n^2)写法
{
    for(int i=1;i<=n;i++){
        int Max = 0;
        for(int j=1;j<=m;j++){
            if(a[i] != b[j]) f[i][j] = f[i-1][j];
            if(a[i] > b[j])  Max = max(Max,f[i-1][j]);
            if(a[i] == b[j]) f[i][j] = Max + 1;
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++)
        ans = max(ans,f[n][i]);
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>m;
        for(int j=1;j<=m;j++) cin>>b[j];
        if(T != 0) printf("%d\n\n", get_LCIS());
        else printf("%d\n", get_LCIS());
    }
}
