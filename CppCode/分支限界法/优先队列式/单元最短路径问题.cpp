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
int map[100][100],dist[100];
class HeapNode{
    public:
        int no;
        int len;
        HeapNode(){};
        HeapNode(int n,int l){no = n,len = l;}
        bool operator < (const HeapNode& node)const{
            return len < node.len; //数值越小优先级越高
        }
};
priority_queue<HeapNode> q;
int main()
{
    cin>>n>>m;
    memset(map,0x3f,sizeof(map));
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v] = map[v][u] = w;
    }
    HeapNode st(1,0);
    q.push(st);
    while(!q.empty()){
        HeapNode fir = q.top();
        q.pop();
        for(int i=2;i<=n;i++){
            if(map[fir.no][i]<INF && fir.len+map[fir.no][i]<dist[i]){  //剪枝
                                                                       //扩展节点，并且判断当前点到1号点的距离能否更新
                dist[i] = fir.len+map[fir.no][i];
                HeapNode tmp(i,dist[i]);
                q.push(tmp);
            }
        }
    }
    for(int i=2;i<=n;i++) cout<<dist[i]<<endl;
    return 0;
}
/*
5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
-->10 50 30 60
*/