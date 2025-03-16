//POJ 1328
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
const int N = 1005;
int n,d;
struct node{
    float x,y;
    float l,r; //存储以当前点为圆心半径为 d 的圆与 x 轴的两个交点横坐标
};
node Ns[N];
bool cmp(node a,node b){
    return a.l > b.l;
}
int main()
{
    int Case  = 0;
    while(cin>>n>>d){
        if(n == 0 && d == 0) break;
        int flag = 1;
        for(int i=1;i<=n;i++){
            cin>>Ns[i].x>>Ns[i].y;
            if(Ns[i].y > d) {  //如果纵坐标的值大于 d 那么该点一定覆盖不了，最后输出 -1
                flag = 0;
            }
            float r = sqrt(d*d - Ns[i].y*Ns[i].y); //勾股定理
            Ns[i].l = Ns[i].x - r;
            Ns[i].r = Ns[i].x + r;
        }
        sort(Ns+1,Ns+n+1,cmp);
        float now = Ns[1].l;
        int ans = 1;
        for(int i=2;i<=n;i++){
            if(Ns[i].l <= now && now <= Ns[i].r) continue;
            else{
                now = Ns[i].l;
                ans ++;
            }
        }
        if(flag){
            cout<<"Case "<<(++Case)<<": ";
            cout<<ans<<endl;
        }
        else{
            cout<<"Case "<<(++Case)<<": ";
            cout<<"-1"<<endl;
        }
    }
}
/*
Sample Input
3 2
1 2
-3 1
2 1

1 2
0 2

0 0
Sample Output
Case 1: 2
Case 2: 1
*/


