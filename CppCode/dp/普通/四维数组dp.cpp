//P1004
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 12;
int mp[N][N];
int dp[N][N][N][N];
int n;
int x,y,w;
int main()
{
    cin>>n;
    while(~scanf("%d%d%d",&x,&y,&w)){
        if(x==0 && y==0 && w==0) break;
        mp[x][y] = w;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    dp[i][j][k][l] = max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])));
                    if(i == k && j == l) dp[i][j][k][l] += mp[i][j];
                    else dp[i][j][k][l] += mp[i][j] + mp[k][l];
                }
            }
        }
    }
    cout<<dp[n][n][n][n]<<endl;
    return 0;

}
/*
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
-->67
*/


