#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int n;
int map[32][32],v[32][32];
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=n) continue;
		if(map[nx][ny]==0&&v[nx][ny]==0) {
			//v[nx][ny]=1;
			dfs(nx,ny);
		}
	}
}
void dfs_2(int x,int y)
{
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=n) continue;
		if(map[nx][ny]==1&&v[nx][ny]==0) {
			v[nx][ny]=1;
			dfs(nx,ny);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>map[i][j];
	for(int i=0;i<n;i++){
		if(map[i][0]==0&&v[i][0]==0) dfs(i,0);
		if(map[i][n-1]==0&&v[i][n-1]==0) dfs(i,n-1);
	}
	for(int i=0;i<n;i++){
		if(map[0][i]==0&&v[0][i]==0) dfs(0,i);
		if(map[n-1][i]==0&&v[n-1][i]==0) dfs(n-1,i);
	}
	/*for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(map[i][j]==1&&v[i][j]==0){
				v[i][j]=1;
				dfs_2(i,j);
				break;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cout<<v[i][j]<<" ";
			cout<<endl;
		}*/ 
		
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]==1||map[i][j]==1) cout<<map[i][j]<<" ";
			else   cout<<"2 ";
		}
		cout<<endl;
	}
	return 0;	
}
