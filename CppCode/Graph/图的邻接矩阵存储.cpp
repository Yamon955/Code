#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//用整型最大值代表正无穷 
#define Maxvex 30//图中最大顶点数 
typedef char VertexType[4]; //定义VertexType为字符类型
typedef struct vertex{
	int adjvex;  //顶点编号
	VertexType data;//顶点信息 
}VType;
typedef struct graph{
	int n,e;//n为实际顶点数，e为实际边数
	VType vexs[Maxvex];//顶点集合 
	int edges[Maxvex][Maxvex]; //边的集合 
}MGraph; //图的邻接矩阵类型 
void CreateGraph(MGraph &g,int a[][Maxvex],int n,int e)
{
	g.n=n;g.e=e;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g.edges[i][j]=a[i][j];
}
int Degree1(MGraph g,int v)//求无向图中顶点的度 
{
	if(v<0||v>=g.n) return -1;//顶点编号错误 
	int d=0;
	for(int i=0;i<g.n;i++) 
		if(g.edges[v][i]>0&&g.edges[v][i]<INF) d++;
		    		//统计第v行既不为0也不为无穷大的边数，即顶点v的度 
	return d;
}
int Degree2(MGraph g,int v)//求有向图中顶点的度
{
	if(v<0||v>=g.n) return -1;//顶点编号错误 
	int d1=0,d2=0;//d1为出度，d2为入度
	for(int i=0;i<g.n;i++)
		if(g.edges[v][i]>0&&g.edges[v][i]<INF) d1++;
					//统计第v行既不为0也不为无穷大的边数，即顶点v的出度
	for(int i=0;i<g.n;i++)
		if(g.edges[i][v]>0&&g.edges[i][v]<INF) d2++;
					//统计第v列既不为0也不为无穷大的边数，即顶点v的入度
	return d1+d2; 
 } 

int main()
{
	MGraph g;
	int n,e;
	cout<<"输入顶点数:";
	cin>>n;
	cout<<"输入边数:";
	cin>>e; 
	cout<<"输入图对应的邻接矩阵:";
	int a[Maxvex][Maxvex];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>a[i][j];
	CreateGraph(g,a,n,e);
	cout<<Degree2(g,0);
	return 0;
}
