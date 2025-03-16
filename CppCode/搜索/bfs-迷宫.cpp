#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int m,n,endx,endy;
int map[100][100],v[100][100];
struct point{
	int x;
	int y;
	int step;//到当前位置所需步数 
};
queue<point>r;
int main()
{
	cin>>m>>n;//行列数 
	cin>>endx>>endy;//终点坐标 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	point start;
	start.x=1;
	start.y=1;//起点为（1，1） 
	start.step=0;
	v[1][1]=0;
	r.push(start);//起点入队 
	while(!r.empty()){
		if(r.front().x==endx&&r.front().y==endy) {//找到终点位置输出到达终点所需步数退出循环 
			cout<<r.front().step;
			break;
		}
		for(int i=0;i<4;i++){//队首元素向四个方向拓展 
			int nx=r.front().x+dx[i],ny=r.front().y+dy[i];
			if(nx<1 || ny<1 || nx>m ||ny>n) continue;
			if(v[nx][ny]==0 && map[nx][ny]==1){
				v[nx][ny]=1;
				point tmp;
				tmp.x=nx;
				tmp.y=ny;
				tmp.step=r.front().step+1;
				r.push(tmp);//队首可一步到达的位置入队 
			}
		}
		r.pop();//队首出队 
	}
	if(r.empty()) cout<<"-1";//如果队列为空则说明终点无法到达 
	return 0;
}
/*
5 4
4 3
1 1 0 1
1 1 1 1 
1 1 0 1
1 0 1 1 
1 1 1 0
输出： 7 
*/
