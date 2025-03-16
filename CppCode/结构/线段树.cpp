#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int a[1000];
int tree[4000];  //开四倍空间
/*
简单的记法： 足够的空间 = 数组大小n的四倍。
实际上足够的空间 =  （n向上扩充到最近的2的某个次方）的两倍。
举例子：假设数组长度为5，就需要5先扩充成8，8*2=16.线段树需要16个元素。如果数组元素为8，那么也需要16个元素。
所以线段树需要的空间是n的两倍到四倍之间的某个数，一般就开4*n的空间就好，如果空间不够，可以自己算好最大值来省点空间。
*/
//  l,r说的是数组 a 的下标    rt代表的是线段树数组 tree 的下标
void PushUp(int rt) //PushUp函数更新节点信息，这里是求和,即当前下标为rt的元素值为其左右两个孩子之和
{
    tree[rt] = tree[rt*2]+tree[rt*2+1];  //节点 rt 的左右孩子节点的下标分别为 2*rt，2*rt+1   如果数组下标从 0 开始的话节点 rt 的左右孩子节点下标为 2*rt+1，2*rt+2
}
void Build(int l,int r,int rt) //建立线段树  ， [l,r]表示当前节点区间，rt表示当前节点的实际存储位置 
{                              //tree[rt] = a[l]+a[l+1]+...+a[r]
    if(l==r){  //递归出口       //l==r时  tree[rt] = a[l] =a[r]
        tree[rt] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    // int rt_left = rt>>1;
    // int rt_right = rt>>1|1;
    Build(l,mid,rt<<1);     //Build(l,mid,rt*2)      //处理左半部分区间
    Build(mid+1,r,rt<<1|1); //Build(l,mid,rt*2+1)    //处理左半部分区间
    PushUp(rt);  //自下而上的更新每个节点的值

}
// (2)点修改：
// 假设a[L]+=C:
void Update(int L,int c,int l,int r,int rt) //修改某个节点 即让第 L 个数据的值加上 c,即 a[L] += c 
{                                           ////[l,r]表示当前区间，rt是当前线段树节点编号
    if(l==r){  //找到了要更新的节点  即当前的 tree[rt] = a[L]
        a[l] += c;
        return;
    }
    int mid = (l+r)>>1;
    //根据条件判断往左子树调用还是往右
    if(L <= mid) Update(L,c,l,mid,rt*2);
    else         Update(L,c,mid+1,r,rt*2+1);
    PushUp(rt);//子节点的信息更新了，所以本节点也要更新信息
}

// (3)区间查询（本题为求和）：
// 询问A[L..R]的和
// 注意到，整个函数的递归过程中，L,R是不变的。
// 首先如果当前区间[l,r]在[L,R]内部，就直接累加答案
// 如果左子区间与[L,R]有重叠，就递归左子树，右子树同理。
int Query(int L,int R,int l,int r,int rt)
{
     //在区间内直接返回
    if(L<=l && r<=R) return tree[rt];
    int mid = (l+r)>>1;
    int ans = 0;
    //左子区间:[l,m] 右子区间：[m+1,r]  求和区间:[L,R]
   //累加答案
    int ANS=0;  
    if(L <= mid) ans+=Query(L,R,l,mid,rt*2);
    if(R > mid) ans+=Query(L,R,mid+1,r,rt*2+1);
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    Build(1,n,1);
    for(int i=1;i<=15;i++) printf("tree[%d] = %d\n",i,tree[i]);
    cout<<Query(2,5,1,n,1);
    return 0;
}
/*
6
1 3 5 7 9 11
*/
