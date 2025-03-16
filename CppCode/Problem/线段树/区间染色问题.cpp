//1OJ 1610
//此题数据范围较小 直接暴力也可以做
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
const int N = 8e3+5;
int n,m;
int tree[N<<2],ans[N],lazy[N<<2],num[N];
void pushdown(int rt)
{
    if(lazy[rt] != -1){
        tree[rt<<1] = tree[rt<<1|1] = lazy[rt];
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;
    }
}
void build(int l,int r,int rt)
{
    tree[rt] = -1;  //区间内没有颜色或者有多种颜色都置为 -1
    if(l == r) return;
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
void update(int l,int r,int x,int y,int c,int rt)
{
    if(x <= l && r <= y){
        tree[rt] = c;
        lazy[rt] = c;
        return;
    }
    pushdown(rt);
    int mid = (l+r)>>1;
    if(x <= mid) update(l,mid,x,y,c,rt<<1);
    if(y > mid) update(mid+1,r,x,y,c,rt<<1|1);

}
void query(int l,int r,int rt)
{
    if(l == r){
        ans[l] = tree[rt];
        return;
    }
    pushdown(rt);
    int mid = (l+r)>>1;
    query(l,mid,rt<<1);
    query(mid+1,r,rt<<1|1);
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        mem(lazy,-1);
        mem(ans,-1);
        mem(num,0);
        build(1,8001,1);

        while(n --){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            x++;
            update(1,8000,x,y,c,1);
        }
        query(1,8000,1);
        for(int i=0;i<=8000;i++){
            while(ans[i] == ans[i+1]) i++;
            if(ans[i] != -1) num[ans[i]]++;
            
        }
        for(int i=0;i<=8000;i++){
            if(num[i] > 0) printf("%d %d\n",i,num[i]);
        }
        cout<<endl;
    }
}
/*
Sample Input

5
0 4 4
0 3 1
3 4 2
0 2 2
0 2 3
4
0 1 1
3 4 1
1 3 2
1 3 1
6
0 1 0
1 2 1
2 3 1
1 2 0
2 3 0
1 2 1


Sample Output

1 1
2 1
3 1

1 1

0 2
1 1
*/