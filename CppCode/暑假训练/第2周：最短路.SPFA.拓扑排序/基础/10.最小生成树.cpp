//HDU1162
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 105;
int n;
double map[N][N],dis[N];
int vis[N];
struct point{
    double x,y;
};
double getlen(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point p[N];
int main()
{
    while(cin>>n){
        for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) map[i][j] = inf;
                else map[i][j] = getlen(p[i],p[j]);
            }
            dis[i] = inf;
        }
        memset(vis,0,sizeof vis);
        dis[1] = 0;
        for(int i=1;i<=n;i++){
            double Min = inf;
            int k;
            for(int j=1;j<=n;j++){
                if(!vis[j] && Min > dis[j]){
                    Min = dis[j];
                    k = j;
                }
            }
            vis[k] = 1;
            for(int j=1;j<=n;j++){
                if(!vis[j] && dis[j]>map[k][j]) dis[j] = map[k][j];
            }
        }
        double ans = 0;
        for(int i=1;i<=n;i++) ans+=dis[i];
        printf("%.2lf\n",ans);
    }
    return 0;
}
/*
Sample Input
3
1.0 1.0
2.0 2.0
2.0 4.0
Sample Output
3.41
*/
