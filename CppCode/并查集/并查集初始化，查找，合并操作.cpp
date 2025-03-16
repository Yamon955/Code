#include<iostream>
using namespace std;
const int MAXN=100;
int fa[MAXN];//fa[i]=j表示i的父节点位j 
void init(int n)//初始化 
{
	for(int i=1;i<=n;i++){
		fa[i]=i;//i的父节点指向它本身 
	}
}
int find(int i)//查找 
{
	if(fa[i]==i) return i;//递归出口，当到达了祖先位置，就返回祖先 
	else return find(fa[i]);//不断往上查找祖先 
}
int find_pro(int i)//查找     这样就会使同一个祖先的结点都指向这个祖先结点 1->5,2->5,3->5,4->5,即fa[1]=fa[2]=fa[3]=fa[4]=5 
{
	if(fa[i]==i) return i;
	else {
		fa[i]=find_pro(fa[i]);//该步进行了路径压缩，fa[i]=j,j是i的最远的祖先结点 
		return fa[i];//返回父节点 
	}
 }
void unionn(int i,int j)//合并 ---------->产生一条很长的单链 1->2->3->4->5 即fa[1]=2,fa[2]=3,fa[3]=4,fa[4]=5 
{
	int i_fa=find(i);//找到i的祖先 
	int j_fa=find(j);//找到j的祖先 
	fa[i_fa]=j_fa;//i的祖先指向j的祖先 
 } 
 
int main()
{
	int n;
	cin>>n;//5
	init(n);
	unionn(1,2);
	unionn(2,3);
	unionn(3,4);
	unionn(4,5);
	for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
	cout<<endl;
	find_pro(1);
	for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
	return 0;
}

