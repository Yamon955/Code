#include<iostream>
using namespace std;
int vertices;//顶点数 
int n;//边的条数 
void init(int fa[],int height[])
{
	for(int i=0;i<vertices;i++){ 
		fa[i]=-1;
		height[i]=0;
	} 
}
int find(int x,int fa[])
{
	int x_fa=x;
	while(fa[x_fa]!=-1){
		x_fa=fa[x_fa];//一直向下找祖先结点 
	}
	return x_fa;//返回祖先结点 
}
bool unionn(int x,int y,int fa[],int height[])
{
	int x_fa=find(x,fa);
	int y_fa=find(y,fa);
	if(x_fa==y_fa){ //x,y有相同的祖先结点，而x,y有时同一条边的两个结点，故存在环 
		return false;
	}
	else {
		if(height[x_fa]>height[y_fa]) fa[y_fa]=x_fa; //保证将深度较小的树连接到深度较大的树中，这样可以避免深度增加，从而避免一条单链的产生 
		else if(height[x_fa]<height[y_fa]) fa[x_fa]=y_fa;
		else {
			fa[x_fa]=y_fa;
			height[y_fa]++;
		}
		return true;
	}
}
int main()
{
	cin>>vertices;//输入顶点数 
	cin>>n; //输入边的条数 
	int fa[vertices];
	int height[vertices];
	int edges[n][2];
	for(int i=0;i<n;i++){
		cin>>edges[i][0]>>edges[i][1];
	}
	init(fa,height);
	for(int i=0;i<n;i++){
		int x=edges[i][0];//任取同一条边的两点 
		int y=edges[i][1];
		if(unionn(x,y,fa,height) == false){
			cout<<"有环"<<endl;
			exit(0);
		}
	}
	cout<<"没有环"<<endl;
	return 0;
 } 
/*
6
6
0 1
1 2
1 3
3 4
2 4
2 5
--->有环

6
5
0 1
1 2
1 3
3 4 
2 5
--->没有环
*/ 

