#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//���������ֵ���������� 
#define Maxvex 30//ͼ����󶥵��� 
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
	MGraph g;
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
	cout<<Degree2(g,0);
	return 0;
}
