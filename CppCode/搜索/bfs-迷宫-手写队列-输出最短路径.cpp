/* 
5 4
4 3
1 1 0 1
1 1 1 1 
1 1 0 1
1 0 1 1 
1 1 1 0
���   7 
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
	int pre;//ָ��ǰһ����㣬��ǰһ�������±� 
}point[100];
void print(int i)
{
	if(point[i].pre==-1){
		printf("(1,1)\n");//ͨ���ݹ������ӡ·�� 
		return;
	}
	else{
		print(point[i].pre);
		printf("(%d,%d)\n",point[i].x,point[i].y);
	}
}
int main()
{
	cin>>m>>n;//������ 
	cin>>endx>>endy;//�յ����� 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	node start;
	start.x=1;
	start.y=1;
	start.pre=-1;// ��ʼ��û�и��ڵ� 
	point[front]=start;
	while(front<rear){//���в��� 
		if(point[front].x==endx&&point[front].y==endy){
			print(front); 
			break;
		}
		for(int i=0;i<4;i++){
			int nx=point[front].x+dx[i],ny=point[front].y+dy[i];
			if(nx<1||ny<1||nx>m||ny>n) continue;
			if(map[nx][ny]==1&&v[nx][ny]==0){
				v[nx][ny]=1;
				point[rear].x=nx;//��� 
				point[rear].y=ny;
				point[rear].pre=front;
				rear=rear+1;
			}
		}
		front++;//���׳��� 
	} 
	return 0;
}
 
