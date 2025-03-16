#include<iostream>
#include<cstdio>
using namespace std;
int c[3500],v[3500];
int f[13000];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i = 1;i <= n; i ++) cin>>c[i]>>v[i];
    for(int i = 0; i <= m; i++) f[0] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = m;j >= c[i]; j --){
          f[j] = max(f[j],f[j-c[i]]+v[i]);
        }
    cout<<f[m]<<endl;
    return 0;
}