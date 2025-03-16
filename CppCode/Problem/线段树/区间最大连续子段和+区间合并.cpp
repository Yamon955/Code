//Acwing-245
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
const int N = 5e5+5;
int n,m;
int a[N];
struct SegTree
{
	int data;//区间最大连续字段和  
	int sum,lmax,rmax;//区间和  区间最大前缀和  区间最大后缀和 
}tree[N<<2];
void pushup(int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum; //区间总和
    tree[rt].lmax = max(tree[rt<<1].lmax,tree[rt<<1].sum+tree[rt<<1|1].lmax);//前缀和 max(左子区间前缀和，左子区间总和+右子区间前缀和)
    tree[rt].rmax = max(tree[rt<<1|1].rmax,tree[rt<<1|1].sum+tree[rt<<1].rmax);//后缀和 max(右子区间后缀和，右子区间总和+左子区间后缀和)
    tree[rt].data = max(max(tree[rt<<1].data,tree[rt<<1|1].data),tree[rt<<1].rmax+tree[rt<<1|1].lmax);//区间最大值 max(左子区间前缀和，右子区间后缀和，(左子区间后缀和+右子区间前缀和))
}
void build(int l,int r,int rt) //建树
{
    if(l == r){
        tree[rt].data = tree[rt].sum = tree[rt].lmax = tree[rt].rmax = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void update(int l,int r,int pos,int c,int rt)//修改
{
    if(l == r){
        tree[rt].data = tree[rt].sum = tree[rt].lmax = tree[rt].rmax = c;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid) update(l,mid,pos,c,rt<<1);
    else update(mid+1,r,pos,c,rt<<1|1);
    pushup(rt);
}
SegTree query(int l,int r,int x,int y,int rt)//查询，由于存在跨左右子区间的情况，返回结构体类型
{
    if(x <= l && r <= y){ //如果当前区间在查询区间内
        return tree[rt];
    }
    int mid = (l+r)>>1;
    if(y <= mid) return query(l,mid,x,y,rt<<1);
    else if(x > mid) return query(mid+1,r,x,y,rt<<1|1);
    else{  //有跨子区间的情况，处理左右子区间
        SegTree left = query(l,mid,x,y,rt<<1);
        SegTree right = query(mid+1,r,x,y,rt<<1|1);
        SegTree ans;  //ans看作left和right的父区间
        //处理同 pushup 中的一样
        ans.sum = left.sum + right.sum;
        ans.lmax = max(left.lmax,left.sum+right.lmax);
        ans.rmax = max(right.rmax,right.sum+left.rmax);
        ans.data = max(max(left.data,right.data),left.rmax+right.lmax);
        return ans;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    while(m --){
        int op,x,y;
        cin>>op>>x>>y;
        if(op == 1){
            if(x > y) swap(x,y);
            SegTree ans = query(1,n,x,y,1);
            cout<<ans.data<<endl;
        }
        else{
            update(1,n,x,y,1);
        }
    }
    return 0;

}
/*
输入样例：
5 3
1 2 -3 4 5
1 2 3
2 2 -1
1 3 2
输出样例：
2
-1
*/