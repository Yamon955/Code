#include<iostream>
#include<queue>
#include<stack>
#define MAXN 51
using namespace std;
 
struct node{
	int x,y;
}p;
 
stack<node> path,temp;
int n,m;
int sx,sy,ex,ey;
char map[MAXN][MAXN];
bool book[MAXN][MAXN]={false};
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int count=0;
 
void dfs(int x,int y)
{	
	for(int i=0;i<4;i++)
	{
		int gx=x+next[i][0];
		int gy=y+next[i][1];
		if(gx==ex&&gy==ey)
		{
	                cout << "********************·��" << ++count << "********************\n";
			//��path����ĵ�ȡ����������temp���� 
			while(!path.empty())
			{
				//path��ջ����ջ�׷���·���Ǵ��յ㵽���ķ���
				node p1=path.top();
				path.pop();
				temp.push(p1); 
			}
			while(!temp.empty())
			{					
				//���temp�������е�·��  ���������Ǵ���㵽�յ�ķ���
				node p1=temp.top();
				temp.pop();
				path.push(p1);		//�����path������Ϊ���滹Ҫ����
				cout << "( " << p1.x << " , " << p1.y << " )\n";  
			}
			cout << "( " << ex << " , " << ey << " )\n"; 
			return;
		}			
		if(gx<1||gx>n||gy<1||gy>m)
			continue;
		if(book[gx][gy]==false&&map[gx][gy]=='.')
		{
			book[gx][gy]=true;
			p.x=gx;
			p.y=gy;
			path.push(p);			
			dfs(gx,gy);
			//���� 
			book[gx][gy]=false;
			path.pop();
		}
	}
	return;
}
 
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='S')
				sx=i,sy=j;
			if(map[i][j]=='G')
				ex=i,ey=j;
		}
	dfs(sx,sy);	
	return 0;
}
