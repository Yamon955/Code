//HDU-1540
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
int n,m;
struct SegTree{
    int lmax,rmax;//lmax,包含左端点的最大连续区间，rmax包含右端点最大连续区间，
    int sum; //sum区间内最大连续区间
};
SegTree tree[N<<2];
void pushup(int l,int r,int rt)
{
    int mid = (l+r)>>1;

    tree[rt].lmax = tree[rt<<1].lmax;
    if(tree[rt<<1].lmax == mid-l+1)  //如果左区间的前缀数是等于他本身的大小的,说明完全是满的,所以合并后区间的前缀是左区间的连续前缀(大小)加上右区间的连续前缀
        tree[rt].lmax += tree[rt<<1|1].lmax;

    tree[rt].rmax = tree[rt<<1|1].rmax;
    if(tree[rt<<1|1].rmax == r-mid)//后缀同理
        tree[rt].rmax += tree[rt<<1].rmax;

    ////最大连续长度是 1.左儿子最大长 2.右儿子最大长 3.左儿子右边界+右儿子左边界最大长 中最大的一个
    tree[rt].sum = max(max(tree[rt<<1].lmax,tree[rt<<1|1].rmax),tree[rt<<1].rmax+tree[rt<<1|1].lmax);

}
void build(int l,int r,int rt)
{
    if(l == r) {
        tree[rt].lmax = tree[rt].rmax = tree[rt].sum = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(l,r,rt);
}
void update(int l,int r,int pos,int c,int rt)//c为1代表该点恢复,c为0代表该点断开
{
    if(l == r){
        tree[rt].lmax = tree[rt].rmax = tree[rt].sum = c;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid) update(l,mid,pos,c,rt<<1);
    else update(mid+1,r,pos,c,rt<<1|1);
    pushup(l,r,rt);
}
int query(int l,int r,int pos,int rt)
{
    //叶子结点 或 完全连续 或 完全不连续 直接返回
    if(l == r || tree[rt].sum == r-l+1 || tree[rt].sum ==0) return tree[rt].sum;
    int mid = (l+r)>>1;
    // if(pos <= mid)
            ////因为pos<=mid，看左子树，mid-tree[rt<<1].rmax+1代表左子树右边连续区间的左边界值，如果t在左子树的右区间内，则要看右子树的左区间有多长并返回
    //     if(pos >= mid-tree[rt<<1].rmax+1) return tree[rt<<1].rmax + tree[rt<<1|1].lmax;
    //     else return query(l,mid,pos,rt<<1);  //如果不在左子树的右边界区间内，则只需要看左子树
    // else{ //在右子树 同理
    //     if(pos <= mid+tree[rt<<1|1].lmax) return tree[rt<<1].rmax+tree[rt<<1|1].lmax;
    //     else return query(mid+1,r,pos,rt<<1|1);
    // }

    //中间地带为 [mid-tree[rt<<1].rmax+1 , mid+tree[rt<<1|1].lmax] 此区间内的所有点都是相连的，故直接返回 tree[rt<<1].rmax+tree[rt<<1|1].lmax --->即区间内所有点的个数 即可
    //中间地带即 以 mid 为结尾的左孩子的最大后缀连续区间 rmax 和 以 mid+1 为开头的右孩子的最大前缀连续区间 lmax 组成的区间，此区间一定是连续的
    if(pos < mid-tree[rt<<1].rmax+1) return query(l,mid,pos,rt<<1);//在中间地带左侧
    if(pos > mid+tree[rt<<1|1].lmax) return query(mid+1,r,pos,rt<<1|1);//在中间地带右侧
    return tree[rt<<1].rmax+tree[rt<<1|1].lmax;//在中间地带直接返回加和
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        stack<int>st;
        build(1,n,1);
        while(m--){
            char op[5];
            int x;
            scanf("%s",op);
            if(op[0] == 'D'){
                scanf("%d",&x);
                st.push(x);
                int c = 0;
                update(1,n,x,c,1);  //c == 0 代表摧毁 x
            }
            else if(op[0] == 'Q'){
                scanf("%d",&x);
                cout<<query(1,n,x,1)<<endl;
            }
            else{
                x = st.top();
                st.pop();
                int c = 1;  //c == 1 代表重建 x
                update(1,n,x,c,1);
            }
        }
    }
    return 0;
}
/*
Sample Input
7 9
D 3
D 6
D 5
Q 4
Q 5
R
Q 4
R
Q 4
Sample Output
1
0
2
4
*/