#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//用整型最大值代表正无穷 
#define Maxvex 30//图中最大顶点数 
///////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////
typedef struct edgenode{
	int adjvex;//相邻点序号
	int weight;//权值
	struct edgenode *nextarc;//下一条边的顶点 
}ArcNode;  //每个顶点建立的单链表中边结点的类型
typedef struct vexnode{
	VertexType data;//存放顶点信息
	ArcNode *firstarc;//指向第一条边结点 
}VHeadNode; //单链表的头结点类型
typedef struct{
	int n,e;//n为实际顶点数，e为实际边数
	VHeadNode adjlist[Maxvex];//单链表的头结点数组 
}ALGraph;   //图的邻接表类型 
void CreateGraph(ALGraph *&g,int a[][Maxvex],int n,int e)
{
	ArcNode *p;
	g=(ALGraph *)malloc(sizeof(ALGraph));
	g->n=n;g->e=e;
	for(int i=0;i<g->n;i++) g->adjlist[i].firstarc=NULL;//邻接表中所有头结点的指针域置空 
	for(int i=0;i<g->n;i++)
		for(int j=0;j<g->n;j++)
			if(a[i][j]>0&&a[i][j]<INF){
				p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=a[i][j];
				p->nextarc=g->adjlist[i].firstarc;
				g->adjlist[i].firstarc=p;
			}
 } 
void AdjToMat(ALGraph *G,MGraph &g)//将邻接表G转换成邻接矩阵g
{
	g.n=G->n;g.e=G->e;   //置顶点数和边数
	for(int i=0;i<G->n;i++)
		for(int j=0;j<G->n;j++){
			if(i==j) g.edges[i][j]=0;//对角线置零 
			else     g.edges[i][j]=INF;
		}
	ArcNode *p;
	for(int i=0;i<G->n;i++){
		p=G->adjlist[i].firstarc;
		while(p!=NULL){
			g.edges[i][p->adjvex]=p->weight;
			p=p->nextarc;
		}
	}
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
	ALGraph *G;//图的邻接表存储 
	MGraph g; //图的邻接矩阵存储 
	int n,e;
	cout<<"输入顶点数:";
	cin>>n;
	cout<<"输入边数:";
	cin>>e; 
	cout<<"输入图对应的邻接矩阵:";
	int a[Maxvex][Maxvex];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>a[i][j];
	CreateGraph(G,a,n,e);//创造图邻接表存储 
	AdjToMat(G,g);    //邻接表存储转化为邻接矩阵存储 
	cout<<Degree1(g,0);//调用关于邻接矩阵求顶点度数的函数 
	return 0;
}
