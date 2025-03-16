#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
class V{
    public :
		int Vno;  //������
    	char Vname[100];//��������
};
V v[100];
int V_num,E_num;
int edge[500][500];
int get_Vno(char s[])
{
	int i;
	for(i=1;i<=V_num;i++){
		if(strcmp(v[i].Vname,s)==0) break;
	}
	return i;
}
void print_V()//���������
{
	cout<<"��԰�ڸ���������:"<<endl;
	for(int i=1;i<=V_num;i++) cout<<v[i].Vname<<endl;
}
void print_len()//���������֮���ֱ�Ӿ���
{
	for(int i=1;i<=V_num;i++)
		for(int j=i;j<=V_num;j++) 
			if(edge[i][j]!=1e9)
				cout<<v[i].Vname<<"��"<<v[j].Vname<<"֮���ֱ�Ӿ���Ϊ:"<<edge[i][j]<<endl;
}
void modify()//�޸�������֮���ֱ�Ӿ���
{
	char a[100],b[100];
	int c;
	cout<<"������Ҫ�޸ĵ���������������Լ���Ҫ�޸ĵľ���:"<<endl;
	cin>>a>>b>>c;
	int x=get_Vno(a);
	int y=get_Vno(b);
	if(edge[x][y]==1e9) cout<<a<<"��"<<b<<"֮��û��ֱ�Ӿ��룬���޷��޸�."<<endl;
	else {
		edge[x][y]=c;
		edge[y][x]=c;
	}
	cout<<"�޸ĺ��������֮���ֱ�Ӿ�������:"<<endl;
	print_len();
}
int min_len(int a[],int& num,int v[])//�������е���̾��룬�Լ�����Ӧ���±�
{
	int min=1e9;
	for(int i=1;i<=V_num;i++){
		if(min>a[i] && v[i]==0){
			min=a[i];
			num=i;
		}
	}
	return min;
}
void Dijkstra()
{
	char s[100];
	cout<<"��������Ŀǰ���ڵľ���:"<<endl;
	cin>>s;
	cout<<"��ǰ��������������֮�����̾�������:"<<endl;
	int x=get_Vno(s);//��ǰ������±�
	int vis[100];//�������
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	int Path[100];//Path[i]��ʾ��ž������Ϊx�ľ��㵽�������Ϊi�ľ���֮��ľ���
	for(int i=1;i<=V_num;i++)
		Path[i]=edge[x][i];
	int Short_Path[100];//���������̾���
	Short_Path[x]=0;
	for(int i=1;i<=V_num-1;i++)
	{
		int num;
		int len=min_len(Path,num,vis);//��������м����len����ֱ��Short_Path[num]=min_len(Path,num,vis)��������ԭ��֪
		Short_Path[num]=len;
		vis[num]=1;
		for(int k=1;k<=V_num;k++){
			if(vis[k]==0 && Short_Path[num]+edge[num][k]<Path[k]) 
				Path[k]=Short_Path[num]+edge[num][k];//����Path
		}
	}
	for(int i=1;i<=V_num;i++){
		if(i!=x && Short_Path[i]<1e9) cout<<s<<"��"<<v[i].Vname<<"֮�����̾���Ϊ:"<<Short_Path[i]<<endl;
	}
}
void get_pass(int x,int y,int pass[][500])//�����������������
{
	if(pass[x][y]==0) return ;
	get_pass(x,pass[x][y],pass);
	cout<<v[pass[x][y]].Vname<<" ";
	get_pass(pass[x][y],y,pass);
}
void Floyed()
{
	int f[500][500];
	int pass[500][500];
	for(int i=1;i<=V_num;i++)
		for(int j=1;j<=V_num;j++) {
			f[i][j]=edge[i][j];
			pass[i][j]=0;
		}
	for(int k=1;k<=V_num;k++)
		for(int i=1;i<=V_num;i++)
			for(int j=1;j<=V_num;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					pass[i][j]=k;
				}
			}
	char a[100],b[100];
	cout<<"��������Ҫ��ѯ���·�����������������:"<<endl;
	cin>>a>>b;
	int x=get_Vno(a);
	int y=get_Vno(b);
	cout<<"������֮�����̾���Ϊ:"<<f[x][y]<<endl;
	cout<<"·��Ϊ:"<<v[x].Vname<<" ";
	if(f[x][y]<edge[x][y]) get_pass(x,y,pass);
	cout<<v[y].Vname<<endl;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Interface()
{
	cout<<"************************************************"<<endl;
	cout<<"1.�����԰�ڸ�����."<<endl;
	cout<<"2.�����԰��ÿ��������֮���ֱ��·������."<<endl;
	cout<<"3.�޸�������֮���֮��·��."<<endl;
	cout<<"4.��ѯ������֮������·���Լ�;������."<<endl;
	cout<<"5.��ѯĳ�����㵽�������о���֮�����̾���."<<endl;
	cout<<"6.�˳�."<<endl;
}
void choose()
{
	Interface();
	int key;
	while(1){
		cout<<"******����������******"<<endl;
		cin>>key;
		switch(key){
			case 1:
				print_V();
				break;
			case 2:
				print_len();
				break;
			case 3:
				modify();
				break;
			case 4:
				Floyed();
				break;
			case 5:
				Dijkstra();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"������������.";
				break;
		}
	}
	
}
int main(){
	cin>>V_num>>E_num;
	for(int i=1;i<=V_num;i++){
		cin>>v[i].Vname;
		v[i].Vno=i;
	}
	for(int i=1;i<=V_num;i++)
		for(int j=1;j<=V_num;j++) edge[i][j]=1e9;
	for(int i=1;i<=E_num;i++){
		char a[100],b[100];
		int c;
		cin>>a>>b>>c;
		int x=get_Vno(a);
		int y=get_Vno(b);
		edge[x][y]=c;
		edge[y][x]=c;
	}
	choose();
	return 0;
}
/*
4 5
a
b
c
d
a b 9
a c 2
a d 10
d b 4
c b 1
*/
/*
5 5
a
b
c
d
e
a b 1
b e 2
e d 3
d c 4
c a 100
*/
