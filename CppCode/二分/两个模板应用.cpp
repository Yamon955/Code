/*
给定一个按照升序排列的长度为  n  的整数数组，以及  q  个查询。

对于每个查询，返回一个元素  k  的起始位置和终止位置（位置从  0  开始计数）。

如果数组中不存在该元素，则返回 -1 -1。
*/
#include<iostream>
using namespace std;
int a[100100];
int n,q;
void L(int l,int r,int k)
{
    while(l<r){
        int mid=(l+r)>>1;
        if(a[mid]<k) l=mid+1;
        else r=mid;
    }
    if(a[l]==k) cout<<l<<" ";//判断是否查找到k
    else  cout<<"-1 ";
}
void R(int l,int r,int k)
{
    while(l<r){
        int mid=(l+r+1)>>1;
        if(a[mid]>k) r=mid-1;
        else l=mid;
    }
    if(a[l]==k) cout<<l<<endl;//判断是否查找到k
    else cout<<"-1"<<endl;
}
int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    while(q--){
        int k;
        cin>>k;
        L(0,n-1,k);
        R(0,n-1,k);
    }
    return 0;
}
/*
输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1
*/

