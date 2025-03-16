//HDU2066
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
const int N = 1005;
int t,c,p,n;
int map[N][N],vis[N],dis[N];
int x[N],y[N];
void Dijstra(int st)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[st] = 0;
	for(int i=1;i<=n;i++){
		int Min = inf;
		int k;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]<Min){
				Min = dis[j];
				k = j;
			}
		}
		vis[k] = 1;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]>dis[k]+map[k][j]){
				dis[j] = dis[k]+map[k][j];
			}
		}
	}
}
int main()
{
	while(scanf("%d%d%d",&t,&c,&p)!=EOF){
		memset(map,0x3f,sizeof map);
		n = 0;
		for(int i=1;i<=t;i++){
			int a,b,w;
			cin>>a>>b>>w;
			map[a][b] = map[b][a] = min(map[a][b],w);
			n = max(n,a);
			n = max(n,b);
		}
		for(int i=1;i<=c;i++) cin>>x[i];
		for(int i=1;i<=p;i++) cin>>y[i];
		int ans = inf;
		for(int i=1;i<=c;i++){   //此题也可以建立一个超级源点0，建立从源点0到起点之间的单向边权值为0，这样只需跑一遍Dijstra即可
			Dijstra(x[i]);
			for(int j=1;j<=p;j++){
				ans = min(ans,dis[y[j]]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
Sample Input
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
Sample Output
9
*/