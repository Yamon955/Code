#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,m;
int map[30][30];
int best;
int vis[30];
bool check(int x,int i)
{
    for(int j=1;j<=n;j++){
        if(map[x][j]==1&&vis[j]==i) return false;
    }
    return true;
}
void Backtrack(int x)
{
    if(x>n){
        best++;
        return;
    }
    for(int i=1;i<=m;i++){
        if(check(x,i)){
            vis[x] = i;
            Backtrack(x+1);
            vis[x] = 0;
        }
    }
}
int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        map[u][v] = map[v][u] = 1;
    }
    Backtrack(1);
    cout<<best;
    return 0;

}