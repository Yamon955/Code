#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int R,C;
char map[1010][1010];
int v[1010][1010];
int total=0;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int judge(int x,int y)
{
	int tmp=0;
	if(map[x][y]=='#') tmp++;
	if(map[x][y+1]=='#') tmp++;
	if(map[x+1][y]=='#') tmp++;
	if(map[x+1][y+1]=='#') tmp++;
	if(tmp==3) return 0;
	else    return 1;
}
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<R && ny<C && map[nx][ny]=='#' && v[nx][ny]==0)
			dfs(nx,ny);
	}
}
int main()
{
	cin>>R>>C;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) cin>>map[i][j];
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			if(!judge(i,j)){
				cout<<"Bad placement.";
				return 0;
			}
		}
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			if(map[i][j]=='#' && v[i][j]==0){
				dfs(i,j);
				total++;
			}
		}
	cout<<"There are "<<total<<" ships.";
	return 0;
}
