//ACwing 164
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<bitset>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 3e4+5;
int m,n;
int in[N],ans[N];
bitset<N>f[N];
struct Edge{
	int to;
	int next;
}edge[N*2];
int h[N],tol;
void add(int u,int v)
{
	edge[tol].to = v;
	edge[tol].next = h[u];
	h[u] = tol++;
}
void topsort()
{
	int cnt = 0;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(in[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans[++cnt] = u;  //记录拓扑顺序
		for(int i=h[u];i!=-1;i=edge[i].next){
			int v = edge[i].to;
			in[v] --;
			if(in[v] == 0) q.push(v);
		}
		
	}
}
int main()
{
	cin>>n>>m;
	mem(h,-1);
	tol = 0;
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v);
		in[v]++;
	}
	topsort();
	for(int i=n;i>=1;i--){
		int v = ans[i];
		f[v][v] = 1; //表示将 f[v] 的第 v 位置为 1
        //假设 u-->v1,u-->v2,......u-->vn
        //那么结点 u 可以到达的点数量为 f[u] = (f[v1] U f[v2] U f[v3] U .... U f[vn])
		for(int i=h[v];i!=-1;i=edge[i].next){
			f[v] |= f[edge[i].to];
		}
	}
	for(int i=1;i<=n;i++) cout<<f[i].count()<<endl; //输出每个结点 i 中每一位 1 的个数，即结点 i 经过的点的个数
}
/*
输入样例：
10 10
3 8
2 3
2 5
5 9
5 9
2 3
3 9
4 8
2 10
4 9
输出样例：
1
6
3
3
2
1
1
1
1
1
*/

