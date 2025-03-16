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
const int N = 5e3+50;

int n,m,k;
char s[N][N];
int idx[N];
stack<char>st;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int op;
	while(cin>>op){
		if(op == -1) break;
		if(op == 0)
			if(st.empty()) continue;
			else {
				cout<<st.top();
				st.pop();
				continue;
			}
		if(idx[op]>=m) continue;
		if(st.size() == k){
			cout<<st.top();
			st.pop();
		}
		st.push(s[op][idx[op]]);
		idx[op] += 1;
	}
}
