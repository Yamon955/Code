#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//力扣 https://leetcode.cn/circle/discuss/FfMCgb/
/*
a[n];
b[n];--->数组a的差分数组
b[1]=a[1]
b[2]=a[2]-a[1]
b[3]=a[3]-a[2]
b[4]=a[4]-a[3]
.
.
b[n]=a[n]-a[n-1]
/////////////////由此可得在输入数组a时可以直接用差分数组表示，即不定义数组a，
///////////////////假如要输入数组a[k]=c时  可以通过  b[k]+=c,b[k+1]-=c 来完成用差分数组b代替数组a
由数组b求数组a
a[1]=b[1]
a[2]=b[2]+b[1]
a[3]=b[3]+b[2]+b[1]
a[4]=b[4]+b[3]+b[2]+b[1]
a[n]=b[n]+b[n-1]+'''''+b[1]
由此性质可得：如果要求数组a从第l项起每个值都加上c,则可以通过只让b[l]=b[l]+c来完成--->O(1)
b[l]+=c--->会使数组a从第l项起之后的每一项都加c
应用：要求一个数组a在第l项到第r项中的元素值都加上c
解决：b[l]+=c;--->使数组a从第l项起之后的每一项都加c
     b[r+1]-=c;-->使数组a从第r+1项起之后的每一项都减c
     通过这两句就使得数组a第l项到第r项中的元素值都加上c
    ////////****特别：当 l==r 时相当于赋值操作 即a[l]+=c;
*/


//例题 AC wing 797
/*
输入一个长度为 n 的整数序列。
接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c
*/
int b[100010];
void f(int l,int r,int c) ///l==r时相当于赋值操作
{
    b[l]+=c;   //在[l,n]之间每个数 +c     ------>
    b[r+1]-=c; //在[r+1,n]之间每个数 -c   ------>而最终实现在[l,r]之间每个数 +c
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        b[i]+=a;  //用差分数组来表示要输入的数组
        b[i+1]-=a;
        ///等同于  f(i,i,a);
    }
    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
       f(l,r,c);//处理
    }
    int a=0;
    for(int i=1;i<=n;i++){
        a+=b[i];
        cout<<a<<" ";//输出每个数
    }
    return 0;
}
/*
输入样例：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出样例：
3 4 5 3 4 2
*/