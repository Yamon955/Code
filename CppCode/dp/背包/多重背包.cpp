#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/*
基本算法
这题目和完全背包问题很类似。基本的方程只需将完全背包问题的方程略微一改即可，因为对于第i种物品有n[i]+1种策略：
取0件，取1件……取 n[i]件。令f[i][v]表示前i种物品恰放入一个容量为v的背包的最大权值，
则：f[i][v]=max{f[i-1][v-k*c[i]]+ k*w[i]|0<=k<=n[i]}。复杂度是O(V*∑n[i])。
*/
int n,m;
int w[1010],v[1010],s[1010];
int dp[1010][1010];
int dp_2[1010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i]>>s[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=s[i];k++){   //遍历该物品i的是 s[i]+1 种状态
                if(j>=k*w[i]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]);  //当前状态最优值是由那两个状态比较得来的
                    //int tmp = dp[i-1][j-k*w[i]]+k*v[i];
                    //if(tmp>dp[i][j]) dp[i][j] = tmp;
                }
            }
        }
    }
    //一维数组做法
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){  //从大到小遍历，与01背包优化类似
            for(int k=0;k<=s[i];k++){   //遍历该物品i的是 s[i]+1 种状态
               if(j>=k*w[i]) dp_2[j] = max(dp_2[j],dp_2[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp_2[m]<<endl;
   // cout<<dp[n][m]<<endl;
    return 0;
}
/*

30 100
12 15 1
15 18 1
6 9 4
32 43 1
24 12 92
5 5 3
13 26 4
2 3 3
14 9 7
31 28 77
19 18 88
18 17 70
21 23 4
19 24 3
29 37 2
33 34 4
25 32 5
28 47 4
1 1 2
23 25 3
24 30 1
22 24 1
4 7 1
33 40 2
15 29 4
18 9 51
19 17 25
6 10 4
24 20 15
18 23 5

输出
195
标准答案
195
*/