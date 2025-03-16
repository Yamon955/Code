//题目要求 旅行商从 1 号节点开始出发
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
const int INF = 0x3f3f3f3f;
using namespace std;
int n,m;
int map[100][100];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    cin>>n>>m;
    memset(map,0x3f,sizeof(map));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v] = map[v][u] = w;
    }
    q.push(1);
    while(!q.empty()){
        int no = q.top();
        q.pop();
        for(int i=2;i<=n;i++){
            if(map[no][i]<INF){
                q.push(i);
            }
        }
    }
}