#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int x,int y)
{
    //return x<y;  sort函数默认的返回值-->从小到大
    return x>y;   //重新定义--->从大到小
}
//sort(a,a+n,cmp) n-->元素个数   cmp可不写--->默认从小到大
//sort(要排序序列的第一个元素的地址，要排序序列的最后一个元素的地址)
//O(nlogn)
typedef struct Node{
    int x;
    int y;
};
int cmp2(Node a,Node b)
{
    return a.y>b.y;//规定按照y值从大到小排序
}
int main()
{
    int a[10];
    for(int i=0;i<=5;i++) cin>>a[i];
    sort(a,a+6);
    for(int i=0;i<=5;i++) cout<<a[i]<<" ";
    cout<<endl;
    sort(a,a+6,cmp);
    for(int i=0;i<=5;i++) cout<<a[i]<<" ";
    cout<<endl;
    //sort 可对结构体排序
    Node b[3];
    b[0]={1,5};
    b[1]={2,-5};
    b[2]={6,0};
    sort(b,b+3,cmp2);
    for(int i=0;i<=2;i++) cout<<b[i].x<<" ";
    return 0;
}
