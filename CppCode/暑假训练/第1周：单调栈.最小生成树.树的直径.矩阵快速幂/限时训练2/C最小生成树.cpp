//BZOJ 1083
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int n,m;
int map[305][305];
int dis[305],vis[305];
int main()
{
	cin>>n>>m;
	memset(map,0x3f,sizeof(map));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v] = map[v][u] =w;
	}
	dis[1] = 0;
	for(int i=1;i<=n;i++){
		int Min = 0x3f3f3f3f,k;
		for(int j=1;j<=n;j++){
			if(vis[j]==0 && dis[j]<Min){
				Min = dis[j];
				k = j;
			}
		}
		vis[k] = 1;
		for(int j=1;j<=n;j++){
			if(vis[j]==0 && map[k][j] < dis[j]) dis[j] = map[k][j];
		}
	}
	int Max = 0;
	for(int i=1;i<=n;i++){
		Max = max(Max,dis[i]);
	}
	cout<<n-1<<" "<<Max<<endl;
	return 0;
}
/*
Sample Input
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8
Sample Output
3 6
*/