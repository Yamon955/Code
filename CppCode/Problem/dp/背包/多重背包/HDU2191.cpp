#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,m,n;
int p[110],h[110],c[110];
int dp[110][110];
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;i++) cin>>p[i]>>h[i]>>c[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=c[i];k++){
                    if(j>=k*p[i]){
                        dp[i][j] = max(dp[i][j],dp[i-1][j-k*p[i]]+k*h[i]);
                    }
                    else break;
                }
            }
        }
        cout<<dp[m][n]<<endl;
    }
    return 0;
}
/*
Input
输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m(1<=n<=100, 1<=m<=100),分别
表示经费的金额和大米的种类，然后是m行数据，每行包含3个数p，h和c(1<=p<=20,1<=h<=200,1<=c<=20)，分别表示每袋的
价格、每袋的重量以及对应种类大米的袋数。
Output
对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的大米，并且经费你可以不用完。每个实例
的输出占一行。
Sample Input
1
8 2
2 100 4
4 100 2
Sample Output
400
*/
