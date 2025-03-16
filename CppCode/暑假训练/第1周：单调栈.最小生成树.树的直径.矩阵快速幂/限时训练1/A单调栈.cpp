//https://vjudge.net/contest/450213
//AtCoder agc005_b
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
int n;
long long a[200005];
int l[200005],r[200005];
stack<int>st;
long long ans = 0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i] = 1;
        r[i] = n;
        //ans+=a[i];
    }
    for(int i=1;i<=n;i++){
        while(!st.empty() && a[i] < a[st.top()]){
            r[st.top()] = i-1;
            st.pop();
        }
        if(!st.empty()) l[i] = st.top()+1;
        st.push(i);
    }
    for(int i=1;i<=n;i++){
        ans += a[i]*(i-l[i]+1)*(r[i]-i+1);
    }
    cout<<ans<<endl;
    return 0;
}