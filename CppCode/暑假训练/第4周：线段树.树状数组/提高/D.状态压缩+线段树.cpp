//POJ 2777
// 由于颜色最多有30种，所以我们可以用二进制上的每一位来表示一种颜色。
// 将2个区间进行合并的时候采取 或操作， 就可以得到2个区间颜色种类的总和。
// 最后将查询到的结果进行计数，统计二进制一共有多少个1。
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
int n,t,m;
ll tree[N<<2],lazy[N<<2];
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1] | tree[rt<<1|1];
}
void pushDown(int l,int r,int rt)
{
    if(lazy[rt]){
        tree[rt<<1] = lazy[rt];
        tree[rt<<1|1] = lazy[rt];
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    if(l == r){
        tree[rt] = 1; //初始全部染上 1 号色，即 0 号色，所以让第 0 位为 1
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
void update(int l,int r,int x,int y,int c,int rt) //[x,y]区间全部涂上颜色 c，
{                                                //c的取值范围是 1~30,我们将他全部减 1 取值变为 0~29,这样方便状态压缩
                                                 //染上颜色 c ，我们就让二进制对应的第 c-1 位为 1，即 1<<(c-1)
    if(x<=l && r<=y){
        //状态压缩  
        tree[rt] = 1<<(c-1); //这里要左移 c-1 位
        lazy[rt] = 1<<(c-1);
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
    if(x <= mid) 
        ans |= Query(l,mid,x,y,rt<<1);
    if(y > mid)
        ans |= Query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
int getNum(ll x)  //获取 x 的二进制表示中 1 的个数即不同颜色的个数(每一位都代表一种颜色)
{
    int ans = 0;
    while(x){
        if(x%2) ans++;
        x /= 2;
    }
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&t,&m);
    Build(1,n,1);
    while(m--){
        char op[2];
        int a,b,c;
        scanf("%s",op);
        if(op[0] == 'C'){
            scanf("%d%d%d",&a,&b,&c);
            int l = min(a,b);
            int r = max(a,b);
            update(1,n,l,r,c,1);
        }
        else if(op[0] == 'P'){
            scanf("%d%d",&a,&b);
            int l = min(a,b);
            int r = max(a,b);
            int num = Query(1,n,l,r,1);
            printf("%d\n",getNum(num));
        }
    }
    return 0;
}
/*
Sample Input
2 2 4
C 1 1 2
P 1 2
C 2 2 2
P 1 2
Sample Output
2
1
*/