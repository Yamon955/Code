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
int bestw = INF;
int bestv[100];
typedef struct Node{
    int no;  //当前城市标号
    int w;  //记录当前的走过的路径长度
    int v[100];//按顺序标记已经走过的城市 v[1] = 1表示第一个到达的城市是 1号城市 ，v[3] = 2表示第2个到达的城市是 3号城市
    int cnt; //已经走过的城市数,即当前节点在子集树中所处的层次
}Node;
queue<Node>q;
int main()
{
    cin>>n>>m;
    memset(map,0x3f,sizeof(map));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v] = map[v][u] = w;
    }
    Node st; //初始化第一个节点
    st.no = 1; 
    st.w = 0;
    st.cnt = 1;
    for(int i=1;i<=n;i++) st.v[i] = 0; //全部置为 0
    st.v[1] = 1; //起点为1号城市，故第一个到达的城市是 1 号城市，故 v[1]=1
    q.push(st); //入队
    while(!q.empty()){
        Node firNode = q.front(); //保存首节点
        q.pop(); //出队
        if(firNode.cnt==n-1){  //当前已经走了 n-1 个城市后，后面就只剩下一个城市未走，最后再返回到 1 号城市
            for(int i=1;i<=n;i++){
                if(firNode.v[i]==0){ //找出最后那个城市还没有走
                    if(map[firNode.no][i]<INF&&map[i][1]<INF){  //如果从当前所在的城市可以走到最后的未走的城市并且从这个最后未走的城市可以返回到起点城市 1
                        firNode.w = firNode.w + map[firNode.no][i] + map[i][1];
                        if(firNode.w<bestw) {  //更新 bestw
                            bestw = firNode.w;
                            for(int j=1;j<=n-1;j++) bestv[firNode.v[j]] = firNode.v[j]; //保存最优路径
                            bestv[i] = n; //表示这个未走的城市是第  n 个到达的城市
                            bestv[n+1] = 1;  //最后返回起点城市 1
                        }   
                    }
                    break;
                }
            }
        }
        else
        for(int i=2;i<=n;i++){
            if(map[firNode.no][i]<INF&&firNode.v[i]==0){
                // Node tmp;
                // tmp.no = i;
                // tmp.cnt = firNode.cnt+1;
                // tmp.w = firNode.w + map[firNode.no][i];
                // for(int j=1;j<=n;j++) tmp.v[j] = firNode.v[j];
                // tmp.v[i] = tmp.cnt;
                Node tmp = firNode;
                tmp.no = i;  //更新当前所在节点
                tmp.w = firNode.w + map[firNode.no][i];
                tmp.v[i] = firNode.cnt+1;
                tmp.cnt = firNode.cnt+1; //所走城市数加 1
                q.push(tmp);
            }
        }
    }
    if(bestw==INF){
        cout<<"-1";
        return 0;
    }
    cout<<bestw<<endl;
    for(int i=1;i<=n+1;i++) cout<<bestv[i]<<" ";
    return 0;
}
/*
Simple input：
3 3
1 2 2
1 3 4
2 3 10
Simple output：
16
1 2 3 1
*/