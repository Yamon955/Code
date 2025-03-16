//HDU1026
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int n,m;
int map[N][N],vis[N][N];
struct node{
    int x;
    int y;
    int step;
    node(){}
    node(int a,int b,int c){
        x = a;
        y = b;
        step = c;
    }
    bool operator< (const node &a)const{
        return step > a.step;
    }
};
node pre[N][N];
void print(node tmp)
{
    if(tmp.x==0 && tmp.y==0){
        pre[tmp.x][tmp.y] = tmp;
        return ;
    }
    print(pre[tmp.x][tmp.y]);
    if(tmp.step == pre[tmp.x][tmp.y].step+1){
        printf("%ds:(%d,%d)->(%d,%d)\n",tmp.step,pre[tmp.x][tmp.y].x,pre[tmp.x][tmp.y].y,tmp.x,tmp.y);
    }
    else{
        printf("%ds:(%d,%d)->(%d,%d)\n",pre[tmp.x][tmp.y].step+1,pre[tmp.x][tmp.y].x,pre[tmp.x][tmp.y].y,tmp.x,tmp.y);
            for(int j=pre[tmp.x][tmp.y].step+2;j<=tmp.step;j++){
                printf("%ds:FIGHT AT (%d,%d)\n",j,tmp.x,tmp.y);
            }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch;
                cin>>ch;
                if(ch=='.') map[i][j] = 1;
                else if(ch=='X') map[i][j] = -1;
                else map[i][j] = ch-'0'+1;
            }
        }
        memset(vis,0,sizeof vis);
        priority_queue<node>q;
        q.push(node(0,0,0));
        vis[0][0] = 1;
        while(!q.empty()){
            node top = q.top();
            int x = top.x;
            int y = top.y;
            int step = top.step;
            if(x==n-1 && y==m-1){
                break;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]==-1||vis[nx][ny]) continue;
                q.push(node(nx,ny,step+map[nx][ny]));
                vis[nx][ny] = 1;
                pre[nx][ny] = node(x,y,step);
             }
        }
        if(q.empty()){
            printf("God please help our poor hero.\nFINISH\n");
        }
        else{
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",q.top().step);
            print(q.top());
            printf("FINISH\n");
        }
        
    }
    return 0;
}
/*
Sample Input
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX.
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX1
5 6
.XX...
..XX1.
2...X.
...XX.
XXXXX.
Sample Output
It takes 13 seconds to reach the target position, let me show you the way.
1s:(0,0)->(1,0)
2s:(1,0)->(1,1)
3s:(1,1)->(2,1)
4s:(2,1)->(2,2)
5s:(2,2)->(2,3)
6s:(2,3)->(1,3)
7s:(1,3)->(1,4)
8s:FIGHT AT (1,4)
9s:FIGHT AT (1,4)
10s:(1,4)->(1,5)
11s:(1,5)->(2,5)
12s:(2,5)->(3,5)
13s:(3,5)->(4,5)
FINISH
It takes 14 seconds to reach the target position, let me show you the way.
1s:(0,0)->(1,0)
2s:(1,0)->(1,1)
3s:(1,1)->(2,1)
4s:(2,1)->(2,2)
5s:(2,2)->(2,3)
6s:(2,3)->(1,3)
7s:(1,3)->(1,4)
8s:FIGHT AT (1,4)
9s:FIGHT AT (1,4)
10s:(1,4)->(1,5)
11s:(1,5)->(2,5)
12s:(2,5)->(3,5)
13s:(3,5)->(4,5)
14s:FIGHT AT (4,5)
FINISH
God please help our poor hero.
FINISH
*/