#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;//1<=n<=500,1<=m<=500
int c[510],v[510];
int Knapsack_1()    // m*m的二维数组
{
    int f[510][510];//二维数组---->一般题目会超过空间限制
    for(int i = 0;i <= m; i ++) f[0][i] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            if(j >= c[i]) f[i][j] = max(f[i-1][j],f[i-1][j-c[i]] + v[i]);
            else f[i][j] = f[i-1][j];
        }
    }
    return f[n][m];
}
//优化 1  ---> 2*m 的二维数组
//我们可以发现每次更新下一行的值时只跟它上一行的值相关，即每次更新只涉及两行，故只开一个 f[2][]数组即可
//可通过设置一个tmp，用它对 2 取余，因此tmp取值只能为 0 或 1，即每次用 第 0 行更新第 1 行，
//然后更新tmp = (tmp + 1) % 2，再用 第 1 行去更新第 0 行，以此类推直到 n 个物品全部更新完毕
int Knapsack_2()
{
      int f[2][510];
      for(int i = 0;i <= m; i ++) f[0][i] = 0;
      int tmp = 1; //更新行
      for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= m; j ++){
                  if(j >= c[i]) f[tmp][j] = max(f[(tmp + 1) % 2][j],f[(tmp + 1) % 2][j-c[i]] + v[i]);
                  else f[tmp][j] = f[(tmp + 1) % 2][j];
        }
        tmp = (tmp + 1) % 2;//tmp值转化为下一行
      }
      //return f[(tmp + 1) % 2][m];
      return max(f[0][m],f[1][m]);
}
//优化3 ----->一维数组
/*
为什么01背包中要按照j=m..0的逆序来循环。这是因为要保证第i次循环中的状态f[i][v]是由状态f[i-1][v-c[i]]递推而来。
换句话说，这正是为了保证每件物品只选一次，保证在考虑“选入第i件物品”这件策略时，依据的是一个绝无已经选入第i件物品
的子结果f[i-1][v-c[i]]。
*/
int Knapsack_3() 
{
    int f[510];
    for(int i = 0;i <= m; i ++) f[i] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= c[i]; j --){ //注意,背包大小一定是从大到小，与完全背包正好相反，可以与完全背包类比
            f[j] = max(f[j],f[j-c[i]] + v[i]);
        }
    }
    return f[m];
}
int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i ++) cin>>c[i]>>v[i];
    cout<<Knapsack_1()<<endl;
    cout<<Knapsack_2()<<endl;
    cout<<Knapsack_3()<<endl;
    return 0;
}
/*
4 6
1 4
2 6
3 12
2 7
-->23 23 23
*/
