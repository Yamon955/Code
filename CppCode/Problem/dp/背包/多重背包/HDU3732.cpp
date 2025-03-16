#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/*
此题乍一看是 01背包 但是01背包解法做不出来，因为数据量很大
此题  0<=v2,w2<=10 数据范围很小一共11*11中可能，但是输入数据量很大，也就是可能有很多物品的重量价值相同，
因此可以转化为 多重背包(二进制优化) 来解决  多重背包通过二进制优化转化为01背包来做
*/
int n,c;
int f[11][11],v2[100010],w2[100010],dp[100010];
char s[15];
int cnt;
int main()
{
    while(scanf("%d%d",&n,&c)!=EOF){
        memset(f,0,sizeof(f));
        memset(dp,0,sizeof(dp));
        cnt = 0;
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%s %d %d",s,&a,&b);
            //cin>>s>>a>>b;用cin会超时
            f[a][b]++;
        }
        for(int i=0;i<=10;i++){
            for(int j=0;j<=10;j++){
                int k = 1;
                if(f[i][j]==0) continue;
                while(f[i][j]>=k){
                    v2[++cnt] = i*k;
                    w2[cnt] = j*k;
                    f[i][j] -= k;
                    k *= 2;
                }
                if(f[i][j]!=0) {
                    v2[++cnt] = i*f[i][j];
                    w2[cnt] = j*f[i][j];
                }
            }
        }
        n =cnt;
        for(int i=1;i<=n;i++){
            for(int j=c;j>=0;j--){
                if(j>=w2[i])  dp[j] = max(dp[j],dp[j-w2[i]]+v2[i]);
            }
        }
        cout<<dp[c]<<endl;
    }
    return 0;
}
/*
示例输入
5 20
go 5 8
think 3 7
big 7 4
read 2 6
write 3 5
样本输出
15
*/