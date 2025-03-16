#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//���������ֵ���������� 
#define Maxvex 30//ͼ����󶥵��� 
typedef char VertexType[10];//VertexTypeΪ�ַ�������
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
				p->nextarc=g->adjlist[i].firstarc;//ͷ�巨����p 
				g->adjlist[i].firstarc=p;
			}
 } 
void DestroyGraph(ALGraph *&g)//����ͼ 
{
	int i;
	ArcNode *p,*pre;
	for(int i=0;i<g->n;i++){      //��������ͷ��� 
		pre=g->adjlist[i].firstarc;
		if(pre!=NULL){
			p=pre->nextarc;
			while(p!=NULL){//�ͷ�adjlist[i]�����б߽�� 
				free(pre);
				pre=p;
				p=p->nextarc;
			}
			free(pre);
		}
	}
	free(g);    //�ͷ�g��ָ��ͷ���������ڴ�ռ� 
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
	ALGraph *g;
	int n,e;
	cout<<"���붥����:";
	cin>>n;
	cout<<"�������:";
	cin>>e; 
	cout<<"����ͼ��Ӧ���ڽӾ���:";
	int a[Maxvex][Maxvex];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>a[i][j];
	CreateGraph(g,a,n,e);
	cout<<Degree1(g,0);
	return 0;
}
