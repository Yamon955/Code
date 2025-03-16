//HDU 1166
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
const int N = 5e4+5;
int n,m,T;
int a[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int pos,int x)
{
    for(int i=pos;i<=n;i += lowbit(i)){
        a[i] += x;
    }
}
int Query(int pos)
{
    int ans = 0;
    for(int i=pos;i;i -= lowbit(i)){
        ans += a[i];
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    
    int cnt = 0;
    while(T--){
        mem(a,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int z;
            cin>>z;
            update(i,z);
        }
        char s[10];
        printf("Case %d:\n",++cnt);
        while(cin>>s){
            int x,y;
            if(s[0]=='E') break;
            else if(s[0]=='Q'){
                scanf("%d%d",&x,&y);
                printf("%d\n",Query(y) - Query(x-1));
            }
            else if(s[0]=='A'){
                scanf("%d%d",&x,&y);
                update(x,y);
            }
            else if(s[0]=='S'){
                scanf("%d%d",&x,&y);
                update(x,-y);
            }
        }
    }
    return 0;
}
/*
Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
Sample Output
Case 1:
6
33
59
*/