//POJ 1985
#include <queue>
#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
int m,n;
struct Node{
    int v;
    int w;
    int next;
}Edge[100000];
int head[50000],vis[50000],idx;
void add(int u,int v,int w)
{
    Edge[idx].v = v;
    Edge[idx].w = w;
    Edge[idx].next = head[u];
    head[u] = idx++;
}
int bfs(int st,int flag)
{
    int Max = 0,Max_i=st;
    queue<int>q;
    memset(vis,-1,sizeof vis);
    vis[st] = 0;
    q.push(st);
    while(!q.empty()){
        int tmp_v = q.front();
        q.pop();
        for(int i=head[tmp_v];i!=-1;i=Edge[i].next){
            int next_v = Edge[i].v;
            if(vis[next_v]==-1){
                vis[next_v] = vis[tmp_v]+Edge[i].w;
                if(Max < vis[next_v]){
                    Max = vis[next_v];
                    Max_i = next_v;
                }
                q.push(next_v);
            }
        }
    }
    return flag?Max_i:Max;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        idx = 0;
        memset(head,-1,sizeof head);
        for(int i=1;i<=m;i++){
            int u,v,w;
            char ch;
            cin>>u>>v>>w>>ch;
            add(u,v,w);
            add(v,u,w);
        }      
        int a = bfs(1,1);
        int ans = bfs(a,0);
        cout<<ans<<endl; 
    }
    return 0;

}
/*
Sample Input
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
Sample Output
52
*/