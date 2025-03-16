//HDU 2795
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
int h,w,n;
ll tree[N<<2];
int ans[N];
// 线段树维护一段区间内剩余长度的最大值。
void pushUp(int rt)
{
    tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
}
void Build(int l,int r,int rt)
{
    if(l == r){
        tree[rt] = w;   //最初板上没有公告
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
int update(int l,int r,int val,int rt)
{
    if(tree[rt] < val){  //如果放不下，返回 -1，这个条件就只可能会在函数调用开始成立，如果进入函数的递归该条件一定不会成立
        return -1;                  //因为如果进入函数的递归则表明一定会有一块地方放下海报
    }
    if(l == r && tree[rt] >= val){
        tree[rt] -= val;
        return l;
    }
    int mid = (l+r)>>1;
    int ans;
    if(tree[rt<<1] >= val)   //要优先对左子树进行操作因为左子树的区间更小即在海报板偏上方。
        ans = update(l,mid,val,rt<<1);
    else if(tree[rt<<1|1] >= val)
        ans = update(mid+1,r,val,rt<<1|1);
    pushUp(rt);
    return ans;
}
int main()
{
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        mem(tree,0);
        int len = min(h,n);  //h有时会很大因为范围是1e9,但是最大只能达到n按一行一个海报算
        Build(1,len,1);
        for(int i=1;i<=n;i++){
            int val;
            scanf("%d",&val);
            printf("%d\n",update(1,len,val,1));
        }
    }
    return 0;
}
/*
3 5 5
2
4
3
3
3
Sample Output
1
2
1
3
-1
*/