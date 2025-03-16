#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
char map[101][101];
int v[101][101];
int m,n,total=0;
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<n && ny<m && map[nx][ny]!='0' && v[nx][ny]==0)
			dfs(nx,ny);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>map[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(map[i][j]!='0' && v[i][j]==0){
				dfs(i,j);
				total++;
			}
		}
	cout<<total;
	return 0;
}
