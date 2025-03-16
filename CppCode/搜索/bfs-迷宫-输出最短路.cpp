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
};
point pre[100][100];
queue<point>r; 
void print(point tmp)
{
	if(tmp.x==1&&tmp.y==1){
		printf("(1,1)\n");
		return;
	} 
	print(pre[tmp.x][tmp.y]);//逆序输出 
	printf("(%d,%d)\n",tmp.x,tmp.y);
}
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
	v[1][1]=0;
	r.push(start);//起点入队 
	while(!r.empty()){
		if(r.front().x==endx&&r.front().y==endy) break;
		for(int i=0;i<4;i++){
			for(int i=0;i<4;i++){//队首元素向四个方向拓展 
				int nx=r.front().x+dx[i],ny=r.front().y+dy[i];
				if(nx<1 || ny<1 || nx>m ||ny>n) continue;
				if(v[nx][ny]==0 && map[nx][ny]==1){
					v[nx][ny]=1;
					point p;
					p.x=nx;
					p.y=ny;
					r.push(p);
					pre[nx][ny]=r.front();//指向（nx,ny)的父节点 即（nx,ny)的前一个结点 
				}
			}
		}
		r.pop();
	}
	point p;
	p.x=endx;
	p.y=endy;
	print(p);
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
*/ 
