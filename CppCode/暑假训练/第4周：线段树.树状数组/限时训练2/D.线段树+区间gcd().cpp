//CodeForces - 914D
// 线段树维护gcd，很简单。查询的时候可以维护一个cnt的值，表示为当一个点的值不整除x的时候，对数进行改变的个数。
//当cnt>1的时候，直接结束函数。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e5;
int n,q;
int tree[N<<2];
int a[N];
int cnt;
int gcd(int x,int y)
{
    if(y != 0) return gcd(y,x%y);
    else return x;
}
void pushUp(int rt)
{
    tree[rt] = gcd(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l == r){
        tree[rt] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
void update(int l,int r,int idx,int c,int rt)
{
    if(l == r){
        tree[rt] = c;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) 
        update(l,mid,idx,c,rt<<1);
    else    
        update(mid+1,r,idx,c,rt<<1|1);
    pushUp(rt);
}
void find(int l,int r,int x,int rt)
{
    if(cnt > 1) return;
    if(l == r){
        if(tree[rt] % x)
            cnt ++;
        return;
    }
    int mid = (l+r)>>1;
    if(tree[rt<<1] % x)
        find(l,mid,x,rt<<1);
    if(tree[rt<<1|1] % x)
        find(mid+1,r,x,rt<<1|1);
}
void query(int l,int r,int x,int y,int c,int rt)
{
    if(x<=l && r<=y){
        if(tree[rt] % c){
            find(l,r,c,rt);
            return ;
        }
        return ;
    }
    int mid = (l+r)>>1;
    //int ret = 0;
    if(x <= mid) 
        query(l,mid,x,y,c,rt<<1);
    if(y > mid)
        query(mid+1,r,x,y,c,rt<<1|1);
    //return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    scanf("%d",&q);
    int op,l,r,x;
    while(q--){
        scanf("%d",&op);
        if(op == 1){
            scanf("%d%d%d",&l,&r,&x);
            cnt = 0;
            query(1,n,l,r,x,1);
            if(cnt > 1) printf("NO\n");
            else printf("YES\n");
        }
        else{
            scanf("%d%d",&l,&x);
            if(a[l] == x) continue;
            a[l] = x;
            update(1,n,l,x,1);
        }
    }
    return 0;
}
/*
Sample Input
5
1 2 3 4 5
6
1 1 4 2
2 3 6
1 1 4 2
1 1 5 2
2 5 10
1 1 5 2
Sample Output
NO
YES
NO
YES
*/