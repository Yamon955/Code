#include<iostream>
#include<stdlib.h>
using namespace std;
int m,n,p,q,x,y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; 
int w=INT_MAX;//stdlib.h头文件下的 正无穷大 
int f[100][100],v[100][100];
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
	//用两个方向数组dx,dy表示四个方向
	//一层for循环按照顺序遍历当前点的四个方向 
	for(int k=0;k<4;k++){
		int tx=x+dx[k];
		int ty=y+dy[k];
		if(f[tx][ty]==1 && v[tx][ty]==0){
			v[tx][ty]=1;
			dfs(tx,ty,++step);
			v[tx][ty]=0;
		} 
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
	v[1][1]=1;//截至条件 
	dfs(x,y,0);
	cout<<w;
	return 0;
  } 
