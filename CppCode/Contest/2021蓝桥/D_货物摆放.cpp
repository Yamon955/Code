#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
ull n = 2021041820210418;
int ans;
ull f[10010];
int main()
{
    int count = 0;
    for(ull i=1;i*i<=n;i++){  //分解n,求出n的所有因数，存储在f[]中
        if(n%i==0) {
            f[count++] = i;
            if(i!=n/i) f[count++] = n/i; //因为两个因数可能相等，避免重复存储
        }
    }
    for(int i=0;i<count;i++){
        for(int j=0;j<count;j++){
            for(int k=0;k<count;k++){
                if(f[i]*f[j]*f[k]==n) ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
//2430