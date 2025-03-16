#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//用整型最大值代表正无穷 
#define Maxvex 30//图中最大顶点数 
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

void Dijkstra(MGraph g,int v)//迪杰斯特拉算法求最短路 
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
	int Max=0;
	int Max_i=-1; 
	for(i=1;i<g.n;i++){
		cout<<dist[i]<<endl;
		if(dist[i]!=INF&&dist[i]>Max){//距离顶点v的最短路径长度最大的一个顶点i
			Max=dist[i]; 
			Max_i=i;
	    }
	}
	   
		
	cout<<"第"<<Max_i<<"个顶点是所求顶点";
} 
int main()
{
	int n,e;
	cin>>n>>e;
	int a[Maxvex][Maxvex];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=INF;
	a[0][2]=1000;
	a[0][4]=30;
	a[0][5]=100;
	a[1][2]=5;
	a[2][3]=50;
	a[3][5]=10;
	a[4][3]=20;
	a[4][5]=60;
	MGraph G;
	CreateGraph(G,a,n,e);	
	Dijkstra(G,0);
	return 0;
}
/*
6 8
inf inf 10 inf 30 inf 100
inf inf 5 inf inf inf
inf inf inf 50 inf inf
inf inf inf inf inf 10
inf inf inf 20 inf 60
inf inf inf inf in
*/


