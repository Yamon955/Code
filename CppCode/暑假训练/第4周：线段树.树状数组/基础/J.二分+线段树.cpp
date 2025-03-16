//HDU 4614
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
const int N = 5e4+5;
int n,m,T;
int tree[N*4],lazy[N*4];  //不要忘了开四倍空间
//线段树模板，tree[]维护的是有花的花瓶数量
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void pushDown(int l,int r,int rt)
{
    if(lazy[rt]){
        int mid = (l+r)>>1;
        tree[rt<<1] = (lazy[rt]-1)*(mid-l+1);
        tree[rt<<1|1] = (lazy[rt]-1)*(r-mid);
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    if(l==r){
        tree[rt] = 0;
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
void updata(int l,int r,int x,int y,int c,int rt)
{
    if(x<=l && r<=y){
        tree[rt] = c*(r-l+1);
        lazy[rt] = c+1;
        return;
    }
    pushDown(l,r,rt);
    int mid = (l+r)>>1;
    if(x <= mid) updata(l,mid,x,y,c,rt<<1);
    if(y > mid) updata(mid+1,r,x,y,c,rt<<1|1);
    pushUp(rt);

}
int Query(int l,int r,int x,int y,int rt)  //查找花瓶[x,y]中花的数量
{
    if(x<=l && r<=y){
        return tree[rt];
    }
    pushDown(l,r,rt);
    int mid = (l+r)>>1;
    int ans = 0;
    if(x <= mid) ans += Query(l,mid,x,y,rt<<1);
    if(y > mid)  ans += Query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
//二分查找
int Binary_Search(int ll,int rr,int x)  //二分查找第 x 个空花瓶的位置
{
    int l = ll,r = rr;
    while(l<=r){
        int mid = (l+r)>>1;
        if(mid-ll+1-Query(1,n,ll,mid,1) >=x){  //mid-ll+1-Query(1,n,ll,mid,1)-->表示的是[ll,mid]中空瓶子的数量
            r = mid-1;                          //计算的区间一定是[ll,mid]而不是[l,mid];
        }
        else l = mid+1;
    }
    return l;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        mem(tree,0);
        mem(lazy,0);
        scanf("%d%d",&n,&m);
        Build(1,n,1);
        for(int i=1;i<=m;i++){
            int k,a,b;
            scanf("%d%d%d",&k,&a,&b);  
            if(k==2){
                cout<<Query(1,n,a+1,b+1,1)<<endl;  //输出[a+1,b+1]中花的数量
                updata(1,n,a+1,b+1,0,1);  //将[a+1,b+1]中所有花瓶的花丢弃，即全部置为 0
            }
            else if(k==1){
                int cnt = n-a-Query(1,n,a+1,n,1);//求出[a+1,n]中空瓶子的数量
                if(cnt == 0) printf("Can not put any one.\n"); //没有空瓶子来插花
                else{
                    //二分得到第一个出现空瓶子的位置
                    int l_pos = Binary_Search(a+1,n,1);  //找出[a+1,n]中第一个空瓶子的位置
                    //二分得到符合条件的最后一个出现空瓶子的位置
                    int r_pos = Binary_Search(a+1,n,min(b,cnt)); //找出[a+1,n]中第 min(b,cnt) 个空瓶子的位置
                                                            //如果 b>cnt  表示要插的花的数量大于空花瓶的数量(花插不完)   最后一个要插的空花瓶为第 cnt 个
                                                            //如果 cnt>b  表示空花瓶的数量大于要插的花的数量(插完所有花) 最后一个要插的空花瓶为第 b 个
                    updata(1,n,l_pos,r_pos,1,1);  //将区间[l_pos,r_pos]中所有花瓶插上花，即全部置为 1
                    printf("%d %d\n",l_pos-1,r_pos-1);
                }

            }
        }
        printf("\n");
    }
    return 0;
}
/*
Sample Input
2
10 5
1 3 5
2 4 5
1 1 8
2 3 6
1 8 8
10 6
1 2 5
2 3 4
1 0 8
2 2 5
1 4 4
1 2 3
Sample Output
[pre]3 7
2
1 9
4
Can not put any one.

2 6
2
0 9
4
4 5
2 3
*/