//HDU 4027
// 首先这题想到的是成段更新成段查询,但是我们用的懒惰标记这里用不了,因为懒惰标记并不是一个确定的值,因此传不下去.
// 这里呢我们就对update做更改,让其每一次的update都能够走完整棵树,这样就用不到懒惰标记了.但是,这样会超时,
// 于是我们就想一下有没有办法进行剪枝.当我们查询到某个全包含区间的值都是1的时候,这时开根操作就没有必要进行了.我们直接返回.这里很关键,如果不加会超时.

//此次区间操作并不是加上一个数或者全改成一个数，每个数的变化都不同，所以无法用懒惰标记，直接在找到叶子结点操作即可，因此不需要lazy[]懒标记和pushDown()函数
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
int T,n,m;
ll a[N];
ll tree[N<<2];
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void Build(int l,int r,int rt)
{
    if(l == r){
        tree[rt] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
//此次区间操作并不是加上一个数或者全改成一个数，每个数的变化都不同，所以无法用懒惰标记，直接在找到叶子结点操作即可，因此不需要lazy[]懒标记和pushDown()函数
void update(int l,int r,int x,int y,int rt)
{
    //当我们查询到某个全包含区间的值都是1的时候,这时开根操作就没有必要进行了.我们直接返回.这里很关键,如果不加会超时
    if(x<=l && r<=y && tree[rt] == r-l+1) return; //如果该区间包含的叶子结点值全部为 1，直接返回即可
    if(l == r){
        tree[rt] = sqrt(1.0*tree[rt]);  //当 tree[rt]==1时，此值将会一直为 1
        return;
    }
    int mid = (l+r)>>1;
    if(x <= mid) update(l,mid,x,y,rt<<1);
    if(y > mid)  update(mid+1,r,x,y,rt<<1|1);
    pushUp(rt);
}
ll Query(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y){
        return tree[rt];
    }
    int mid = (l+r)>>1;
    ll ans = 0;
    if(x <= mid) 
        ans += Query(l,mid,x,y,rt<<1);
    if(y > mid)
        ans += Query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
int main()
{
    int cnt = 0;
    while(scanf("%d",&n)!=EOF){
        mem(tree,0);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        Build(1,n,1);
        scanf("%d",&m);
        printf("Case #%d:\n",++cnt);
        while(m--){
            int op,a,b;
            scanf("%d%d%d",&op,&a,&b); //输入的区间端点不一定满足 a < b 

            int l = min(a,b);
            int r = max(a,b);
            if(op == 0){
                update(1,n,l,r,1);
            }
            else if(op == 1){
                printf("%lld\n",Query(1,n,l,r,1));
            }
        }
       printf("\n");//每组数据都要换行
//每个样例后面如果不输出空行在OJ平台上会提示  Presentation Error。
// 1.思路是对的，且运行时间符合要求
// 2.答案和标准结果非常接近，也就是说最可能是因为，在输出结果中，多了或少了不必要的空格或者回车或者其他，
//总而言之，OJ平台对格式的检查非常严格，所以一定要认真检查程序的输出结果是否与标准一致。

    }
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
5
0 1 10
1 1 10
1 1 5
0 5 8
1 4 8
Sample Output
Case #1:
19
7
6
*/