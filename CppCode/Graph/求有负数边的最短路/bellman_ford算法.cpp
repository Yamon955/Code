#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/*
当题目存在边权为负数的情况时考虑两种算法-->Bellman_ford算法和SPFA算法
Bellman_ford算法--->O(nm)
    只有题目规定了只能走k步的时候才能用Bellman_ford算法
Bellman_ford算法两个特色：
    1.不要存储图，只要开一个结构体把所有边存起来就行
    2.要有一个备份dist数组的backups数组
流程：
for(k次)：//一共走k步
    1.把dist数组备份
    2.遍历所有边{
        if(dist[b]>dist[a]+w) dist[b]=backups[a]+w;
    }
*/
struct N{
    int a,b,c;
}Ns[10010];
int n,m,k;
int dist[550],bak[500];
void bellman_ford()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<k;i++){ //k步
        memcpy(bak,dist,sizeof(dist));//将数组dist备份到bak中
        for(int j=0;j<m;j++){
            int a=Ns[j].a,b=Ns[j].b,c=Ns[j].c;
            if(dist[b]>bak[a]+c) dist[b]=bak[a]+c;//更新
        }
    }
    if(dist[n]>0x3f3f3f3f/2) //可能存在负权边，比较的值要做出改变
        cout<<"impossible";
    else cout<<dist[n];

}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Ns[i]={a,b,c};
    }
    bellman_ford();
    return 0;
}
/*
AC wing---853. 有边数限制的最短路
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。

注意：图中可能 存在负权回路 。

输入格式
第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。

如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500,
1≤m≤10000,
任意边长的绝对值不超过 10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/