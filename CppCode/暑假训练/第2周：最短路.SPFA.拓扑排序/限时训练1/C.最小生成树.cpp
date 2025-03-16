//POJ2253
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
int n;
struct Edge{
	int u,v;
	double w;
};
struct point{
	double x,y;
};
point p[N];
Edge edge[N*1000];
int f[N],cnt,tol;
double getlen(point a,point b)
{
	return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]!=x) f[x] = find(f[x]);
	return f[x];
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		cnt++;
		tol = 0;
		for(int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				++tol;
				edge[tol].u = i;
				edge[tol].v = j;
				edge[tol].w = getlen(p[i],p[j]);
			}
		}
		sort(edge+1,edge+tol+1,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=tol;i++){
			int u = edge[i].u;
			int v = edge[i].v;
			if(find(u)!=find(v)){
				f[find(u)] = find(v);
			}
			if(find(1)==find(2)){  //一旦1和2相连，则此时的边就是可以连通1和2的路径的最大的间隔
				cout<<"Scenario #"<<cnt<<endl;
				printf("Frog Distance = %.3f\n\n",edge[i].w);
				break;
			}
            
		}
		
	}
	
	return 0;
}
/*
Sample Input
2
0 0
3 4

3
17 4
19 4
18 5

0
Sample Output
Scenario #1
Frog Distance = 5.000

Scenario #2
Frog Distance = 1.414
*/