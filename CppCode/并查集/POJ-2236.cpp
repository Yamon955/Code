#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>、
#include<cmath> 
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int N = 1e3+5;
int x[N],y[N];
int n;
double d;
int f[N];
int vis[N];  //记录已经出现的点
int find(int x)
{
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) f[i] = i; //初始化
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	char op[2];
	int p,q;
	while(cin>>op){
		if(op[0] == 'O'){
			cin>>p;
			for(int i=1;i<=n;i++){  //用当前点 p 去更新已经出现的点即 vis[i] = 1 的点 i
				if(vis[i]){
					double dis = sqrt((x[p]-x[i])*(x[p]-x[i]) + (y[p]-y[i])*(y[p]-y[i]));
					if(dis <= d && find(p) != find(i)){  //如果点 i 和 p 之间的距离小于等于 d 并且二者未连接，就连起来
						f[find(p)] = find(i);
					} 
				} 
			}
			vis[p] = 1;
		}
		else{
			cin>>p>>q;
			if(find(f[p]) == find(f[q])){
				cout<<"SUCCESS"<<endl;
			}
			else cout<<"FAIL"<<endl;
		}
	}
}
/*
Sample Input
4 1
0 1
0 2
0 3
0 4
O 1
O 2
O 4
S 1 4
O 3
S 1 4
Sample Output
FAIL
SUCCESS
*/
