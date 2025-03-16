//POJ 2421
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,m,w,ans;
int map[105][105];
int cnt;
int p[105];
struct Node{
    int u,v,w;
}Ns[10005];
int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
bool cmp(Node a,Node b){
    return a.w<b.w;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=n;i++) p[i] = i;
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(find(u)!=find(v)){
            p[find(u)] = find(v);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            Ns[cnt].u = i;
            Ns[cnt].v = j;
            Ns[cnt].w = map[i][j];
            cnt++;
        }
    sort(Ns,Ns+cnt,cmp);
    for(int i=0;i<cnt;i++){
        if(find(Ns[i].u)!=find(Ns[i].v)){
            p[find(Ns[i].u)] = find(Ns[i].v);
            ans += Ns[i].w;
        }
    }
    cout<<ans;
    return 0;
}
/*
Sample Input
3
0 990 692
990 0 179
692 179 0
1
1 2
Sample Output
179
*/