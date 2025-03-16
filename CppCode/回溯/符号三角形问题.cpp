#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt,n,sum,ans;
int f[1000][1000];
void Backtrack(int t)
{
    if(cnt>sum/2||(sum-cnt)>sum/2) return;
    if(t>n){
        ans++;
        return;
    }
    for(int i=0;i<2;i++){//0为+，1为-
        f[1][t] = i;
        cnt += i;
        for(int j=2;j<=t;j++){
            f[j][t-j+1] = f[j-1][t-j+1]^f[t-1][t-j+2];//异或
            cnt += f[j][t-j+1];
        }
        Backtrack(t+1);
        for(int j=2;j<=t;j++){
            cnt -= f[j][t-j+1];
        }
        cnt -= i;
    }
}
int main()
{
    cin>>n;
    sum = n*(n+1)/2;
    if(sum%2!=0) {
        return 0;
    }
    Backtrack(1);
    cout<<ans<<endl;
    return 0;
}