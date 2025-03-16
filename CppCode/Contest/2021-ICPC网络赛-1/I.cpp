#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
ll as[N];
ll ans[N];
int main()
{
    int cnt = 0,res = 0;
    ll x;
    while(scanf("%lld",&x)!=EOF){
        as[cnt++] = x;
    }
    ll a = as[cnt-2];
    ll r = as[cnt-1];
    sort(as,as+cnt-2);
    bool flag = false;
    for(int i=cnt-3;i>=0;i--){
        if(as[i] <= a+r && as[i] >= a-r){
            printf("%lld ",as[i]);
            flag = true;
        }
    }
    if(!false) cout<<endl;
    return 0;
}