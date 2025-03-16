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
int sx,sy,gx,gy,count=0;
struct point{
	int x,y;
};
stack<point>path,tmp;
void dfs(int x,int y)
{
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx==gx && ny==gy){
			cout << "********************路径" << ++count << "********************\n";
			//将path里面的点取出来，放在temp里面
			while(!path.empty()){
				//path从栈顶到栈底方向，路径是从终点到起点的方向
				point p=path.top();
				path.pop();
				tmp.push(p);
			}
			while(!tmp.empty()){
				//输出temp里面所有的路径  这样正好是从起点到终点的方向
				point p=tmp.top();
				tmp.pop();
				path.push(p);//存放在path里面因为后面还要回溯 
				cout<<"("<<p.x<<" , "<<p.y<<")"<<endl;
			}
			cout<<"("<<gx<<" , "<<gy<<")"<<endl;
			return ;
		}
		if(nx<1||ny<1||nx>m||ny>n) continue;
		if(map[nx][ny]=='.'&&v[nx][ny]==0){
			v[nx][ny]=1;
			point p;
			p.x=nx;
			p.y=ny;
			path.push(p);
			dfs(nx,ny);
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
	dfs(sx,sy);		
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
