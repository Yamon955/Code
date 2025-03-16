//BZOJ 1113
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n;
long long a[250005];
long long b,ans;
stack<long long>st;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.top()]>a[i]){
            st.pop();
            ans++;
        }
        if(st.empty() || a[st.top()]<a[i]){
            st.push(i);
        }
    }
    if(st.size()>=1) ans += st.size();
    cout<<ans;
    return 0;
}
/*
Sample Input
5
1 2
1 3
2 2
2 5
1 4

Sample Output
4
*/