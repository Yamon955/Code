#include<iostream>
#include<cstdio>
using namespace std;
#define MAXSIZE 12500//�������Ԫ�������ֵΪ12500
typedef struct{
	int i,j;//�÷���Ԫ�����±�����±�
	int e;//�÷���Ԫ��ֵ 
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];//data[0]δʹ��
	int row,col,tu;//���������������������Ԫ���� 
}TSMatrix;
int f[100][100],y[100][100];
int TransposeMatrix(TSMatrix M,TSMatrix &T)
{
	T.row=M.col;
	T.col=M.row;
	T.tu=M.tu;
	int q=1;
	if(T.tu){
		for(int n=1;n<=M.col;n++)
		for(int p=1;p<=M.tu;p++){
			if(n==M.data[p].j){
				T.data[q].i=M.data[p].j;
				T.data[q].j=M.data[p].i;
				T.data[q].e=M.data[p].e;
				q++;
			}
		}
	}
	return 1;	
 } 
int main()
{
	TSMatrix M,T;
	M.row=6;
	M.col=7;
	cout<<"����ϡ�����M����Ԫ�ĸ���:";
	cin>>M.tu; 
    for(int m=1;m<=M.tu;m++){
    	cin>>M.data[m].i>>M.data[m].j>>M.data[m].e;//������Ԫ�� 
	}
	cout<<"ϡ�����MΪ:"<<endl;
	for(int m=1;m<=M.row;m++){
		for(int n=1;n<=M.col;n++){
			for(int x=1;x<=M.tu;x++){
				if(m==M.data[x].i && n==M.data[x].j){
					f[m][n]=M.data[x].e;
					break;
				} 
			}
			printf("%d\t",f[m][n]);
		}
		cout<<endl;
	}
	TransposeMatrix(M,T);
	cout<<"ϡ�����M��ת�þ���TΪ:"<<endl;
	for(int m=1;m<=T.row;m++){
		for(int n=1;n<=T.col;n++){
			for(int x=1;x<=T.tu;x++){
				if(m==T.data[x].i&&n==T.data[x].j){
					y[m][n]=T.data[x].e;
					break;
				} 
			}
			printf("%d\t",y[m][n]);
		}
		cout<<endl;
	}
	/*T.row=M.col;//������ת�ú�����ת�þ��� 
	T.col=M.row;
	T.tu=M.tu;
	for(int m=1;m<=M.tu;m++){
		T.data[m].i=M.data[m].j;
		T.data[m].j=M.data[m].i;
		T.data[m].e=M.data[m].e;
	}
	cout<<"ϡ�����M��ת�þ���TΪ:"<<endl;
	for(int m=1;m<=T.row;m++){
		for(int n=1;n<=T.col;n++){
			for(int x=1;x<=T.tu;x++){
				if(m==T.data[x].i && n==T.data[x].j){
					y[m][n]=T.data[x].e;
					break;
				} 
			}
			printf("%d\t",y[m][n]);
		}
		cout<<endl;
	}*/
	return 0;	
 }
/*
8 
1 2 12
1 3 9
3 1 -3
3 6 14
4 3 24
5 2 18
6 1 15
6 4 -7
ϡ�����MΪ:
0       12      9       0       0       0       0
0       0       0       0       0       0       0
-3      0       0       0       0       14      0
0       0       24      0       0       0       0
0       18      0       0       0       0       0
15      0       0       -7      0       0       0
ϡ�����M��ת�þ���TΪ:
0       0       -3      0       0       15
12      0       0       0       18      0
9       0       0       24      0       0
0       0       0       0       0       -7
0       0       0       0       0       0
0       0       14      0       0       0
0       0       0       0       0       0
*/ 
