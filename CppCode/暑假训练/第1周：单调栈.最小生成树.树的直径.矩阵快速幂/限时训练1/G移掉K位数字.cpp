#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
int n,k;
int a[10005],ans[10005];
int vis[10005];
int main()
{
    cin>>n;
    if(n==k){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        a[i] = ch-'0';
    }
    cin>>k;
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){ 
            vis[i] = 1;
            k --;
        }
        if(k==0) break;
    }
    if(k!=0){
        for(int i=n;i>=1;i--){
            if(vis[i]==0) {
                vis[i]=1;
                k--;
            }
            if(k==0) break;
        } 
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0)  ans[++cnt] = a[i];
    }
    if(ans[1]!=0) cout<<ans[1];
    for(int i=2;i<=cnt;i++){
        //if(i==1 && a[i]==0) continue;
        cout<<ans[i];
    }
    return 0;
}