//HDU 2196
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
int n;

vector<int>map[10005],val[10005];
int vis[10005];
int dis1[10005],dis2[10005];
int va[10005];
int x,y;
int ans[10005];
void dfs(int idx,int step,int dis[]){
    dis[idx] = step;
    for(int i=0;i<map[idx].size();i++){
        if(vis[map[idx][i]]==0){
            vis[map[idx][i]] = 1;
            dfs(map[idx][i],step+val[idx][i],dis);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            map[i].clear();
            val[i].clear();
        }
    for(int i=2;i<=n;i++){
        int u,v,w;
        cin>>v>>w;
        u = i;
        map[u].push_back(v);
        val[u].push_back(w);
        map[v].push_back(u);
        val[v].push_back(w);
    }
    memset(vis,0,sizeof vis);
    vis[1] = 1;
    dfs(1,0,dis1);
    int Max = 0;
    for(int i=1;i<=n;i++){
        if(Max < dis1[i]){
            Max = dis1[i];
            x = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[x] = 1;
    dfs(x,0,dis2);
    Max = 0;
    for(int i=1;i<=n;i++){
        if(Max < dis2[i]){
            Max = dis2[i];
            y = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[y] = 1;
    dfs(y,0,dis1);
    //cout<<x<<" "<<y<<endl;
    for(int i=1;i<=n;i++){
        cout<<max(dis1[i],dis2[i])<<endl;
    } 
    }
    return 0;

}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
int n;
typedef struct node{
    int v;
    int w;
}Node;
vector<Node>map[10005];
int vis[10005];
int dis1[10005],dis2[10005],dis3[10005];
int va[10005];
int x,y;
int ans[10005];
void dfs(int idx,int step,int dis[]){
    dis[idx] = step;
    for(int i=0;i<map[idx].size();i++){
        if(vis[map[idx][i].v]==0){
            vis[map[idx][i].v] = 1;
            dfs(map[idx][i].v,step+map[idx][i].w,dis);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) map[i].clear();
    for(int i=2;i<=n;i++){
        int u,v,w;
        cin>>v>>w;
        u = i;
        Node tmp;
        tmp.v = v;
        tmp.w = w;
        map[u].push_back(tmp);
        tmp.v = u;
        map[v].push_back(tmp);
    }
    memset(vis,0,sizeof vis);
    vis[1] = 1;
    dfs(1,0,dis1);
    int Max = 0;
    for(int i=1;i<=n;i++){
        //cout<<dis1[i]<<" ";
        if(Max < dis1[i]){
            Max = dis1[i];
            x = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[x] = 1;
    dfs(x,0,dis2);
    Max = 0;
    for(int i=1;i<=n;i++){
        if(Max < dis2[i]){
            Max = dis2[i];
            y = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[y] = 1;
    dfs(y,0,dis3);
    for(int i=1;i<=n;i++){
        cout<<max(dis3[i],dis2[i])<<endl;
    } 
    }
    return 0;

}
*/
/*
Sample Input
5
1 1
2 1
3 1
1 1
Sample Output
3
2
3
4
4
*/