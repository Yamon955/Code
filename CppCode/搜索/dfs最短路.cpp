#include<iostream>
#include<stdlib.h>
using namespace std;
int m,n,p,q,x,y;
int w=INT_MAX;//stdlib.hͷ�ļ��µ� ������� 
int f[100][100];//f[][]=1��ʾ�յأ�f[][]=2��ʾ���谭�� 
int v[100][100];//v[][]=0��ʾû��ͨ���˵㣬v[][]=1��ʾ�Ѿ�ͨ���˵� 
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
		return;//���� 
	}
	//��(x,y)�ĸ����� ��->��->��->�� ˳ʱ�����
	//�� 
	if(f[x][y+1]==1 && v[x][y+1]==0){
		v[x][y+1]=1;
		dfs(x,y+1,step+1);
		v[x][y+1]=0;
	}
	//�� 
	if(f[x+1][y]==1 && v[x+1][y]==0){
		v[x+1][y]=1;
		dfs(x+1,y,step+1);
		v[x+1][y]=0;
	}
	//�� 
	if(f[x][y-1]==1 && v[x][y-1]==0){
		v[x][y-1]=1;
		dfs(x,y-1,step+1);
		v[x][y-1]=0;
	}
	//�� 
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
