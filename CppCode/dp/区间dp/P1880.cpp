#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int f[310];
int dp_min[310][310],dp_max[310][310];
int sum[310];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>f[i];
        f[n+i] = f[i];
    }
     for(int i=1;i<=2*n;i++) {
        sum[i] = sum[i-1]+f[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=2*n-len+1;i++){
            int j=len+i-1;
            dp_min[i][j] = dp_min[i][i]+dp_min[i+1][j]+sum[j]-sum[i-1];
            dp_max[i][j] = dp_max[i][i]+dp_max[i+1][j]+sum[j]-sum[i-1];
            for(int k=i+1;k<j;k++){
                int tmp = dp_min[i][k]+dp_min[k+1][j]+sum[j]-sum[i-1];
                int tmp2 = dp_max[i][k]+dp_max[k+1][j]+sum[j]-sum[i-1];
                if(tmp<dp_min[i][j]) dp_min[i][j]=tmp;
                if(tmp2>dp_max[i][j]) dp_max[i][j] = tmp2;
            }
        }
    }
    int Min = 0x3f3f3f3f;
    int Max = 0;
    for(int i=1;i<=n;i++){
        Min = min(Min,dp_min[i][i+n-1]);
        Max = max(Max,dp_max[i][i+n-1]);
    }
    cout<<Min<<endl;
    cout<<Max<<endl;
    return 0;
}