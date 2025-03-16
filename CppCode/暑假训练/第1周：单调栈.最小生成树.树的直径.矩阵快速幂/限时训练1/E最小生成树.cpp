//BZOJ 2429
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int a[505];
typedef struct node{
	int x,y;
}Tree;
Tree t[1005];
double map[1005][1005];
double dis[1005];
int vis[1005];
int ans;
double getlen(Tree a,Tree b){
	double sum = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	return sqrt(sum);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i].x>>t[i].y;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			map[i][j] = 0x3f3f3f3f;
		}
		dis[i] = 0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			map[i][j] = getlen(t[i],t[j]);
			map[j][i] = getlen(t[i],t[j]);
			//cout<<map[i][j]<<"     ";
		}
		//cout<<endl;
	}
	//cout<<map[1][1]<<endl;
	dis[1] = 0;
	for(int i=1;i<=m;i++){
		double Min = 1e9;
		int k;
		for(int j=1;j<=m;j++){
			if(vis[j]==0 && dis[j] < Min){
				Min = dis[j];
				k = j;
			}
		}
		vis[k] = 1;
		for(int j=1;j<=m;j++){
			if(vis[j]==0 && dis[j] > map[k][j]) dis[j]=map[k][j];
			//cout<<map[k][j]<<endl;
		}
	}
	double Max = 0;
	for(int i=1;i<=m;i++){
		//cout<<dis[i]<<endl;
		if(Max < dis[i]) Max = dis[i];
	}
	//cout<<Max<<endl;
	for(int i=1;i<=n;i++){
		if(a[i]>=Max) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
Sample Input
4
1 2 3 4
6
0 0
1 0
1 2
-1 -1
-2 0
2 2
Sample Output
3
*/