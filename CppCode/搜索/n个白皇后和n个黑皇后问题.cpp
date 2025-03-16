/*
给定一个n*n的棋盘，现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
*/
#include<iostream>
#include<cstring>
using namespace std;
int b[1000],c[1000],d[1000];
int e[1000],f[1000],g[1000];
int map[10][10];
int total=0;
int n;
void queen2(int x)
{
	if(x>n){
		total++;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(e[j]==0 && f[x+j]==0 && g[x-j+n]==0 && map[x][j]==0){
			e[j]=1;
			f[x+j]=1;
			g[x-j+n]=1;
			map[x][j]=1;
			queen2(x+1);
			e[j]=0;
			f[x+j]=0;
			g[x-j+n]=0;
			map[x][j]=0;
		}
	}
	
}
void queen1(int x)
{
	if(x>n) {
		queen2(1);//先将n个白皇放好后放再放黑皇后，两个函数的区别在于白皇后所在的空黑皇后不能放 
		return;
	}
	for(int j=1;j<=n;j++){
		if(b[j]==0 && c[x+j]==0 && d[x-j+n]==0){
			b[j]=1;
			c[x+j]=1;
			d[x-j+n]=1;
			map[x][j]=1;
			queen1(x+1);
			b[j]=0;
			c[x+j]=0;
			d[x-j+n]=0;
			map[x][j]=0;
		}
	}
 } 
int main()
{
	int T;
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) map[i][j]=0; 
		cin>>n;
		total=0;
		queen1(1);
		cout<<total<<endl;
	}
	
	return 0;
 } 
