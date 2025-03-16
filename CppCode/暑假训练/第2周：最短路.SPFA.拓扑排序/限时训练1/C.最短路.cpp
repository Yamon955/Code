//POJ2253
// 克鲁斯卡尔  算出所有点之间的距离，将距离从小到大排序，逐一选边，将边的两点加入到一个集合里，并判断两只是否相遇
// 若相遇，此时距离就是答案
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
const int N = 205;
int n,cnt,vis[N];
struct point{
    double x,y;
};
point p[N];
double map[N][N],dis[N];
double getlen(point a,point b)
{
	return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void Dijstra(int st)
{
    for(int i=1;i<=n;i++) dis[i] = inf;
    memset(vis,0,sizeof vis);
    dis[st] = 0;
    for(int i=1;i<=n;i++){
        double Min = inf;
        int k = -1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && Min > dis[j]){
                Min = dis[j];
                k = j;
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                double maxx = max(dis[k],map[k][j]);
                dis[j] = min(dis[j],maxx);
            }
        }
    }
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
        for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) map[i][j] = inf;
		cnt++; 
		for(int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				map[i][j] = getlen(p[i],p[j]);
                map[j][i] = map[i][j];
			}
		}
        Dijstra(1);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cnt,dis[2]);
	}
	
	return 0;
}
/*
Sample Input
2
0 0
3 4

3
17 4
19 4
18 5

0
Sample Output
Scenario #1
Frog Distance = 5.000

Scenario #2
Frog Distance = 1.414
*/