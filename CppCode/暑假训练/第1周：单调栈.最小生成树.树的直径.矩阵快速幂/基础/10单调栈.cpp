#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n;
int a[100005];
int l[100005],r[100005];
long long ans=-1; //ans一定要等于-1， 对于样例 1 0 ---> 0 1 1,  如果ans==0  样例1 0-->0 0 0
long long sum[100005];
int best_l,best_r;
stack<int>st;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
    	//cin>>a[i];卡了cin
        scanf("%d",&a[i]);
    	sum[i] += sum[i-1]+a[i];//前缀和
        l[i] = 1;
        r[i] = n;
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
        long long tmp = 1ll*a[i]*(sum[r[i]] - sum[l[i]-1]);
        if(ans < tmp) {
            ans = tmp;
            best_l = l[i];
            best_r = r[i];
        }
    }
    cout<<ans<<endl;
    cout<<best_l<<" "<<best_r;
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n;
int a[100005];
int l[100005],r[100005];
long long ans = -1,sum[100005];
int best_l,best_r;
int st[100005];
int top;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	sum[i] += sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        while(top>0 && a[st[top-1]]>=a[i])
            top--;
        l[i] = top==0 ? 1:st[top-1]+1;
        st[top++] = i;
    }
    top = 0;
    for(int i=n;i>=1;i--){
        while(top>0 && a[st[top-1]]>=a[i])
            top--;
        r[i] = top==0 ? n:st[top-1]-1;
        st[top++] = i;
    }
    for(int i=1;i<=n;i++){
        long long tmp = a[i]*(sum[r[i]] - sum[l[i]-1]);
        if(ans < tmp){
            ans = tmp;
            best_l = l[i];
            best_r = r[i];
        }
    }
    cout<<ans<<endl;
	cout<<best_l<<" "<<best_r;
    return 0;

}*/