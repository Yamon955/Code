//https://vjudge.net/contest/449425#problem
//CodeForces 320D
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n;
int a[100005];
int ans;
typedef struct node{
    int data,step;
}Node;
Node node[100005];
stack<Node>st;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int tmp = 0;
        while(!st.empty() && st.top().data < a[i]){
            tmp = max(tmp,st.top().step);
            st.pop();
        }
        Node p;
        p.data = a[i];
        p.step = st.empty() ? 0:tmp+1;
        ans = max(ans,p.step);
        st.push(p);
    }
    cout<<ans<<endl;
    return 0;
}
/*
Input
10
10 9 7 8 6 5 3 4 2 1
Output
2
Input
6
1 2 3 4 5 6
Output
0
*/