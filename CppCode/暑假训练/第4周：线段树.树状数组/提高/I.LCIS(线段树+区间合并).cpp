//HDU 3308
//https://blog.csdn.net/qq_41713256/article/details/80508611
// 父节点的最长连续上升序列难道就是两个子节点的最大值吗？ 肯定不是，中间那个点肯定会有影响的。

// 那么我们应该维护区间的三个信息。
// 区间的最长连续上升序列，tree[]
// 区间头为起点的最长连续上升序列le[]
// 以区间尾为终点的最长连续上升序列ri[]
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
int tree[N<<2],le[N<<2],ri[N<<2]; //这三个数组的意义很重要
// 区间的最长连续上升序列，tree[]
// 区间头为起点的最长连续上升序列le[]
// 以区间尾为终点的最长连续上升序列ri[]
int a[N];
void pushUp(int l,int r,int rt)
{
    le[rt] = le[rt<<1];
    ri[rt] = ri[rt<<1|1];
    tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
    int mid = (l+r)>>1;
    if(a[mid] < a[mid+1]){  //好好揣摩一下这个条件
        if(le[rt] == mid-l+1)  //当前 rt 的左区间内所有点都是连续上升的，如果 a[mid] < a[mid+1]
            le[rt] += le[rt<<1|1]; //那么当前的 rt 左区间以区间头(即a[mid])为起点的连续上升序列 le[rt] 就可以加上其右区间以区间头(即a[mid+1])为起点的连续上升序列le[rt<<1|1]
                                    // le[rt] + le[rt<<1|1] 仍然是连续上升的
        if(ri[rt] == r-mid)  //当前 rt 的右区间内所有点都是连续上升的，如果 a[mid] < a[mid+1]
            ri[rt] += ri[rt<<1];  //那么当前的 rt 右区间以区间尾(即a[mid+1])为终点的连续上升序列 ri[rt] 就可以加上其左区间以区间尾(即a[mid])为终点的连续上升序列ri[rt<<1|1]

        //更新 左区间以 a[mid] 为终点的连续上升序列 + 右区间以 a[mid+1] 为头的连续上升序列 --> ri[rt<<1]+le[rt<<1|1] 相加仍然是连续上升的
        tree[rt] = max(tree[rt],ri[rt<<1]+le[rt<<1|1]);
    }
}
void Build(int l,int r,int rt)
{
    if(l == r){
        tree[rt] = le[rt] = ri[rt] = 1; //都初始化为 1
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(l,r,rt);
}
void update(int l,int r,int pos,int rt)
{
    if(l == r) return;
    int mid = (l+r)>>1;
    if(pos <= mid) update(l,mid,pos,rt<<1);
    else update(mid+1,r,pos,rt<<1|1);
    pushUp(l,r,rt);
}
int Query(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y) return tree[rt];
    int mid = l+r>>1;
    if(y <= mid) return Query(l,mid,x,y,rt<<1); //如果区间全在左儿子中，
    if(x > mid)  return Query(mid+1,r,x,y,rt<<1|1);//如果区间全在右儿子中
    
    //最后就是左右儿子都有。那么先取左右儿子的最大值，在考虑中间的情况。
    int t1 = Query(l,mid,x,y,rt<<1);
    int t2 = Query(mid+1,r,x,y,rt<<1|1);
    int ans = max(t1,t2);
    if(a[mid] < a[mid+1]){
        ans = max(ans,min(ri[rt<<1],mid-x+1)+min(le[rt<<1|1],y-mid));
        //对于左儿子 min( ri[root<<1],mid-x+1)，这里要说明一下为什么不是直接取ri[root<<1],因为 x 不一定能达到 l 的位置，还有就是 x 是不可能超过 l 的。
        //对于右儿子同理
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        Build(1,n,1);
        while(m--){
            char op[2];
            int l,r;
            scanf("%s%d%d",op,&l,&r);
            l++;
            if(op[0] == 'Q'){
                r++;
                printf("%d\n",Query(1,n,l,r,1));
            }
            else{
                a[l] = r;
                update(1,n,l,1);
            }
        }
    }
    return 0;
}
/*
Sample Input
1
10 10
7 7 3 3 5 9 9 8 1 8 
Q 6 6
U 3 4
Q 0 1
Q 0 5
Q 4 7
Q 3 5
Q 0 2
Q 4 6
U 6 10
Q 0 9
Sample Output
1
1
4
2
3
1
2
5
*/