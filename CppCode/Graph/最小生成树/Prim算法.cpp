#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
/*
Prim算法---O(n^2)----------->稠密图
dist[N]----每个点到当前集合的最短距离
    for(int i=0;i<n;i++){
        找到集合外所有点中dist最小的点t
        st[t]=true;
        用t来更新其他点到集合的dist
    }
*/
int g[1000][1000],dist[1000],n,m,res;//res用来保存最终的最小生成树的所有权值的和
int st[1000];
void Prim()
{
    for(int i=0;i<n;i++){//第一次循环仅仅是为了找一个点
        int t=-1;//初始选择一个树外的点
        for(int j=1;j<=n;j++){ //每个节点一次判断
            if(st[j]==0&&(dist[t]>dist[j]||t==-1)) t=j;//如果没有在树中，且到树的距离最短，则选择该点
        }
        st[t]=1;
        if(i) res+=dist[t];//第一次循环仅仅是为了找一个点,不用加进去
        if(i&&dist[t]==INF) { //判断连通性，看能否生产最小生成树
            cout<<"impossible";
            return ;
        }
        for(int j=1;j<=n;j++)
            if(dist[j]>g[t][j]) dist[j]=g[t][j];//更新
    }
    cout<<res<<endl;
}
int main()
{
    cin>>n>>m;
    memset(dist,0x3f,sizeof(dist));
    memset(g,0x3f,sizeof(g));
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(g[a][b]>c) g[a][b]=g[b][a]=c;//无向图,可能输入重边，保存最小的就好
    }
    Prim();
    return 0;
}
/*
AC wing---858
给定一个  n  个点  m  条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图  G=(V,E) ，其中  V  表示图中点的集合， E  表示图中边的集合， n=|V| ， m=|E| 。

由  V  中的全部  n  个顶点和  E  中  n−1  条边构成的无向连通子图被称为  G  的一棵生成树，其中边的权值之和最小的生成树被称为无向图  G  的最小生成树。

输入格式
第一行包含两个整数  n  和  m 。

接下来  m  行，每行包含三个整数  u,v,w ，表示点  u  和点  v  之间存在一条权值为  w  的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500 ,
1≤m≤105 ,
图中涉及边的边权的绝对值均不超过  10000 。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/