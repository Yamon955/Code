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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e5+50;

//思路：删完每个方案的城市后一条完整的边都不能存在 
int n,m,k;
int u[N],v[N];
int vis[N],p[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i];
	cin>>k;
	while(k--){
		int w;
		cin>>w;
		mem(vis,0);
		for(int i=0;i<=n;i++) p[i] = i;
		while(w--){
			int a;
			cin>>a;
			vis[a] = 1;
		}
		int i;
		for(i=1;i<=m;i++){
			if(!vis[u[i]] && !vis[v[i]]) {
				cout<<"NO"<<endl;
				break;
			}
		}
		if(i > m) cout<<"YES"<<endl;
	}
}


