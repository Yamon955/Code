//HDU - 4217
// 建立一个线段树，树节点记录的是节点所表示的区间内剩余数的个数（初始化时叶子节点的值都为1）。
//取出对应位置的数后，将该位置置为 0 ，即update(pos,-1);
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
int T,k,n,m;
int a[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int pos,int x)
{
    for(int i=pos;i<=n;i+=lowbit(i))
        a[i] += x;
}
int query(int pos)
{
    int ans = 0;
    for(int i=pos;i;i-=lowbit(i))
        ans += a[i];
    return ans;
}
int Binary_search(int l,int r,int k)
{
    while(l < r){
        int mid = (l+r)>>1;
        if(query(mid) < k){
            l = mid+1;
        }
        else r = mid;
    }
    return r;
}
int main()
{
    scanf("%d",&T);
    int cnt = 0;
    while(T--){
        ll ans = 0;
        scanf("%d%d",&n,&m);
        mem(a,0);
        for(int i=1;i<=n;i++) 
            update(i,1);
        while(m--){
            scanf("%d",&k);
            k = Binary_search(1,n,k);
            ans += k;
            update(k,-1);
        }
        cout<<"Case "<<(++cnt)<<": "<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
2
3 2
1 1
10 3
3 9 1
Sample Output
Case 1: 3
Case 2: 14
*/