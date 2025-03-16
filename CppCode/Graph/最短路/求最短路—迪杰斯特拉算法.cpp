#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define INF INT_MAX//���������ֵ���������� 
#define Maxvex 30//ͼ����󶥵��� 
typedef struct {
    int adjvex;  //������
    char data;//������Ϣ 
}VType;   //�Զ��嶥������ 
typedef struct{
    char first;  //�ߵ���� 
    char last;  //�ߵ��յ� 
    int weight; //�ߵ�Ȩֵ����·������ 
}Edge;//�Զ���ߵ����� 
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

void Dijkstra(MGraph g,int v,int v2,int shortpath_[])//�Ͻ�˹�����㷨�����· 
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
    cout<<dist[v2]<<endl;//�����v���յ�v2�����··������ 
    shortpath_[0]=v2;  //����shortpath[]�д洢��v��v2���·���ϵĶ����ŵ����� 
    int num=1;
    while(v2!=v){
        shortpath_[num++]=path[v2];
        v2=path[v2];
    }
} 
void show_ShortestPath(int n,int m)//������·�� 
{
    VType V[10];
    for(int i=0;i<n;i++){
        V[i].adjvex=i; 
        cin>>V[i].data;//���붥������֣���A B C D 
    }
    Edge E[10];
    int a[Maxvex][Maxvex];//�����ڽӾ��� 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) a[i][j]=INF; //��ʼ���ڽӾ��� 
    for(int i=0;i<m;i++){
        cin>>E[i].first>>E[i].last>>E[i].weight;
        int x,y;
        for(int j=0;j<n;j++){
            if(V[j].data==E[i].first) x=V[j].adjvex;
            if(V[j].data==E[i].last)  y=V[j].adjvex;
        }
        a[x][y]=E[i].weight;  //��x->y�ߵĳ��ȷ����ڽӾ�����    
    }
    char v1,v2;//������㣬�յ� 
    cin>>v1>>v2;// ������㣬�յ������ 
    int v1_num,v2_num;//��㣬�յ�ı��  
    for(int i=0;i<n;i++){
        if(V[i].data==v1) v1_num=V[i].adjvex;
        if(V[i].data==v2) v2_num=V[i].adjvex;
    }
    MGraph G;
    CreateGraph(G,a,n,m);
    int shortpath[Maxvex];//����shortpath[]�д洢��v��v2���·���ϵĶ����ŵ�����
    Dijkstra(G,v1_num,v2_num,shortpath);
    int num;
    for(int i=0;i<Maxvex;i++) 
        if(shortpath[i]==v1_num) {
         num=i; break;
        }
    for(int i=num;i>=0;i--){
        for(int j=0;j<n;j++){
            if(shortpath[i]==V[j].adjvex) cout<<V[j].data;//������· 
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(!(n==0&&m==0)){
        show_ShortestPath(n,m);
        cin>>n>>m;
    }
    return 0;
}
/* 
3 3
A B C
A B 1
B C 1
C A 3
A C
6 8
A B C D E F
A F 100
A E 30
A C 10
B C 5
C D 50
D E 20
E F 60
D F 10
A F
0 0
COUT<<
2
A B C
70
A C D F
*/
