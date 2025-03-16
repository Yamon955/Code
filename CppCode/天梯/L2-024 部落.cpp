#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e4+50;

int n,m,cnt,ans;
int p[N];
int vis[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	cin>>n;
	for(int i=1;i<N;i++) p[i] = i;
	while(n--){
		int k,last,now;
		cin>>k;
		if(k > 0){
			cin>>last;
			cnt = max(cnt,last);
		} 
		for(int i=2;i<=k;i++){
			cin>>now;
			cnt = max(cnt,now);
			if(find(now) != find(last)){
				p[find(now)] = find(last);
			}
			last = now;
		}
	}
	for(int i=1;i<=cnt;i++) if(p[i] == i) ans++;
	cout<<cnt<<" "<<ans<<endl;
	
	cin>>m;
	while(m --){
		int u,v;
		cin>>u>>v;
		if(find(u) == find(v)){
			cout<<"Y"<<endl;
		}
		else cout<<"N"<<endl;
	}
	return 0;
}