//如果只涉及单点修改，不需要 lazy[] 惰性标记，不需要 pushDown() 向下传送
//因为修改的位置就是叶子节点，只 pushUp() 向上维护线段树即可
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
int T,n,m,mod; 
int tree[N<<2];  
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
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
void update(int l,int r,int idx,int c,int rt) // idx代表要修改的结点在[l,r]内位置
{
    if(l == r){  //单点修改
        tree[rt] = c;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) update(l,mid,idx,c,rt<<1);
    else update(mid+1,r,idx,c,rt<<1|1);
    pushUp(rt);
}