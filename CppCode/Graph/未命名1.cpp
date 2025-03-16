#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//���������ֵ���������� 
#define Maxvex 30//ͼ����󶥵��� 
typedef struct{
	int n,e;//nΪʵ�ʶ�������eΪʵ�ʱ���
	int edges[Maxvex][Maxvex]; //�ߵļ��� 
}MGraph; //ͼ���ڽӾ������� 
void CreateGraph(MGraph &g,int a[][Maxvex],int n,int e)//����ͼ 
{
	g.n=n;g.e=e;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g.edges[i][j]=a[i][j];
}

void Dijkstra(MGraph g,int v)//�Ͻ�˹�����㷨�����· 
{
	int dist[Maxvex];//�洢����v��ÿ����������·������ 
	int path[Maxvex];// 
	int s[Maxvex];
	int mindis,i,j,u=0;
	for(i=0;i<g.n;i++){
		dist[i]=g.edges[v][i];//�����ʼ�� 
		s[i]=0;   //s[]�ÿ� 
		if(g.edges[v][i]<INF) //·����ʼ��
				path[i]=v;       //v->�б�ʱ����iǰһ����Ϊv 
		else         path[i]=-1; //v->�ޱ�ʱ����iǰһ����Ϊ-1 
	}
	s[v]=1;   //������v����s�� 
	for(i=0;i<g.n-1;i++){  //ѭ����s�����n-1������ 
		mindis=INF;    //mindis����С���ȳ�ֵ 
		for(j=0;j<g.n;j++)  //ѡȡ����s��������С����Ķ���u 
			if(s[j]==0 && dist[j]<mindis){
				u=j;
				mindis=dist[j];
			}
			s[u]=1;   //����u����s�� 
			for(j=0;j<g.n;j++)  //�޸Ĳ���s�ж���ľ��� 
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
		if(dist[i]!=INF&&dist[i]>Max){//���붥��v�����·����������һ������i
			Max=dist[i]; 
			Max_i=i;
	    }
	}
	   
		
	cout<<"��"<<Max_i<<"�����������󶥵�";
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


