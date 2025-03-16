//HDU 1754
//相近 洛谷P1531
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
const int N = 2e5+5;
int T,n,m;
int a[N];
int tree[N*4],lazy[N*4];
void pushUp(int rt)
{
    tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
}
void pushDown(int l,int r,int rt)
{
    if(lazy[rt]!=0){
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        tree[rt<<1] = max(tree[rt<<1],lazy[rt]);
        tree[rt<<1|1] = max(tree[rt<<1|1],lazy[rt]);
        lazy[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    if(l==r){
        tree[rt] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
void update(int l,int r,int x,int y,int c,int rt)
{
    if(x<=l && r<=y){
        tree[rt] = c;
        lazy[rt] = c;
        return;
    }
    pushDown(l,r,rt);
    int mid = (l+r)>>1;
    if(x<=mid) update(l,mid,x,y,c,rt<<1);
    if(y>mid) update(mid+1,r,x,y,c,rt<<1|1);
    pushUp(rt);
}
int Query(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y){
        return tree[rt];
    }
    pushDown(l,r,rt);  //如果查询时还存在没有处理过的标记，则处理一下，防止出错
    int mid = (l+r)>>1;
    int ans = 0;
    if(x<=mid) ans = max(ans,Query(l,mid,x,y,rt<<1));
    if(y>mid) ans = max(ans,Query(mid+1,r,x,y,rt<<1|1));
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        mem(tree,0);
        mem(lazy,0);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        Build(1,n,1);
        char op[5];
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%s%d%d",op,&x,&y);
            if(op[0]=='Q'){
                cout<<Query(1,n,x,y,1)<<endl;
            }
            else {
                update(1,n,x,x,y,1);
            }
        }
    }
    return 0;
}
/*
Sample Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5
Sample Output
5
6
5
9

*/
