#include<iostream>
#include<stdlib.h>
using namespace std;
int m,n,p,q,x,y;
int w=INT_MAX;//stdlib.h头文件下的 正无穷大 
int f[100][100];//f[][]=1表示空地，f[][]=2表示有阻碍物 
int v[100][100];//v[][]=0表示没有通过此点，v[][]=1表示已经通过此点 
/*5 4
  1 1 2 1
  1 1 1 1
  1 1 2 1
  1 2 1 1
  1 1 1 2
  1 1 4 3
  out<<7
*/
void dfs(int x,int y,int step)
{
	if(x==p && y==q){
		if(step<w) w=step;
		return;//回溯 
	}
	//从(x,y)四个方向按 右->下->左->上 顺时针遍历
	//右 
	if(f[x][y+1]==1 && v[x][y+1]==0){
		v[x][y+1]=1;
		dfs(x,y+1,step+1);
		v[x][y+1]=0;
	}
	//下 
	if(f[x+1][y]==1 && v[x+1][y]==0){
		v[x+1][y]=1;
		dfs(x+1,y,step+1);
		v[x+1][y]=0;
	}
	//左 
	if(f[x][y-1]==1 && v[x][y-1]==0){
		v[x][y-1]=1;
		dfs(x,y-1,step+1);
		v[x][y-1]=0;
	}
	//上 
	if(f[x-1][y]==1 && v[x-1][y]==0){
		v[x-1][y]=1;
		dfs(x-1,y,step+1);
		v[x-1][y]=0;
	}
	return;
 } 
 int main()
 {
 	cin>>m>>n;
 	for(int i=1;i<=m;i++)
 		for(int j=1;j<=n;j++){
 			cin>>f[i][j];
		 }
	cin>>x>>y>>p>>q;
	v[1][1]=1;
	dfs(x,y,0);
	cout<<w;
	return 0;
  } 
