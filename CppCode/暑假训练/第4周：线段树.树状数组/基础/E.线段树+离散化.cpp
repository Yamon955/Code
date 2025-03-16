//HDU 3333
// 首先把所有查询区间记录下来，然后按照区间的右值排序，接着从左到右把每一个数更新到线段树中，并记录它出现的位置。
// 如果一个数已经出现过，那么我们就把他上次出现的位置的值置为0，并更新它出现的位置。因为查询区间是按右值排序的，
// 所以当前区间的左值要么和之前一样要么比之前的要大，因此把过去重复出现的数字置为0不会影响结果。
// 当更新到某个区间的右值时，我们就查询一次该区间的答案，并把答案记录到对应的地方。

//先把区间信息读进来，然后以右端点排序，然后离线处理每一个区间信息，同时用一个map来维护一个数值x最后一次出现的位置。
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
const int M = 1e5+5;
int n,m,T,a[N];
ll tree[N*4],lazy[N*4];  //不要忘了开四倍空间
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
    return a.idx < b.idx;
}
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void pushDown(int l,int r,int rt)
{
    if(lazy[rt]!=-1){
        int mid = (l+r)>>1;
        tree[rt<<1] = lazy[rt]*(mid-l+1);
        tree[rt<<1|1] = lazy[rt]*(r-mid);
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = -1; // -1 为空标志
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
        tree[rt] = c*(r-l+1);
        lazy[rt] = c;
        return;
    }
    pushDown(l,r,rt);
    int mid = (l+r)>>1;
    if(x <= mid) update(l,mid,x,y,c,rt<<1);
    if(y > mid) update(mid+1,r,x,y,c,rt<<1|1);
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
    if(x <= mid) ans += Query(l,mid,x,y,rt<<1);
    if(y > mid)  ans += Query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        mem(tree,0);
        mem(a,0);
        mem(lazy,-1);  //lazy 标记全部初始化为 -1
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        Build(1,n,1); //建树
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&p[i].l,&p[i].r);
            p[i].idx = i; //记录原来的操作顺序
        }
        map<int,int>vis;  //记录每个值出现的位置
        sort(p+1,p+m+1,cmp1);
        int j = 1;
        for(int i=1;i<=m;i++){
            while(j <= p[i].r){  ///j是一个指针，指示原数组的下标，vis[ a[j] ]则是对应a[j]这个值上次出现的位置
                if(vis.count(a[j])==0){ //如果a[j]这个值没有出现过
                    vis[a[j]] = j;   //记录 a[j] 出现的位置 
                }
                else{  //如果a[j]这个值之前出现过
                    update(1,n,vis[a[j]],vis[a[j]],0,1); //则把之前位置vis[a[j]]上的 a[j] 置为0
                    vis[a[j]] = j; //记录 a[j] 新的位置
                }
                j++; //遍历下一个位置
            }
            p[i].ans = Query(1,n,p[i].l,p[i].r,1);  //得出 [p[i].l,p[i].j] 的区间和
        } 
        sort(p+1,p+m+1,cmp2);  //按照 idx 值排序，回到原来的操作请求顺序
        for(int i=1;i<=m;i++){
            printf("%lld\n",p[i].ans);  //按顺序输出每个操作请求的答案
        }

    }
    return 0;
}
/*
Sample Input
2
3
1 1 4
2
1 2
2 3
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output
1
5
6
3
6
*/