#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int v[510][510];
char map[510][510];
int n,m;
int gx,gy,sx,sy;
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=n ||ny>=m) continue;
		if(map[nx][ny]!='#' && !v[nx][ny]){
			dfs(nx,ny);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin>>map[i][j];	
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(map[i][j]=='g') {
				gx=i;
				gy=j;
			}
			else if(map[i][j]=='s') {
				sx=i;
				sy=j;
			}
		}	
	dfs(sx,sy);
	if(v[gx][gy])       cout<<"Yes"<<endl;
	else                 cout<<"No"<<endl;
	return 0;		
}
