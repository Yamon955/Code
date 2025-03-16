#include<iostream>
#include<cstring>
using namespace std;
int f[1010];
int ans[1010];
int n;
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++) cin>>f[i];
   int Max=0;
   for(int i=1;i<=n;i++){
       ans[i]=1;//初始化
       for(int j=1;j<=i-1;j++){
           if(f[i]>f[j]){
               ans[i]=max(ans[i],ans[j]+1);
           }
        }
        Max=max(Max,ans[i]);
    }
    cout<<Max;
    return 0;
}
/*
AC wing--895
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤1000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/