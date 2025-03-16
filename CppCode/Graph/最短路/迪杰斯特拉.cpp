#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int map[110][110];
int s[110];
int shortest[110];
void Dijkstra(int x)
{
	s[x] = 1;
	for(int i=1;i<=n-1;i++){
		int Min = 0x3f3f3f3f;
		int Min_j;
		for(int j=2;j<=n;j++){
			if(map[x][j]<Min&&s[j]==0){
				Min = map[x][j];
				Min_j = j;
			}
		}
		s[Min_j] = 1;
		shortest[Min_j] = Min;
		for(int j=2;j<=n;j++){
			if(s[j]==0&&map[x][j]>map[x][Min_j]+map[Min_j][j]){
				map[x][j] = map[x][Min_j]+map[Min_j][j];
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	memset(map,0x3f,sizeof(map));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v] = w;
		map[v][u] = w;
	}
	Dijkstra(1);
	for(int i=2;i<=n;i++) cout<<shortest[i]<<" ";
	return 0;
}