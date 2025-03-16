#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int dp_min[1010][1010],dp_max[1010][1010];
int f[1010];
int sum[1010];//前缀和数组
/*
    定义状态f[i][j]，表示i到j合并后的最大得分。其中1<=i<=j<=N。

既然这样，我们就需要将这一圈石子分割。很显然，我们需要枚举一个k，来作为这一圈石子的分割线。

这样我们就能得到状态转移方程：
f[i][j] = min(f[i][k] + f[k+1][j] + d(i,j));其中，1<=i<=<=k<j<=N。
f[i][j] = max(f[i][k] + f[k+1][j] + d(i,j));其中，1<=i<=<=k<j<=N。

d(i,j)表示从i到j石子个数的和。

化曲为直：
    通过将一个环形排列转化为两倍的直线排列，然后从中遍历所有区间长度为 n 的序列，得出最大值和最小值
*/
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){  //化曲为直----->将一个圆形排列转化为两倍的直线排列  
                              //如1 2 3 4环形排列----转化为两倍直线排列--->1 2 3 4 1 2 3 4
        cin>>f[i];
        f[i+n] = f[i];
    }
    for(int i=1;i<=2*n;i++) sum[i] = sum[i-1]+f[i];//求前缀和
    for(int len = 2; len <=n; len ++){  //len代表区间长度------>区间dp
                                        //如dp_min[1][1],dp_[i][j] 区间长度len=1,dp_min[2][5] len=4, dp_min[1][n] len=n  
                                        //dp_min[i][j] 区间长度 len = j-i+1---->得到 len,i,j三者的关系式
        for(int i=1;i<=2*n-len+1;i++){  //2*n-len+1此值为 i 的能到达的最最右端，如果再大的话 j 的值会超过 2n
            int j=len+i-1;//len = j-i+1
            dp_min[i][j] = dp_min[i][i]+dp_min[i+1][j]+sum[j]-sum[i-1];
            dp_max[i][j] = dp_max[i][i]+dp_max[i+1][j]+sum[j]-sum[i-1];
            for(int k=i+1;k<j;k++){  //遍历 k 值
                int tmp1 = dp_min[i][k]+dp_min[k+1][j]+sum[j]-sum[i-1];
                int tmp2 = dp_max[i][k]+dp_max[k+1][j]+sum[j]-sum[i-1];
                if(tmp1<dp_min[i][j]) dp_min[i][j] = tmp1;
                if(tmp2>dp_max[i][j]) dp_max[i][j] = tmp2;
            }
        }
    }
    int Min = 0x3f3f3f3f;
    int Max = 0;
    for(int i=1;i<=n;i++){  //遍历所有区间长度为 n 的值，从中取出最大值和最小值
        Min = min(Min,dp_min[i][i+n-1]);
        Max = max(Max,dp_max[i][i+n-1]);
    }
    cout<<Min<<endl;
    cout<<Max<<endl;
    return 0;
}
/*
4
4 5 9 4
-->43  54
*/