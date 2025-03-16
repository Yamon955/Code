#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/*  -->与矩阵连乘相同，可参考矩阵连乘时的二维矩阵f[i][j]的变化情况分析
有N堆石子，现要将石子有序的合并成一堆，规定如下：每次只能移动相邻的2堆石子合并，合并花费为新合成的一堆石子的数量。
求将这N堆石子合并成一堆的总花费最小（或最大）。
*/
//求最小   m[i][j] = 0    i=j
//        m[i][j] = min(m[i][j],m[i][k]+m[k+1][j]+sum(i,j))  i!=j

//求最大   m[i][j] = 0    i=j
//        m[i][j] = max(m[i][j],m[i][k]+m[k+1][j]+sum(i,j))  i!=j
const int INF = 0x3f3f3f3f;
int n;
int cnt[1000];
int f[1010][1010];
int sum[1010];
int get_sum(int x,int y){  //求出  第x到第y堆石子的总数量  ---->可用前缀和数组提高效率
    int sum=0;
    for(int i=x;i<=y;i++) sum+=cnt[i];
    return sum;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>cnt[i];
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+cnt[i];//前缀和数组
    for(int i=1;i<=n;i++) f[i][i] = 0;//区间长度r=1  f[1][1],f[2][2]...f[n][n]
    for(int r=2;r<=n;r++){   //r表示区间长度 如f[1][2] 区间长度r=2   f[1][3] 区间长度r=3  f[i][j]  区间长度r=j-i+1
        for(int i=1;i<=n-r+1;i++){  // i+r-1<=n  -->  i<=n-r+1
            int j=i+r-1;  // r=j-i+1  -->  j=i+r-1
            f[i][j] = f[i][i] + f[i+1][j] + sum[j]-sum[i-1];
            for(int k=i+1;k<j;k++){//枚举分割点
                f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<f[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<f[1][n];
    return 0;
}