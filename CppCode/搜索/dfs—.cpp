#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};//四个方向 
int  map[1001][1001],v[1001][1001];//map表示图，v是标记数组 
int m,n,k;
int _max(int x,int y){return x>y?x:y;}
void dfs(int x,int y)
{
	k++;
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&ny>=0&&nx<m&&ny<n&&map[nx][ny]==1&&v[nx][ny]==0)
			dfs(nx,ny);
	}
}
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) {
			scanf("%d",&map[i][j]);
		}
	int ans=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			k=0;
			if(map[i][j]==1&&v[i][j]==0) dfs(i,j);
			ans=_max(k,ans);
		}
	printf("%d",ans);
	return 0;
}
/* 
第一行为m,n表示图的大小
以下各行0表示海洋，1表示陆地 
问：求出图中最大的岛屿，即相连的1（陆地）的个数 
5 5
0 1 1 0 0
1 1 0 0 0
0 0 1 1 0
0 1 1 1 1
0 0 1 1 0
输出 8;
*/ 
