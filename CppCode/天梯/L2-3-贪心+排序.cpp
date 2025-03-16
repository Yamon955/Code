#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#include<map>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
int n,d;
double a[N],val[N];  //此题输入的重量和价格可能不是整数
double sum;
struct node{
    double w;
    double val;
    double avg;
};
node Ns[N];
bool cmp(node a,node b)
{
    return a.avg > b.avg;
}
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=n;i++){
        Ns[i].avg = 1.0*val[i]/a[i];
        Ns[i].w = a[i];
        Ns[i].val = val[i];
    }
    sort(Ns+1,Ns+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(d == 0) break;
        if(d > 0 && d >= Ns[i].w){
            d -= Ns[i].w;
            sum += Ns[i].val;
        }
        else if(d > 0 && d < Ns[i].w){
            sum += 1.0*Ns[i].avg*d;
            break;
        }
    }
    printf("%.2f",sum);
}
/*
输入样例：
3 20
18 15 10
75 72 45
结尾无空行
输出样例：
94.50
*/