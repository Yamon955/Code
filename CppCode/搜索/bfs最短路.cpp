/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3
cout<<7
*/

#include<queue>
#include<iostream>
using namespace std;
int f[100][100],v[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct point{
	int x;
	int y;
	int step;
};
int main()
{
	queue<point> r;
	int m,n,sx,sy,p,q;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	cin>>sx>>sy>>p>>q;
	point start;
	start.x=sx;
	start.y=sy;
	start.step=0;
	r.push(start);
	v[sx][sy]=1;
	int flag=0;
	while(!r.empty()){
		if(r.front().x==p && r.front().y==q){
			flag=1;
			cout<<r.front().step;
			break;
		}
		for(int k=0;k<4;k++){
			int tx,ty;
			tx=r.front().x+dx[k];
			ty=r.front().y+dy[k];
			if(f[tx][ty]==1&&v[tx][ty]==0){
				point temp;
				temp.x=tx;
				temp.y=ty;
				temp.step=r.front().step+1;
				r.push(temp);
				v[tx][ty]=1;
			}
		}
		r.pop();
	}
	if(flag==0) cout<<"no answer!";
	return 0;
}
