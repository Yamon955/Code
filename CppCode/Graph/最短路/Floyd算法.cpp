#include<iostream>
#include<cstdio>
using namespace std;
/*
参考HDU1385
多源最短路--Floyd算法-----O(n^3)
g[n][n]两个点之间的最短距离，兼职存储初始的图
流程：
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j])
*/
/*
输出最短路径
这里我们要输入两个结点v1 v2
最后输出的就是v1到v2的最短路径
仔细想想我们的path[v1][v2]储存的是v1 v2的第一个中转节点z的信息
输出z后，path[z][v2]储存的是z到v2的第一个中转结点
一个一个输出这些中转结点
以此类推，直到z为v2的时候，这就是v1到v2的最短路径
注意：要对path[][]初始化为path[i][j] = j  (很重要)
*/
#define INF 0x3f3f3f3f
int g[210][210];//有向图
int path[210][210];//保存最短路径
int n,m,k;
void Floyd()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) path[i][j] = j; //初始化path数组（别忘了）
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                //g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j] = g[i][k]+g[k][j];
                    path[i][j] = path[i][k];  //i-->j 的中转结点 k
                }
                // else if(g[i][j] == g[i][k]+g[k][j]){
                //     path[i][j] = min(path[i][j],path[i][k]);//当最短路径长度相等时，优先选择字典序最小的
                // }
}
void print(int u,int v)
{
    while(u != path[u][v]){
        cout<<u<<" ";
        u = path[u][v];
    }
    cout<<u<<endl;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) 
            if(i==j) g[i][j]=0;//注意
            else g[i][j]=INF;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);//可能输入重边，保存最小的就好
    }
    Floyd();
    while(k--){
        int a,b;
        cin>>a>>b;
        if(g[a][b]>INF/2) //边权可能为负
            cout<<"impossible"<<endl;
        else{  
            cout<<g[a][b]<<endl;
            cout<<"最短路径为:";
            print(a,b);
        }
    }
    return 0;
}
/*
给定一个  n  个点  m  条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定  k  个询问，每个询问包含两个整数  x  和  y ，表示查询从点  x  到点  y  的最短距离，如果路径不存在，则输出 impossible。

数据保证图中不存在负权回路。

输入格式
第一行包含三个整数  n,m,k 。

接下来  m  行，每行包含三个整数  x,y,z ，表示存在一条从点  x  到点  y  的有向边，边长为  z 。

接下来  k  行，每行包含两个整数  x,y ，表示询问点  x  到点  y  的最短距离。

输出格式
共  k  行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。

数据范围
1≤n≤200 ,
1≤k≤n2 
1≤m≤20000 ,
图中涉及边长绝对值均不超过  10000 。

输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
输出样例：
impossible
1
*/