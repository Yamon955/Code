//CodeForces - 574C
// 如果要使每个数乘以数量不限的2或数量不限的3，最后它们的值要相等！
// 可以想成是，当前的数是由其它更小的数通过乘以数量不限的2或数量不限的3得来的，
// 这样的话，只需要把输入的数只要它能除尽2或3，就除下去，
// 当得到一个无法再做除法的数时，判断这些数是否都是相等的。等就是yes，不等就是no。

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int n;
int a[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int flag = 0;
    for(int i=1;i<=n;i++){
        while(a[i]%2==0) a[i] /= 2;
        while(a[i]%3==0) a[i] /= 3;
        if(i == 1) continue;
        if(a[i] != a[i-1]){
            flag = 1;
            break;
        }
    }
    if(flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
/*
Input
4
75 150 75 50
Output
Yes
Input
3
100 150 250
Output
No
*/