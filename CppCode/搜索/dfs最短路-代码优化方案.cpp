#include<iostream>
#include<stdlib.h>
using namespace std;
int m,n,p,q,x,y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; 
int w=INT_MAX;//stdlib.hͷ�ļ��µ� ������� 
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
		return;//���� 
	}
	//��(x,y)�ĸ����� ��->��->��->�� ˳ʱ�����
	//��������������dx,dy��ʾ�ĸ�����
	//һ��forѭ������˳�������ǰ����ĸ����� 
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
	v[1][1]=1;//�������� 
	dfs(x,y,0);
	cout<<w;
	return 0;
  } 
