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
const int N = 1e5+50;

int n;
set<int>se;
int main()
{
	cin>>n;

	for(int i=1;i<=n;i++){
		int now;
		scanf("%d",&now);
		set<int>::iterator it = se.lower_bound(now);
		if(it != se.end()){
			se.erase(it);
			se.insert(now);
		}
		else se.insert(now);
	}
	cout<<se.size();
		
}
