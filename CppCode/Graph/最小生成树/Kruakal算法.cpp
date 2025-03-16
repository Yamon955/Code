#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/*
Kruskal算法----O(mlogn)----------->稀疏图
    存每一条边，并且根据边的权值大小从小到达排序
    for(int i=0;i<m;i++){
        如果a和b没有连通{
            把a,b连通；
            res+=c;
            cnt++;
        }
    }
    if(cnt!=n-1) 此图不连通(即说明没有生成最小生成树)
    else cout<<res;
*/
int p[100010];
int n,m;
int cnt;//记录连接的边的条数，当cnt==n-1时表示连接完毕了，以及生成最小生成树了
int res;//res用来保存最终的最小生成树的所有权值的和
struct Node{
    int a,b,c;
}Ns[100010];
bool cmp(Node x,Node y)
{
    return x.c<y.c;//将结构体按照c值大小从小到达排序
}
int find(int x)//并查集
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{   
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;//并查集初始化，容易忘记
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Ns[i]={a,b,c};
    }
    sort(Ns,Ns+m,cmp);
    for(int i=0;i<m;i++){
        if(find(Ns[i].a)!=find(Ns[i].b)){ //如果当前两点没有相连
            p[find(Ns[i].a)]=find(Ns[i].b);//连接起来
            res+=Ns[i].c;
            cnt++;
        }
    }
    if(cnt!=n-1) cout<<"impossible";//表示不连通，构不成最小生成树
    else cout<<res;
    return 0; 
}
/*
AC wing----859
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
1≤n≤105 ,
1≤m≤2∗105 ,
图中涉及边的边权的绝对值均不超过  1000 。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
输入：
5 10
3 5 -2
1 5 -6
3 1 -6
4 5 -8
2 1 7
2 1 -4
5 2 -9
2 4 -8
4 1 8
3 5 -2
输出：
-29
*/