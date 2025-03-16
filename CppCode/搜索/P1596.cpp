#include<iostream>
#include<cstdio>
using namespace std;
int n,m,total=0;
char map[110][110];
int v[110][110];
const int dx[8]={0,0,1,-1,1,-1,1,-1};
const int dy[8]={1,-1,0,0,1,1,-1,-1};
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=m) continue;
		if(map[nx][ny]=='W'&&v[nx][ny]==0) dfs(nx,ny);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>map[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(map[i][j]=='W'&&v[i][j]==0){
				dfs(i,j);
				total++;
			}
		}
	cout<<total;
	return 0;
}
