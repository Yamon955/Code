#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e3+50;

int n,m,k,cnt;
int num[N];
int p[N];
int u[N],v[N]; 
int vis[N];
int exist[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) p[i] = i;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		if(p[u[i]] != p[v[i]]){
			p[find(u[i])] = find(v[i]);
		}
	}
	
	cin>>k;
	for(int i=1;i<=k;i++) cin>>num[i];
	for(int i=0;i<n;i++) if(p[i] == i) cnt++;
	
	for(int i=1;i<=k;i++){
		exist[num[i]] = 1; //标记摧毁点
		for(int j=0;j<n;j++) p[j] = j;
		for(int j=1;j<=m;j++){
			if(vis[j]) continue;  //该边被摧毁不能使用
			else if(u[j] == num[i] || v[j] == num[i]){
				vis[j] = 1; //标记摧毁的边
			}
			else{
				if(p[u[j]] != p[v[j]]){
					p[find(u[j])] = find(v[j]);
				}
			}
		}
		int tmp = 0;
		for(int j=0;j<n;j++) if(p[j] == j && !exist[j]) tmp++; //当前点是根节点并且还没有被摧毁
		//cout<<tmp<<" "<<cnt<<endl;
		if(tmp > cnt) {
			printf("Red Alert: City %d is lost!\n",num[i]);
			cnt = tmp;
		}
		else{
			printf("City %d is lost.\n",num[i]);
			cnt = tmp;
		}
	}
	if(k == n) printf("Game Over.");
	return 0;
}

/*
dfs做法

#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e3+50;

int n,m,k,cnt;
int map[N][N];
int vis[N];

void dfs(int u)
{
	vis[u] = 1;
	for(int i=0;i<n;i++){
		if(vis[i] == 0 && map[u][i] != 0){
			dfs(i);
		}
	}
}
int caculate()
{
	int cnt = 0;
	mem(vis,0);
	for(int i=0;i<n;i++){
		if(vis[i] == 0){
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		map[u][v] = map[v][u] = 1;
	}
	cin>>k;
	cnt = caculate();
	for(int i=1;i<=k;i++){
		int city;
		cin>>city;
		for(int j=0;j<n;j++){
			if(map[city][j]){
				map[city][j] = map[j][city] = 0;
			}
		}
		int tmpcnt = caculate();
		if(tmpcnt > cnt+1){
			printf("Red Alert: City %d is lost!\n",city);
		}
		else{
			printf("City %d is lost.\n",city);
		}
		cnt = tmpcnt; //更新当前的连通分量数 
	}
	if(k == n) printf("Game Over.");
	return 0;

}

*/

