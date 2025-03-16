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
const int N = 1e6+50;

int n,m,k;

int main()
{
	cin>>n>>m>>k;
	while(k --){
		stack<int>st;
		int last = 1;
		int flag = 0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			if(a > last){
				while(!st.empty()){
					int w = st.top();
					if(w == last){
						st.pop();
						last += 1;
					}
					else break;
				}
				if(a > last){
					st.push(a);
					if(st.size() > m) flag = 1;
				}
				else if(a == last){
					last += 1;
				}
			}
			else if(a == last){
				last += 1;
			}
			
		}
		while(!st.empty()){
					int w = st.top();
					if(w == last){
						st.pop();
						last += 1;
					}
					else break;
		}
		if(flag || last <= n) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
 } 

