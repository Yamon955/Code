//POJ2240
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 35;
int n,m,cnt;
map<string,int>mp;
double dis[N][N];
void Floyed()
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]<dis[i][k]*dis[k][j])
                    dis[i][j] = dis[i][k]*dis[k][j];
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) 
                if(i==j) dis[i][j] = 1;
                else dis[i][j] = 0;
        }
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            mp[s] = i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            string s1,s2;
            double rt;
            cin>>s1>>rt>>s2;
            dis[mp[s1]][mp[s2]] = rt;
        }
        Floyed();
        int flag = 0;
        for(int i=1;i<=n;i++){
            if(dis[i][i]>1){
                flag = 1;
                break;
            }
        }
        if(flag) printf("Case %d: Yes\n",++cnt);
        else printf("Case %d: No\n",++cnt);
    }
    return 0;
}
/*
Sample Input
3
USDollar
BritishPound
FrenchFranc
3
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar

3
USDollar
BritishPound
FrenchFranc
6
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar

0
Sample Output
Case 1: Yes
Case 2: No
Hint
判断图中是否存在变大环
*/