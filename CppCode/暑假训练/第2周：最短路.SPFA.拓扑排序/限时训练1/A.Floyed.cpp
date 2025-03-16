//HDU2544
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
int n,m;
int map[N][N];
void Floyed()
{
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0) break;
		memset(map,0x3f,sizeof map);
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			map[u][v] = map[v][u]=min(map[u][v],w);
		}
		Floyed();
		cout<<map[1][n]<<endl;
	}
	
	
	
	
	return 0;
}
/*
Sample Input
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
Sample Output
3
2
*/