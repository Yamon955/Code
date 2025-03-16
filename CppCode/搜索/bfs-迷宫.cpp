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
	int step;//����ǰλ�����貽�� 
};
queue<point>r;
int main()
{
	cin>>m>>n;//������ 
	cin>>endx>>endy;//�յ����� 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	point start;
	start.x=1;
	start.y=1;//���Ϊ��1��1�� 
	start.step=0;
	v[1][1]=0;
	r.push(start);//������ 
	while(!r.empty()){
		if(r.front().x==endx&&r.front().y==endy) {//�ҵ��յ�λ����������յ����貽���˳�ѭ�� 
			cout<<r.front().step;
			break;
		}
		for(int i=0;i<4;i++){//����Ԫ�����ĸ�������չ 
			int nx=r.front().x+dx[i],ny=r.front().y+dy[i];
			if(nx<1 || ny<1 || nx>m ||ny>n) continue;
			if(v[nx][ny]==0 && map[nx][ny]==1){
				v[nx][ny]=1;
				point tmp;
				tmp.x=nx;
				tmp.y=ny;
				tmp.step=r.front().step+1;
				r.push(tmp);//���׿�һ�������λ����� 
			}
		}
		r.pop();//���׳��� 
	}
	if(r.empty()) cout<<"-1";//�������Ϊ����˵���յ��޷����� 
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
����� 7 
*/
