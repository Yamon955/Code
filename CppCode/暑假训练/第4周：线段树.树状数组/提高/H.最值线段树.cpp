//POJ 3264
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
int n,m;  
int a[N];
int Max[N<<2];//维护最大值
int Min[N<<2];//维护最小值
void pushUp(int rt)
{
    Max[rt] = max(Max[rt<<1],Max[rt<<1|1]);
    Min[rt] = min(Min[rt<<1],Min[rt<<1|1]);
}
void Build(int l,int r,int rt)
{
    if(l==r){
        Max[rt] = max(a[l],Max[rt]);
        Min[rt] = min(a[l],Min[rt]);
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
int Query_Max(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y){
        return Max[rt];
    }
    int mid = (l+r)>>1;
    int ans = 0;
    if(x <= mid) ans = max(ans,Query_Max(l,mid,x,y,rt<<1));
    if(y > mid) ans = max(ans,Query_Max(mid+1,r,x,y,rt<<1|1));
    return ans;
}
int Query_Min(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y){
        return Min[rt];
    }
    int mid = (l+r)>>1;
    int ans = inf;
    if(x <= mid) ans = min(ans,Query_Min(l,mid,x,y,rt<<1));
    if(y > mid) ans = min(ans,Query_Min(mid+1,r,x,y,rt<<1|1));
    return ans;
}
int main()
{
    mem(Max,0);
    mem(Min,0x3f);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    Build(1,n,1);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        int sub = Query_Max(1,n,l,r,1) - Query_Min(1,n,l,r,1);
        printf("%d\n",sub);
    }
    return 0;
}
/*
Sample Input
6 3
1
7
3
4
2
5
1 5
4 6
2 2
Sample Output
6
3
0
*/