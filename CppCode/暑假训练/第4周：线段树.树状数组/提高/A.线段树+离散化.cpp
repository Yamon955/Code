//https://vjudge.net/contest/453607  题集

//SPOJ DQUERY-D
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
const int N = 3e4+5;
const int M = 2e5+5;
int n,m;
int a[N];
ll ans[N];
ll tree[N*4],lazy[N*4];
struct node{
    int l,r;
    int idx;
    ll ans;
};
node p[M];
bool cmp1(node a,node b)
{
    return a.r<b.r;
}
bool cmp2(node a,node b)
{
    return a.idx<b.idx;
}
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void pushDown(int l,int r,int rt)
{
    if(lazy[rt]){
        int mid = (l+r)>>1;
        tree[rt<<1] = lazy[rt]*(mid-l+1);
        tree[rt<<1|1] = lazy[rt]*(r-mid);
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    if(l==r){
        tree[rt] = 0;
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
        tree[rt] = c*(r-l+1);
        lazy[rt] = c;
        return;
    }
    pushDown(l,r,rt);
    int mid = (l+r)>>1;
    if(x<=mid) update(l,mid,x,y,c,rt<<1);
    if(y>mid)  update(mid+1,r,x,y,c,rt<<1|1);
    pushUp(rt);
}
ll Query(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y){
        return tree[rt];
    }
    pushDown(l,r,rt);
    int mid = (l+r)>>1;
    ll ans = 0;
    if(x<=mid) ans += Query(l,mid,x,y,rt<<1);
    if(y>mid) ans += Query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    Build(1,n,1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&p[i].l,&p[i].r);
        p[i].idx = i;
    }
    sort(p+1,p+m+1,cmp1);
    map<int,int>vis;
    int j = 1;
    for(int i=1;i<=m;i++){
        while(j <= p[i].r){
            if(vis.count(a[j])==0){
                vis[a[j]] = j;
                update(1,n,vis[a[j]],vis[a[j]],1,1);
            }
            else {
                update(1,n,vis[a[j]],vis[a[j]],0,1);
                vis[a[j]] = j;
                update(1,n,vis[a[j]],vis[a[j]],1,1);
            }
            j++;
        }
        p[i].ans = Query(1,n,p[i].l,p[i].r,1);
    }
    sort(p+1,p+m+1,cmp2);
    for(int i=1;i<=m;i++)
        printf("%lld\n",p[i].ans);
    return 0;
}
/*
Input
5
1 1 2 1 3
3
1 5
2 4
3 5

Output
3
2
3 
*/