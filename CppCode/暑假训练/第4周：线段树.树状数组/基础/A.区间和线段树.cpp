//https://vjudge.net/contest/453578  题集
//线段树  树状数组

//HDU 1166
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
const int N = 5e4+5;
int T,n;
int a[N];
int tree[N*4],lazy[N*4];
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void pushDown(int l,int r,int rt)
{
    if(lazy[rt]!=0){
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        int mid = (l+r)>>1;
        tree[rt<<1] += lazy[rt]*(mid-l+1);
        tree[rt<<1|1] += lazy[rt]*(r-mid);
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
        tree[rt] += c*(r-l+1);
        lazy[rt] += c;
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
    if(x<=mid) ans += Query(l,mid,x,y,rt<<1);
    if(y>mid) ans += Query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
int main()
{
    scanf("%d",&T);
    
    int cnt = 0;
    while(T--){
        mem(tree,0);
        mem(lazy,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        Build(1,n,1);
        char s[10];
        printf("Case %d:\n",++cnt);
        while(cin>>s){
            int x,y;
            if(s[0]=='E') break;
            else if(s[0]=='Q'){
                scanf("%d%d",&x,&y);
                printf("%d\n",Query(1,n,x,y,1));
            }
            else if(s[0]=='A'){
                scanf("%d%d",&x,&y);
                update(1,n,x,x,y,1);
            }
            else if(s[0]=='S'){
                scanf("%d%d",&x,&y);
                update(1,n,x,x,-y,1);
            }
        }
    }
    return 0;
}
/*
Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
Sample Output
Case 1:
6
33
59
*/
