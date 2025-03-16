#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int m,n;
char map[51][51];
int v[51][51];
int MIN=1e9; 
int sx,sy,gx,gy;
struct point{
	int x,y;
};
stack<point>path,tmp,path_end;//path_end栈用来存放最短路径 
void dfs(int x,int y,int step)
{
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx==gx && ny==gy){
			if(step<MIN){//若小于最小路径，把路径存入栈tmp,path_end 
				while(!path_end.empty()){//清空非最短路径 
					path_end.pop();
				}
				while(!path.empty()){
					point p=path.top();
					path.pop();
					tmp.push(p);
					path_end.push(p);
				}
				while(!tmp.empty()){
					point p=tmp.top();
					tmp.pop();
					path.push(p);
				}
			}
		}
		if(nx<1||ny<1||nx>m||ny>n) continue;
		if(map[nx][ny]=='.'&&v[nx][ny]==0){
			v[nx][ny]=1;
			point p;
			p.x=nx;
			p.y=ny;
			path.push(p);
			dfs(nx,ny,step+1);
			//回溯 
			v[nx][ny]=0;
			path.pop();
		}
	}
	return ;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
			if(map[i][j]=='S'){
				sx=i;sy=j;
			}
			else if(map[i][j]=='G'){
				gx=i;gy=j;
			}
		}
	dfs(sx,sy,0);
	while(!path_end.empty()){
		point p=path_end.top();
		path_end.pop();
		cout<<"("<<p.x<<" , "<<p.y<<")"<<endl;
	}	
	cout<<"("<<gx<<" , "<<gy<<")"<<endl;	
	return 0;
}
/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/ 
