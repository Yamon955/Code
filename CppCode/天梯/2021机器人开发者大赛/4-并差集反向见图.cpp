/*
支持两种操作
（1）删除一个点
（2）询问两个点是否联通

首先，询问两个点是否联通可以很容易地想到并查集
其次，对于依次删除图中的结点，启发我们将顺序删除操作变为逆序添加操作进行处理
最后，由于是删除一部分点，所以要把边先存一下，删完点做并集，每次加点也要做并集
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#include<map>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
const int M = 4e5+5;
const int D = 1e3+5;
int n,m,d;
struct Edge{
	int v;
	int next;
};
Edge e[M*2];
int h[N],tol=1;
struct node{
	int x,y;
};
node Ns[M];
vector<node>c[D];

int del[D];
int vis[N],p[N];
int ans[D];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
void add(int u,int v)
{
	e[tol].v = v;
	e[tol].next = h[u];
	h[u] = tol++;
}
int main()
{
	cin>>n>>m>>d;
	mem(h,-1);
	for(int i=1;i<=n;i++) p[i] = i;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Ns[i] = {x,y};
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=d;i++){
		int k;
		cin>>del[i]>>k;
		vis[del[i]] = 1;
		while(k--){
			int x,y;
			cin>>x>>y;
			c[i].push_back({x,y});
		}
	}
	for(int i=1;i<=m;i++){
		int x = Ns[i].x;
		int y = Ns[i].y;
		if(!vis[x] && !vis[y]){
			p[find(y)] = find(x);
		}
	}
	for(int i=d;i>=1;i--){
		int cnt = 0;
		for(int j=0;j<c[i].size();j++){
			if(find(c[i][j].x) != find(c[i][j].y)) cnt++;
		}
		vis[del[i]] = 0;
		ans[i] = cnt;
		for(int j=h[del[i]];j!=-1;j=e[j].next){
			int y = e[j].v;
			if(!vis[y]){
				int fa = find(del[i]);
				int fb = find(y);
				p[fb] = fa;
			}
		}
	}
	for(int i=1;i<=d;i++) cout<<ans[i]<<endl;
	//cout<<ans[d];

}
/*
5 5 3
1 2
1 3
1 5
2 5
3 4

4 3
1 3
1 4
2 3

5 3
3 4
2 3
3 5

1 3
2 3
2 5
3 4

--->
1
2
3
*/
