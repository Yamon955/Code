//POJ3037
//此题每个点的速度实际上是一个定值
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const double inf = 1e12; //这题卡数据范围，const int inf=0x3f3f3f3f就过不了
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
const int N = 105;
int v0,r,c;
double v[N][N],dis[N][N];
int h[N][N];
int vis[N][N];
struct node{
    int x,y;
};
void spfa()
{
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++) 
            dis[i][j] = inf;
    queue<node>q;
    dis[1][1] = 0;
    vis[1][1] = 1;
    node tmp ={1,1};
    q.push(tmp);
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        vis[tmp.x][tmp.y] = 0;
        for(int i=0;i<4;i++){
            int nx = tmp.x+dx[i],ny = tmp.y+dy[i];
            if(nx<1||ny<1||nx>r||ny>c) continue;
            if(dis[nx][ny]>dis[tmp.x][tmp.y]+1.0/v[tmp.x][tmp.y]){
                dis[nx][ny]=dis[tmp.x][tmp.y]+1.0/v[tmp.x][tmp.y];
                if(!vis[nx][ny]){
                    node tp = {nx,ny};
                    q.push(tp);
                    vis[nx][ny] = 1;
                }
            }
        }
    }
}
int main()
{
	scanf("%d%d%d",&v0,&r,&c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
            scanf("%d",&h[i][j]);
            v[i][j] = v0*pow(2,h[1][1]-h[i][j]);
		}
	}
    spfa();
	printf("%.2f\n",dis[r][c]);
	return 0;
}
/*
Sample Input
1 3 3
1 5 3
6 3 5
2 4 3
Sample Output
29.00
*/