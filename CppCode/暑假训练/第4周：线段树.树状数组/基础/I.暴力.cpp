///CF 1199A
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
const int N = 1e5+5;
int n,x,y,a[N];
int flag,flag2;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        flag = 0;
        flag2 = 0;
        for(int j=i-1;j>0 && j>=i-x;j--){
            if(a[j] <= a[i]){
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        for(int j=i+1;j<=n && j<=i+y;j++){
            if(a[j] <= a[i]){
                flag2 = 1;
                break;
            }
        }
        if(flag2==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
/*
Input
10 2 2
10 9 6 7 8 3 2 1 4 5
Output
3
Input
10 2 3
10 9 6 7 8 3 2 1 4 5
Output
8
Input
5 5 5
100000 10000 1000 100 10
Output
5
*/