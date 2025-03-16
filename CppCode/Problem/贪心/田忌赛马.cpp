//POJ-2287
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
int a[N],b[N];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n == 0) break;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int la = 1,ra = n;
        int lb = 1,rb = n;
        int win = 0,lose = 0;
        for(int i=1;i<=n;i++){
            if(a[ra] > b[rb]){  //田忌最快的马快于国王最快的马
                win ++;
                ra --;
                rb --;
            }
            else if(a[la] > b[lb]){  //田忌最慢的马快于国王最慢的马
                win ++;
                la ++;
                lb ++;
            }
            else{  //田忌最快的马 <= 国王最快的马，田忌最慢的马 <= 国王最慢的马
                   //那么就让田忌最慢的马去跑国王最快的马，因为田忌所有的马都 <= 国王的这匹最快的马，所以就让最慢的马去比国王最快的马
                if(a[la] < b[rb]){
                    lose ++;
                    la ++;
                    rb --;
                }
            }
        }
        cout<<(win - lose)*200<<endl;
    }
    return 0;
}
/*
Sample Input
3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0
Sample Output
200
0
0
*/