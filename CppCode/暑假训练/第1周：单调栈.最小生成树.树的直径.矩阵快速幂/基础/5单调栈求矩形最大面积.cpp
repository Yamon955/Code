#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int N = 5e4+5;
const int inf = 0x3f3f3f3f;

int n;
int l[N],r[N],a[N];
int main()
{
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			l[i] = 1;
			r[i] = n;
		}
		stack<int>st;
		for(int i=1;i<=n;i++){
			if(!st.empty() && a[st.top()] > a[i]){
				r[st.top()] = i-1;
				st.pop();
			}
			if(!st.empty()) l[i] = st.top()+1;
			st.push(i);
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" :"<<l[i]<<" "<<r[i]<<endl;
//		}
		int ans = 0;
		for(int i=1;i<=n;i++){
        	int len = r[i]-l[i]+1;
        	long long tmp = 1ll*len*a[i];
        	if(ans < tmp) ans = tmp;
    	}
    	cout<<ans<<endl;
	}
}