#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
class V{
    public :
		int Vno;  //景点编号
    	char Vname[100];//景点名字
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
void print_V()//输出各景点
{
	cout<<"公园内各景点如下:"<<endl;
	for(int i=1;i<=V_num;i++) cout<<v[i].Vname<<endl;
}
void print_len()//输出各景点之间的直接距离
{
	for(int i=1;i<=V_num;i++)
		for(int j=i;j<=V_num;j++) 
			if(edge[i][j]!=1e9)
				cout<<v[i].Vname<<"与"<<v[j].Vname<<"之间的直接距离为:"<<edge[i][j]<<endl;
}
void modify()//修改两景点之间的直接距离
{
	char a[100],b[100];
	int c;
	cout<<"请输入要修改的两个景点的名字以及想要修改的距离:"<<endl;
	cin>>a>>b>>c;
	int x=get_Vno(a);
	int y=get_Vno(b);
	if(edge[x][y]==1e9) cout<<a<<"与"<<b<<"之间没有直接距离，故无法修改."<<endl;
	else {
		edge[x][y]=c;
		edge[y][x]=c;
	}
	cout<<"修改后各个景点之间的直接距离如下:"<<endl;
	print_len();
}
int min_len(int a[],int& num,int v[])//求数组中的最短距离，以及所对应的下标
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
	cout<<"请输入您目前所在的景点:"<<endl;
	cin>>s;
	cout<<"当前景点与其他景点之间的最短距离如下:"<<endl;
	int x=get_Vno(s);//求当前景点的下标
	int vis[100];//标记数组
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	int Path[100];//Path[i]表示存放景点序号为x的景点到景点序号为i的景点之间的距离
	for(int i=1;i<=V_num;i++)
		Path[i]=edge[x][i];
	int Short_Path[100];//用来存放最短距离
	Short_Path[x]=0;
	for(int i=1;i<=V_num-1;i++)
	{
		int num;
		int len=min_len(Path,num,vis);//如果不设中间变量len而是直接Short_Path[num]=min_len(Path,num,vis)，则会出错，原因不知
		Short_Path[num]=len;
		vis[num]=1;
		for(int k=1;k<=V_num;k++){
			if(vis[k]==0 && Short_Path[num]+edge[num][k]<Path[k]) 
				Path[k]=Short_Path[num]+edge[num][k];//更新Path
		}
	}
	for(int i=1;i<=V_num;i++){
		if(i!=x && Short_Path[i]<1e9) cout<<s<<"与"<<v[i].Vname<<"之间的最短距离为:"<<Short_Path[i]<<endl;
	}
}
void get_pass(int x,int y,int pass[][500])//类似于树的中序遍历
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
	cout<<"请输入你要查询最短路径的两个景点的名字:"<<endl;
	cin>>a>>b;
	int x=get_Vno(a);
	int y=get_Vno(b);
	cout<<"两景点之间的最短距离为:"<<f[x][y]<<endl;
	cout<<"路径为:"<<v[x].Vname<<" ";
	if(f[x][y]<edge[x][y]) get_pass(x,y,pass);
	cout<<v[y].Vname<<endl;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Interface()
{
	cout<<"************************************************"<<endl;
	cout<<"1.输出公园内各景点."<<endl;
	cout<<"2.输出公园内每两个景点之间的直接路径距离."<<endl;
	cout<<"3.修改两景点之间的之间路径."<<endl;
	cout<<"4.查询两景点之间的最短路径以及途径景点."<<endl;
	cout<<"5.查询某个景点到其他所有景点之间的最短距离."<<endl;
	cout<<"6.退出."<<endl;
}
void choose()
{
	Interface();
	int key;
	while(1){
		cout<<"******请输入命令******"<<endl;
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
				cout<<"输入命令有误.";
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
