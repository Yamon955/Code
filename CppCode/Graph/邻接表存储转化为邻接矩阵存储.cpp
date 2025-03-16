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
void AdjToMat(ALGraph *G,MGraph &g)//���ڽӱ�Gת�����ڽӾ���g
{
	g.n=G->n;g.e=G->e;   //�ö������ͱ���
	for(int i=0;i<G->n;i++)
		for(int j=0;j<G->n;j++){
			if(i==j) g.edges[i][j]=0;//�Խ������� 
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
int Degree1(MGraph g,int v)//������ͼ�ж���Ķ� 
{
	if(v<0||v>=g.n) return -1;//�����Ŵ��� 
	int d=0;
	for(int i=0;i<g.n;i++) 
		if(g.edges[v][i]>0&&g.edges[v][i]<INF) d++;
		    		//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�����ı�����������v�Ķ� 
	return d;
}
int Degree2(MGraph g,int v)//������ͼ�ж���Ķ�
{
	if(v<0||v>=g.n) return -1;//�����Ŵ��� 
	int d1=0,d2=0;//d1Ϊ���ȣ�d2Ϊ���
	for(int i=0;i<g.n;i++)
		if(g.edges[v][i]>0&&g.edges[v][i]<INF) d1++;
					//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�����ı�����������v�ĳ���
	for(int i=0;i<g.n;i++)
		if(g.edges[i][v]>0&&g.edges[i][v]<INF) d2++;
					//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�����ı�����������v�����
	return d1+d2; 
 } 
int main()
{
	ALGraph *G;//ͼ���ڽӱ�洢 
	MGraph g; //ͼ���ڽӾ���洢 
	int n,e;
	cout<<"���붥����:";
	cin>>n;
	cout<<"�������:";
	cin>>e; 
	cout<<"����ͼ��Ӧ���ڽӾ���:";
	int a[Maxvex][Maxvex];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>a[i][j];
	CreateGraph(G,a,n,e);//����ͼ�ڽӱ�洢 
	AdjToMat(G,g);    //�ڽӱ�洢ת��Ϊ�ڽӾ���洢 
	cout<<Degree1(g,0);//���ù����ڽӾ����󶥵�����ĺ��� 
	return 0;
}
