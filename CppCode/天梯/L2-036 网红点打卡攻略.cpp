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
const int N = 5e2+50;

int n,m,k;
int map[N][N];
int cnt;
int Min = inf;
int ans;
int tmp[N];
int main()
{
	mem(map,-1);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b] = map[b][a] = c;
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		int num;
		cin>>num;
		set<int>s;
		int last = 0;
		int flag = 0;
		int sum = 0;
		for(int j=1;j<=num;j++){
			cin>>tmp[j];
			s.insert(tmp[j]);
		}
		if(s.size() != n || num > n) continue;
		for(int j=1;j<=num;j++){
			if(map[last][tmp[j]] == -1){
				flag = 1;
				break;
			} 
			else {
				sum += map[last][tmp[j]];
				last = tmp[j];
			}
		}
		if(map[last][0] == -1) flag = 1;
		else sum += map[last][0];
		if(flag == 0){
			cnt ++;
			if(sum < Min){
				Min = sum;
				ans = i;
			}
		}
		
	}
	cout<<cnt<<endl;
	cout<<ans<<" "<<Min<<endl;
}
