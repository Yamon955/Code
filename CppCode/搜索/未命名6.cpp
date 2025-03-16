#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int MAX=1e9;
int v[510][510],stp[510][510];
char map[510][510];
int n,m;
int gx,gy,sx,sy;
void dfs(int x,int y,int sum)
{
	if(sum>=stp[x][y]) return ;
	stp[x][y]=sum;
	if(x==gx && y==gy) return ;
		for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=n ||ny>=m) continue;
		if(map[nx][ny]!='#'){
			dfs(nx,ny,sum+1);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin>>map[i][j];	
			stp[i][j]=MAX;
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
	dfs(sx,sy,0);
	if(stp[gx][gy]!=MAX) cout<<"Yes";
	else                 cout<<"No";
	return 0;	
}
