#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
typedef long long ll;
int m,n,k;
int vis[100005];
ll cnt;
struct Node{
    int u;
    int v;
    ll  w;
}Ns[100005];
bool cmp(Node a,Node b){
    return a.w < b.w;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Ns[i].u = u;
        Ns[i].v = v;
        Ns[i].w = w;
    }
    for(int i=1;i<=k;i++){
        int a;
        cin>>a;
        vis[a] = 1;
    }
    //sort(Ns,Ns+m,cmp);
    ll ans = 0x3f3f3f3f;
    for(int i=1;i<=m;i++){
        if((vis[Ns[i].u]==0&&vis[Ns[i].v]!=0) || (vis[Ns[i].v]==0&&vis[Ns[i].u]!=0) ){
            ans = min(ans,Ns[i].w);
        }  
    }
    if(ans<0x3f3f3f3f) cout<<ans<<endl;
    else cout<<"-1";
    return 0;

}
/*
Examples
Input
5 4 2
1 2 5
1 2 3
2 3 4
1 4 10
1 5
Output
3
Input
3 1 1
1 2 3
3
Output
-1
*/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
typedef long long ll;
int m,n,k;
int vis[100005];
ll cnt;
struct Node{
    int u;
    int v;
    ll  w;
}Ns[100005];
bool cmp(Node a,Node b){
    return a.w < b.w;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Ns[i].u = u;
        Ns[i].v = v;
        Ns[i].w = w;
    }
    for(int i=1;i<=k;i++){
        int a;
        cin>>a;
        vis[a] = 1;
    }
    ll ans = -1;
    sort(Ns+1,Ns+m+1,cmp);
    for(int i=1;i<=m;i++){
        if((vis[Ns[i].u]==0&&vis[Ns[i].v]!=0) || (vis[Ns[i].v]==0&&vis[Ns[i].u]!=0) ){
            ans = Ns[i].w;
            break;
        }  
    }
    cout<<ans;
    return 0;

}
*/