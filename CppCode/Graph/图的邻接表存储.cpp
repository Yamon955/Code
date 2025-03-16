#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//用整型最大值代表正无穷 
#define Maxvex 30//图中最大顶点数 
typedef char VertexType[10];//VertexType为字符串类型
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
				p->nextarc=g->adjlist[i].firstarc;//头插法插入p 
				g->adjlist[i].firstarc=p;
			}
 } 
void DestroyGraph(ALGraph *&g)//销毁图 
{
	int i;
	ArcNode *p,*pre;
	for(int i=0;i<g->n;i++){      //遍历所有头结点 
		pre=g->adjlist[i].firstarc;
		if(pre!=NULL){
			p=pre->nextarc;
			while(p!=NULL){//释放adjlist[i]的所有边结点 
				free(pre);
				pre=p;
				p=p->nextarc;
			}
			free(pre);
		}
	}
	free(g);    //释放g所指的头结点数组的内存空间 
}
int Degree1(ALGraph *g,int v)//求无向图g中顶点的度数
{
	if(v<0||v>=g->n) return -1;//顶点编号错误 
	int d=0;
	ArcNode *p=g->adjlist[v].firstarc ;
	while(p!=NULL){     //统计v顶点的单链表中结点的个数，即顶点v的度 
		d++;
		p=p->nextarc;
	}
	return d;
 } 
int Degree2(ALGraph *g,int v)//求有向图g中顶点的度数
{
	if(v<0||v>=g->n) return -1;//顶点编号错误
	int d1=0,d2=0;//d1为出度，d2为入度
	ArcNode *p=g->adjlist[v].firstarc ;
	while(p!=NULL){     //统计v顶点的单链表中结点的个数，即顶点v的出度 
		d1++;
		p=p->nextarc;
	}
	for(int i=0;i<g->n;i++){  //统计边结点中adjvex为v的个数，即顶点v的入度 
		ArcNode *q=g->adjlist[i].firstarc;
		while(q!=NULL){
			if(q->adjvex==v) d2++;
			q=q->nextarc;
		}
	}
	return d1+d2;
 } 
int main()
{
	ALGraph *g;
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
	cout<<Degree1(g,0);
	return 0;
}
