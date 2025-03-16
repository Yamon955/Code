//CodeForces 631A
//由于此题数据范围很小可以直接暴力解决，把全部的可能都遍历一遍求出最大值


//简单解法 ：由于每两个数做 或运算 之后的结果肯定是不小于其中的任何一个数，
//所以把每一个数组中所有的数都做一遍 或运算 所得结果一定是最大值

//简单解法
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int a[1005],b[1005];
int n;
long long Max;
int main()
{
    cin>>n;
    int ans1 = 0,ans2 = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans1 = ans1 | a[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        ans2 = ans2 | b[i];
    }  
    cout<<ans1+ans2<<endl;
    return 0;
    
}


//暴力解法
// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<stack>
// using namespace std;
// int a[1005],b[1005];
// int n;
// long long Max;
// int main()
// {
//     cin>>n;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     for(int i=1;i<=n;i++) cin>>b[i];
//     if(n==1) Max = a[1]+b[1];
//     else{
//         for(int i=1;i<=n;i++){
//             int tmp1 = a[i];
//             int tmp2 = b[i];
//             for(int j=i+1;j<=n;j++){
//                 tmp1 = (tmp1 | a[j]);//或运算
//                 tmp2 = (tmp2 | b[j]);
//                 if(tmp1+tmp2 > Max){
//                     Max = tmp1 + tmp2;
//                 }
//             }
//         }
//     }
//     cout<<Max<<endl;
//     return 0;
// }