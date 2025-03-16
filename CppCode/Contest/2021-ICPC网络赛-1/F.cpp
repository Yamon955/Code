#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int T;
ll a,b,R;

int main()
{
    cin>>T;
    int Case = 0;
    while(T--){
        cin>>a>>b>>R;
        //特判 ：  假如A圆的最低点低于X轴，也就是b<=R的时候，直接沿x轴走到圆B更近
        if(b <= R){
            double short_len = 2*a-R;
            printf("Case #%d: %.2f\n",(++Case),short_len);
            continue;
        }
        ll pax = a,pay = b;
        ll pbx = 2*a,pby = 0;
        //直接猜中垂线 也就是(a,b-r)这个点
        ll pcx = a,pcy = b-R;
        double OC = sqrt(pcx*pcx+pcy*pcy);
        double BC = sqrt((pbx-pcx)*(pbx-pcx) + (pby-pcy)*(pby-pcy));
        double short_len = OC + BC - R;
        printf("Case #%d: %.2f\n",(++Case),short_len);
    }
}
/*
Sample Input
1
3 5 1

Sample Output
Case #1: 9.00
*/