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
	int cpot[100],num[100];//copt[col]��ʾM�е�col�еĵ�һ������Ԫ��T.data�е��ʵ�λ�ü�T.data[copt[col]]
	                       //num[col]��ʾM�е�col���з���Ԫ���� 
	for(int m=1;m<=M.tu;m++) num[m]=0;//��ʼ��num[]�� 
	if(T.tu){
		for(int m=1;m<=M.col;m++)  num[m]=0;//��ʼ��num[]�� 
		for(int t=1;t<=M.tu;t++) ++num[M.data[t].j]; //��M��ÿһ�з���Ԫ����
		cpot[1]=1;
		for(int t=2;t<=M.col;t++) cpot[t]=cpot[t-1]+num[t-1];
		for(int m=1;m<=M.tu;m++){
			int p=M.data[m].j;
			int q=cpot[p];
			T.data[q].i=M.data[m].j;
			T.data[q].j=M.data[m].i;
			T.data[q].e=M.data[m].e;
			++cpot[p];	
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
