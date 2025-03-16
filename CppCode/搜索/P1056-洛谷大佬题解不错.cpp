#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};//四个方向 
int m,n,v[510][510],total=0;
char map[510][510];
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||ny<0||nx>=m||ny>=n) continue;
		if(map[nx][ny]=='0'&&v[nx][ny]==0) dfs(nx,ny); 
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) cin>>map[i][j];
	for(int i=0;i<m;i++){
		if(map[i][0]=='0'&&v[i][0]==0) dfs(i,0);//第一列 
		if(map[i][n-1]=='0'&&v[i][n-1]==0) dfs(i,n-1);//最后一列 
	}
	for(int i=0;i<n;i++){
		if(map[0][i]=='0'&&v[0][i]==0) dfs(0,i);//第一行 
		if(map[m-1][i]=='0'&&v[m-1][i]==0) dfs(m-1,i);//最后一行 
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			if(v[i][j]==0&&map[i][j]=='0') total++;
		}
	cout<<total;
	return 0;
}
