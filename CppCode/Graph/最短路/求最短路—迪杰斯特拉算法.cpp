#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//用整型最大值代表正无穷 
#define Maxvex 30//图中最大顶点数 
typedef struct {
    int adjvex;  //顶点编号
    char data;//顶点信息 
}VType;   //自定义顶点类型 
typedef struct{
    char first;  //边的起点 
    char last;  //边的终点 
    int weight; //边的权值，即路径长度 
}Edge;//自定义边的类型 
typedef struct{
    int n,e;//n为实际顶点数，e为实际边数
    int edges[Maxvex][Maxvex]; //边的集合 
}MGraph; //图的邻接矩阵类型 
void CreateGraph(MGraph &g,int a[][Maxvex],int n,int e)//创建图 
{
    g.n=n;g.e=e;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g.edges[i][j]=a[i][j];
}

void Dijkstra(MGraph g,int v,int v2,int shortpath_[])//迪杰斯特拉算法求最短路 
{
    int dist[Maxvex];//存储顶点v到每个顶点的最短路径长度 
    int path[Maxvex];// 
    int s[Maxvex];
    int mindis,i,j,u=0;
    for(i=0;i<g.n;i++){
        dist[i]=g.edges[v][i];//距离初始化 
        s[i]=0;   //s[]置空 
        if(g.edges[v][i]<INF) //路径初始化
                path[i]=v;       //v->有边时，置i前一顶点为v 
        else         path[i]=-1; //v->无边时，置i前一顶点为-1 
    }
    s[v]=1;   //顶点编号v放入s中 
    for(i=0;i<g.n-1;i++){  //循环向s中添加n-1个顶点 
        mindis=INF;    //mindis置最小长度初值 
        for(j=0;j<g.n;j++)  //选取不在s中且有最小距离的顶点u 
            if(s[j]==0 && dist[j]<mindis){
                u=j;
                mindis=dist[j];
            }
            s[u]=1;   //顶点u加入s中 
            for(j=0;j<g.n;j++)  //修改不在s中顶点的距离 
                if(s[j]==0)
                    if(g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j]){
                        dist[j]=dist[u]+g.edges[u][j];
                        path[j]=u;
                    }
    }
    cout<<dist[v2]<<endl;//输出从v到终点v2的最短路路径长度 
    shortpath_[0]=v2;  //数组shortpath[]中存储从v到v2最短路径上的顶点编号的逆序 
    int num=1;
    while(v2!=v){
        shortpath_[num++]=path[v2];
        v2=path[v2];
    }
} 
void show_ShortestPath(int n,int m)//输出最短路径 
{
    VType V[10];
    for(int i=0;i<n;i++){
        V[i].adjvex=i; 
        cin>>V[i].data;//输入顶点的名字，即A B C D 
    }
    Edge E[10];
    int a[Maxvex][Maxvex];//定义邻接矩阵 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) a[i][j]=INF; //初始化邻接矩阵 
    for(int i=0;i<m;i++){
        cin>>E[i].first>>E[i].last>>E[i].weight;
        int x,y;
        for(int j=0;j<n;j++){
            if(V[j].data==E[i].first) x=V[j].adjvex;
            if(V[j].data==E[i].last)  y=V[j].adjvex;
        }
        a[x][y]=E[i].weight;  //将x->y边的长度放入邻接矩阵中    
    }
    char v1,v2;//定义起点，终点 
    cin>>v1>>v2;// 输入起点，终点的名字 
    int v1_num,v2_num;//起点，终点的编号  
    for(int i=0;i<n;i++){
        if(V[i].data==v1) v1_num=V[i].adjvex;
        if(V[i].data==v2) v2_num=V[i].adjvex;
    }
    MGraph G;
    CreateGraph(G,a,n,m);
    int shortpath[Maxvex];//数组shortpath[]中存储从v到v2最短路径上的顶点编号的逆序
    Dijkstra(G,v1_num,v2_num,shortpath);
    int num;
    for(int i=0;i<Maxvex;i++) 
        if(shortpath[i]==v1_num) {
         num=i; break;
        }
    for(int i=num;i>=0;i--){
        for(int j=0;j<n;j++){
            if(shortpath[i]==V[j].adjvex) cout<<V[j].data;//输出最短路 
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(!(n==0&&m==0)){
        show_ShortestPath(n,m);
        cin>>n>>m;
    }
    return 0;
}
/* 
3 3
A B C
A B 1
B C 1
C A 3
A C
6 8
A B C D E F
A F 100
A E 30
A C 10
B C 5
C D 50
D E 20
E F 60
D F 10
A F
0 0
COUT<<
2
A B C
70
A C D F
*/
