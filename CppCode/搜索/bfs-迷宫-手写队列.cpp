/* 
5 4
4 3
1 1 0 1
1 1 1 1 
1 1 0 1
1 0 1 1 
1 1 1 0
输出   7 
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int m,n,endx,endy;
int front=1,rear=2;
int map[100][100],v[100][100];
struct node{
	int x;
	int y;
	int step;//到当前位置所需步数 
}point[100];
int main()
{
	cin>>m>>n;//行列数 
	cin>>endx>>endy;//终点坐标 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	node start;
	start.x=1;
	start.y=1;
	start.step=0;
	point[front]=start;
	while(front<rear){
		if(point[front].x==endx&&point[front].y==endy){
			cout<<point[front].step;
			break;
		}
		for(int i=0;i<4;i++){
			int nx=point[front].x+dx[i],ny=point[front].y+dy[i];
			if(nx<1||ny<1||nx>m||ny>n) continue;
			if(map[nx][ny]==1&&v[nx][ny]==0){
				v[nx][ny]=1;
				point[rear].x=nx;//入队 
				point[rear].y=ny;
				point[rear].step=point[front].step+1;
				rear=rear+1;
			}
		}
		front++;//出队 
	}
	if(front==rear) cout<<"-1";//无法到达 
	return 0;
}
 
