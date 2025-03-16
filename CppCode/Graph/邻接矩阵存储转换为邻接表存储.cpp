#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//���������ֵ���������� 
#define Maxvex 30//ͼ����󶥵��� 
///////////////////////////////////////////////////////////////////////
typedef char VertexType[4]; //����VertexTypeΪ�ַ�����
typedef struct vertex{
	int adjvex;  //������
	VertexType data;//������Ϣ 
}VType;
typedef struct graph{
	int n,e;//nΪʵ�ʶ�������eΪʵ�ʱ���
	VType vexs[Maxvex];//���㼯�� 
	int edges[Maxvex][Maxvex]; //�ߵļ��� 
}MGraph; //ͼ���ڽӾ������� 
void CreateGraph(MGraph &g,int a[][Maxvex],int n,int e)
{
	g.n=n;g.e=e;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g.edges[i][j]=a[i][j];
}
///////////////////////////////////////////////////////////////////////////
typedef struct edgenode{
	int adjvex;//���ڵ����
	int weight;//Ȩֵ
	struct edgenode *nextarc;//��һ���ߵĶ��� 
}ArcNode;  //ÿ�����㽨���ĵ������б߽�������
typedef struct vexnode{
	VertexType data;//��Ŷ�����Ϣ
	ArcNode *firstarc;//ָ���һ���߽�� 
}VHeadNode; //�������ͷ�������
typedef struct{
	int n,e;//nΪʵ�ʶ�������eΪʵ�ʱ���
	VHeadNode adjlist[Maxvex];//�������ͷ������� 
}ALGraph;   //ͼ���ڽӱ����� 
void CreateGraph(ALGraph *&g,int a[][Maxvex],int n,int e)
{
	ArcNode *p;
	g=(ALGraph *)malloc(sizeof(ALGraph));
	g->n=n;g->e=e;
	for(int i=0;i<g->n;i++) g->adjlist[i].firstarc=NULL;//�ڽӱ�������ͷ����ָ�����ÿ� 
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
void MatToAdj(ALGraph *&G,MGraph &g)//���ڽӾ���gת�����ڽӱ�G
{
	G=(ALGraph *)malloc(sizeof(ALGraph));
	G->n=g.n;G->e=g.e;
	for(int i=0;i<g.n;i++) G->adjlist[i].firstarc=NULL;
	ArcNode *p;
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			if(g.edges[i][j]!=0&&g.edges[i][j]<INF){
				p=(ArcNode *)malloc(sizeof(ArcNode));//�������p 
				p->adjvex=j;
				p->weight=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;//ͷ�巨����p 
				G->adjlist[i].firstarc=p;
			}
}
int Degree1(ALGraph *g,int v)//������ͼg�ж���Ķ���
{
	if(v<0||v>=g->n) return -1;//�����Ŵ��� 
	int d=0;
	ArcNode *p=g->adjlist[v].firstarc ;
	while(p!=NULL){     //ͳ��v����ĵ������н��ĸ�����������v�Ķ� 
		d++;
		p=p->nextarc;
	}
	return d;
 } 
int Degree2(ALGraph *g,int v)//������ͼg�ж���Ķ���
{
	if(v<0||v>=g->n) return -1;//�����Ŵ���
	int d1=0,d2=0;//d1Ϊ���ȣ�d2Ϊ���
	ArcNode *p=g->adjlist[v].firstarc ;
	while(p!=NULL){     //ͳ��v����ĵ������н��ĸ�����������v�ĳ��� 
		d1++;
		p=p->nextarc;
	}
	for(int i=0;i<g->n;i++){  //ͳ�Ʊ߽����adjvexΪv�ĸ�����������v����� 
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
	MGraph g;
	ALGraph *G;
	int n,e;
	cout<<"���붥����:";
	cin>>n;
	cout<<"�������:";
	cin>>e; 
	cout<<"����ͼ��Ӧ���ڽӾ���:";
	int a[Maxvex][Maxvex];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>a[i][j];
	CreateGraph(g,a,n,e);//����ͼ���ڽӾ���洢 
	MatToAdj(G,g);//���ڽӾ���洢ת��Ϊ�ڽӱ�洢 
	cout<<Degree1(G,0);//���ù����ڽӱ��󶥵�����ĺ��� 
	return 0;
}
