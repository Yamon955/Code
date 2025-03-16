#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};//�ĸ����� 
int  map[1001][1001],v[1001][1001];//map��ʾͼ��v�Ǳ������ 
int m,n,k;
int _max(int x,int y){return x>y?x:y;}
void dfs(int x,int y)
{
	k++;
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&ny>=0&&nx<m&&ny<n&&map[nx][ny]==1&&v[nx][ny]==0)
			dfs(nx,ny);
	}
}
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) {
			scanf("%d",&map[i][j]);
		}
	int ans=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			k=0;
			if(map[i][j]==1&&v[i][j]==0) dfs(i,j);
			ans=_max(k,ans);
		}
	printf("%d",ans);
	return 0;
}
/* 
��һ��Ϊm,n��ʾͼ�Ĵ�С
���¸���0��ʾ����1��ʾ½�� 
�ʣ����ͼ�����ĵ��죬��������1��½�أ��ĸ��� 
5 5
0 1 1 0 0
1 1 0 0 0
0 0 1 1 0
0 1 1 1 1
0 0 1 1 0
��� 8;
*/ 
