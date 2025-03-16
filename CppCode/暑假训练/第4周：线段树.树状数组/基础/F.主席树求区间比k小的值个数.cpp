//HDU 4417
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
int T,n,m,node_cnt;
int a[N],b[N],len;
int root[N];
int ls[N<<4],rs[N<<4],sum[N<<4];
int Build(int l,int r)
{
    int rt = ++node_cnt; //新开结点
    if(l==r) return rt;

    int mid = (l+r)>>1;
    ls[rt] = Build(l,mid);
    rs[rt] = Build(mid+1,r);
    return rt; //返回根节点标记以存储至root中
}
int update(int l,int r,int pre,int pos)
{
    int rt = ++node_cnt;
    ////先复制原树，后续更改！
    ls[rt] = ls[pre];  
    rs[rt] = rs[pre];
    sum[rt] = sum[pre]+1; //维护

    if(l==r) return rt;
    int mid = (l+r)>>1;
    if(pos <= mid)  //根据插入数的大小来更新左或右
        ls[rt] = update(l,mid,ls[rt],pos);
    else 
        rs[rt] = update(mid+1,r,rs[rt],pos); 
    return rt;
}
int Query(int l,int r,int x,int y,int k)
{   //查询[x,y]区间中所有小于k的值
    if(r <= k){ //这玩意大于所有区间最大值了 一定符合
        return sum[y] - sum[x];
    }
    int mid = (l+r)>>1;
    int ans = 0;
    //注意这里求 ans 有所不同
    if(k >= l){
        ans += Query(l,mid,ls[x],ls[y],k);
    }
    if(k >= mid+1) ans += Query(mid+1,r,rs[x],rs[y],k);
    return ans;
}
int main()
{
    scanf("%d",&T);
    int cnt = 0;
    while(T--){
        mem(a,0);
        mem(b,0);
        mem(sum,0);
        mem(ls,0);
        mem(rs,0);
        node_cnt = 0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        //离散化
        sort(b+1,b+n+1);
        len = unique(b+1,b+n+1)-b-1;  //去重
        root[0] = Build(1,len);
        for(int i=1;i<=n;i++){  //这里注意 i<=n 而不是 i<=len
            int pos = lower_bound(b+1,b+len+1,a[i])-b;
            root[i] = update(1,len,root[i-1],pos);
        }
        int l,r,k;
        cout<<"Case "<<(++cnt)<<":"<<endl;
        while(m--){
            scanf("%d%d%d",&l,&r,&k);
            l++;
            r++;
            int pos = upper_bound(b+1,b+len+1,k)-b-1; 
            //upper_bound(b+1,b+len+1,k)-b --->得出的是数组 b[] 中第一个大于 k 的元素下标，而该值减 1 之后得到的是 b[] 中小于等于 k 的最后一个元素的下标
            cout<<Query(1,len,root[l-1],root[r],pos)<<endl;
        }
    }
    return 0;
}
/*
Sample Input
1
10 10
0 5 2 7 5 4 3 8 7 7 
2 8 6
3 5 0
1 3 1
1 9 4
0 1 0
3 5 5
5 5 1
4 6 3
1 5 7
5 7 3
Sample Output
Case 1:
4
0
0
3
1
2
0
1
5
1
*/