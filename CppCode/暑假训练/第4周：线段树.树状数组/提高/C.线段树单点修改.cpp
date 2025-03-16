//HDU 5475
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
const int N = 1e5+5;
ll T,n,m,mod;  //无脑 long long
ll tree[N<<2];  
void pushUp(int rt)
{
    tree[rt] = (tree[rt<<1]*tree[rt<<1|1]) % mod;
}
void Build(int l,int r,int rt)
{
    if(l==r){
        tree[rt] = 1;
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
void update(int l,int r,int idx,int c,int rt)
{
    if(l == r){
        tree[rt] = c%mod;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) update(l,mid,idx,c,rt<<1);
    else update(mid+1,r,idx,c,rt<<1|1);
    pushUp(rt);
}

int main()
{
    scanf("%lld",&T);
    for(int t=1;t<=T;t++){
        scanf("%lld%lld",&n,&mod);
        Build(1,n,1);
        printf("Case #%lld:\n",t);
        for(int i=1;i<=n;i++){
            ll op,y;
            scanf("%lld%lld",&op,&y);
            if(op == 1){
                update(1,n,i,y,1); // 第 i 个叶子结点内容置为乘数 y
            }
            else if(op == 2){
                update(1,n,y,1,1);  //不进行除法，只需要将之前第 y 次操作的乘数抵消掉就行，即将叶子节点 y 的内容置为 1
            }
            printf("%lld\n",tree[1]);
        }
    }
}
/*
Case #1:
2
1
2
20
10
1
6
42
504
84
*/