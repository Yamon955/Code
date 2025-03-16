#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
char map[1005][1005];
int Max;
int solve(int a[])
{
    stack<int>st;
    int l[1005],r[1005];
    for(int i=1;i<=m;i++){
        l[i] = 1;
        r[i] = m;
    }
    for(int i=1;i<=m;i++){
        while(!st.empty() && a[i] < a[st.top()]){
            r[st.top()] = i-1;
            st.pop();
        }
        if(!st.empty()) l[i] = st.top()+1;
        st.push(i);
    }
    int Max = 0;
    for(int i=1;i<=m;i++){
        Max = max(Max,a[i]*(r[i]-l[i]+1));
    }
    return Max;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>map[i][j];
    }
    for(int i=1;i<=n;i++){
        int a[1005];
        memset(a,0,sizeof a);
        for(int j=1;j<=m;j++){
            for(int k=i;k>=1;k--){
                if(map[k][j]=='R') break;
                a[j]++;
            }
        }
        Max = max(Max,solve(a));
    }
    cout<<3*Max<<endl;
    return 0;
}