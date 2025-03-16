#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int m,n,v[1010][1010],sx,sy,total,ans[1010][1010];//ans用来存放（x,y）的可走步数 
char map[1010][1010];
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct point{
	int x,y;
}; 
queue<point>r,r2;//r2用来存放以及走过的点，这些点的可走步数都是一样的（解题关键） 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>map[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(ans[i][j]==0&&v[i][j]==0){
				total=1;
				point p;
				p.x=i;
				p.y=j;
				r.push(p);
				r2.push(p);
				v[i][j]=1;
				while(!r.empty()){
					for(int i=0;i<4;i++){
						int nx=r.front().x+dx[i],ny=r.front().y+dy[i];
						if(nx<1||ny<1||nx>n||ny>n) continue;
						if(((map[nx][ny]=='0'&&map[r.front().x][r.front().y]=='1')||(map[nx][ny]=='1'&&map[r.front().x][r.front().y]=='0')) && v[nx][ny]==0){
							v[nx][ny]=1;
							point p;
							p.x=nx;
							p.y=ny;
							r.push(p);
							r2.push(p);
							total++;
							}
					}
					r.pop();
				}
				while(!r2.empty()){
					int x=r2.front().x;
					int y=r2.front().y;
					ans[x][y]=total;
					r2.pop();
				}
			}
		}
	for(int i=1;i<=m;i++){
		cin>>sx>>sy;
		cout<<ans[sx][sy]<<endl;
	}	
	return 0;
}
