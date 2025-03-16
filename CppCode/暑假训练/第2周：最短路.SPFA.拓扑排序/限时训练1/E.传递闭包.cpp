///HDU1704
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 505;
int T,n,m;
int map[N][N];
void Floyed()
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(map[i][k]==1){  //i--->k
                for(int j=1;j<=n;j++){
                    if(map[k][j]==1){  //k--->j
                        map[i][j] = 1;  //i--->k && k---->j ====> i----j  传递关系
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof map);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            map[u][v] = 1;
        }
        Floyed();
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j){
                    if(map[i][j]==1) cnt++;
                }
                else if((map[i][j]==0 && map[j][i]==0) || (map[i][j]==1 && map[j][i]==1)) 
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
Sample Input
3
3 3
1 2
1 3
2 3
3 2
1 2
2 3
4 2
1 2
3 4
Sample Output
0
0
4
*/