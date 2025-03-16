//https://www.cnblogs.com/LonecharmRiver/articles/9087536.html
//主席树---->求静态区间第 k 小(大)
//洛谷P3834 -->求区间第 k 小
//poj 2104
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
const int N = 1e6+5;
int node_cnt,n,m;
int root[N];
int sum[N<<5],ls[N<<5],rs[N<<5];  //一定要开20倍往上
int a[N],b[N],len;//用于离散化  原序列a[]   离散序列b[]   a[]去重以后的个数len  对于a[]和b[]为了节省空间也可以用 vector 数组
int Build(int l,int r)  //初始时建一棵线段树
{
    int root = ++node_cnt; //新开结点
    if(l==r) return root;
    int mid = (l+r)>>1;
    ls[root] = Build(l,mid);   //创建左子节点
    rs[root] = Build(mid+1,r); //创建右子节点
    return root;  //返回根节点标记以存储至rt中
}
int update(int l,int r,int pre,int pos) //pre 表示新建树链的前一条树链，pos 表示要插入的数的大小(即位置)
{
    int rt = ++node_cnt;  //新开一个结点,来新建一条树链
    //先复制原树，后续递归更改
    ls[rt] = ls[pre]; //左右子节点的信息相同
    rs[rt] = rs[pre];
    sum[rt] = sum[pre]+1;  //修改维护信息--->对于不同题这里的修改情况不同
    
    if(l==r) return rt;
    int mid = (l+r)>>1;
    if(pos <= mid) //根据要插入数的大小(位置)来更新左树或右树
        ls[rt] = update(l,mid,ls[pre],pos);  //维护左子树
    else         
        rs[rt] = update(mid+1,r,rs[pre],pos);  //维护右子树
    return rt; //返回新建的树链的根节点，存储在 root[] 中
}
// 区间查询：返回的时答案在离散化数组中的编号
// 注意在查询右子树时要注意减去当前查询到的比它大的数的个数
int Query(int l,int r,int x,int y,int k)  //查询[x,y]区间第 k 大的数
{
    int mid = (l+r)>>1;
    int w = sum[ls[y]] - sum[ls[x]]; //表示左枝数的个数
    if(l==r) return l; //找到目标位置

    int ans;
    if(k <= w)  //w 是左枝从最小开始的 w 个不同的数，k<=x表示第 k 大的数一定在左枝上
        ans = Query(l,mid,ls[x],ls[y],k);
    else    //否则则是右枝第 k-w 位，因为左枝已经有 w 个数比它小了，所以需要减去，在右区间不需要找满 k 个
        ans = Query(mid+1,r,rs[x],rs[y],k-w);
    return ans;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i];
    }

    //离散化
    sort(b+1,b+n+1);
    len = unique(b+1,b+n+1)-b-1;//unique 的作用是去重，len 是去重后的数组有多少个数。
    root[0] = Build(1,len);
    for(int i=1;i<=n;i++){   //这里注意 i<=n 而不是 i<=len
        int pos = lower_bound(b+1,b+1+len,a[i])-b;
        root[i] = update(1,len,root[i-1],pos);
        //每插入一个数都会创建一条树链，root[i] 存储插入数 i(对应原数组的数b[i]) 所产生树链的根节点
    }

    int l,r,k;
    while(m--){
        cin>>l>>r>>k;
        int w = Query(1,len,root[l-1],root[r],k);
        printf("%d\n",b[w]);
    }
    return 0;
}
/*
5 5
25957 6405 15770 26287 26465 
2 2 1
3 4 1
4 5 1
1 2 2
4 4 1

output:
6405
15770
26287
25957
26287
*/