//https://www.dotcpp.com/oj/problem2606.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 2e5+50;

int n;
vector<int>v[N];
int f[N];

void dfs(int u)
{
	f[u] = v[u].size();
	int Max = 0;
	for(int i=0;i<v[u].size();i++){
		int to = v[u][i];
		dfs(to);
		Max = max(Max,f[to]);
	}
	f[u] += Max; 
}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int u;scanf("%d",&u);
		v[u].push_back(i);
	}
	dfs(1);
	cout<<f[1]<<endl;
}