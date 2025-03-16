//POJ 3250
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n;
long long x;
long long ans;
stack<long long>st;
int main()
{
    cin>>n;
    cin>>x;
    st.push(x);
    for(int i=1;i<n;i++){
        cin>>x;
        while(!st.empty() && x >= st.top()) 
            st.pop();
        ans += st.size();
        st.push(x);
    }
    cout<<ans;
    return 0;
}

/*示例输入
6
10
3
7
4
12
2
样本输出
5
*/