#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<malloc.h>
#include<queue>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int map[100][100];
int best[100];
queue<int> q;
int main()
{
    cin>>n>>m;
    memset(map,0x3f,sizeof(map));
    memset(best,0x3f,sizeof(best));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v] = map[v][u] = w;
    }
    int k = 1;
    q.push(1);
    while(!q.empty()){
        int fir = q.front();
        q.pop();
        for(int i=2;i<=n;i++){
            if(map[fir][i]<INF){
                best[i] = map[fir][i];
                q.push(i);
                for(int i=2;i<=n;i++){
                    
                }
            }
        }
    }
}
