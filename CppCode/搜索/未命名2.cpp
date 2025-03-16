#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//0红色 1黄色 ->1红色 2黄色 
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};//四个方向 
int m,n;
const int MAX=1e9;
int map[110][110],my[110][110];
void dfs(int x,int y,int sum,bool flag)
{
	if(sum>=my[x][y]) return;
	my[x][y]=sum;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||ny<1||nx>m||ny>m) continue;
		if(map[nx][ny]){
			if(map[nx][ny]==map[x][y]) dfs(nx,ny,sum,true);
		    else		dfs(nx,ny,sum+1,true);
		}
		else{
			if(flag){
				map[nx][ny]=map[x][y];
				dfs(nx,ny,sum+2,false);
				map[nx][ny]=0;
			} 	
		}
		 
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=c+1;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++) my[i][j]=MAX;
	dfs(1,1,0,true);
	if(my[m][m]==MAX) cout<<"-1";
	else cout<<my[m][m];
	return 0;
}

