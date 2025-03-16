//CodeForces 817D
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[1000005];
int l[1000005],r[1000005];
int L[1000005],R[1000005];
long long sum,sub;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        l[i] = L[i] = 1;
        r[i] = R[i] = n;
    }
    stack<int>st;
    for(int i=1;i<=n;i++){
        while(!st.empty() && a[st.top()] > a[i]){
            int tmp = st.top();
            st.pop();
            r[tmp] = i-1;
        }
        if(!st.empty()) l[i] = st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=1;i<=n;i++){
        while(!st.empty() && a[st.top()] < a[i]){
            int tmp = st.top();
            st.pop();
            R[tmp] = i-1;
        }
        if(!st.empty()) L[i] = st.top()+1;
        st.push(i);
    }
    for(int i=1;i<=n;i++){
        //cout<<l[i]<<" "<<r[i]<<" "<<L[i]<<" "<<R[i]<<endl;
		sub += 1ll * a[i]*(i-l[i]+1) * (r[i]-i+1);
        sum += 1ll * a[i]*(i-L[i]+1) * (R[i]-i+1);
	 }
	cout<<sum-sub;
	return 0;
	
}
/*
Input
3
1 4 1
Output
9
*/