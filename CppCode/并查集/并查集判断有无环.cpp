#include<iostream>
using namespace std;
int vertices;//������ 
int n;//�ߵ����� 
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
		x_fa=fa[x_fa];//һֱ���������Ƚ�� 
	}
	return x_fa;//�������Ƚ�� 
}
bool unionn(int x,int y,int fa[],int height[])
{
	int x_fa=find(x,fa);
	int y_fa=find(y,fa);
	if(x_fa==y_fa){ //x,y����ͬ�����Ƚ�㣬��x,y��ʱͬһ���ߵ�������㣬�ʴ��ڻ� 
		return false;
	}
	else {
		if(height[x_fa]>height[y_fa]) fa[y_fa]=x_fa; //��֤����Ƚ�С�������ӵ���Ƚϴ�����У��������Ա���������ӣ��Ӷ�����һ�������Ĳ��� 
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
	cin>>vertices;//���붥���� 
	cin>>n; //����ߵ����� 
	int fa[vertices];
	int height[vertices];
	int edges[n][2];
	for(int i=0;i<n;i++){
		cin>>edges[i][0]>>edges[i][1];
	}
	init(fa,height);
	for(int i=0;i<n;i++){
		int x=edges[i][0];//��ȡͬһ���ߵ����� 
		int y=edges[i][1];
		if(unionn(x,y,fa,height) == false){
			cout<<"�л�"<<endl;
			exit(0);
		}
	}
	cout<<"û�л�"<<endl;
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
--->�л�

6
5
0 1
1 2
1 3
3 4 
2 5
--->û�л�
*/ 

