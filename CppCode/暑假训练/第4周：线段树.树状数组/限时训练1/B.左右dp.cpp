//CodeForces - 1547E
//对于每个位置的空调的最小值来说肯定是和左右（+1）比较
//左右各遍历一遍所有格子就是答案；
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 3e6+5;
int T,n,k;
int a[N],ans[N];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n+5;i++) ans[i] = inf;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        for(int i=1;i<=k;i++) scanf("%d",&ans[a[i]]);
        for(int i=1;i<=n;i++) ans[i] = min(ans[i],ans[i-1]+1);
        for(int i=n;i>=1;i--) ans[i] = min(ans[i],ans[i+1]+1);
        for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<endl;

    }
    return 0;
}
/*
Input
5

6 2
2 5
14 16

10 1
7
30

5 5
3 1 4 2 5
3 1 4 2 5

7 1
1
1000000000

6 3
6 1 3
5 5 5
Output
15 14 15 16 16 17 
36 35 34 33 32 31 30 31 32 33 
1 2 3 4 5 
1000000000 1000000001 1000000002 1000000003 1000000004 1000000005 1000000006 
5 6 5 6 6 5 
*/
