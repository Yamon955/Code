//----------��̬�滮------�����m��n�б���д�(0,0)��(m-1,n-1)�ж����ֲ�ͬ�ķ�ʽ��ÿ��ֻ�����һ������ߣ�-----
//����   1  3 ===> 1
//ʱ�临�Ӷ�O(m*n)  �ռ临�Ӷ�O(m*n) 

#include<iostream>
using namespace std;
int uniquePaths(int m,int n)
{
	int f[m][n];//f[i][j] ��ʾ��(0,0)��(i,j)�Ĳ�ͬ��ʽ���� 
	int i,j;
	for(j=0;j<n;j++){//�������� 
		for(i=0;i<m;i++){//��������   ����˳�򣺴����ң����ϵ��� 
			if(i==0||j==0){
				f[i][j]=1;//��ʼ���� 
			}
			else 
				f[i][j]=f[i-1][j]+f[i][j-1];//���һ��һ�������һ����� �����ܷ�ʽ��=����(i-1,j)�ķ�ʽ��+����(i,j-1)�ķ�ʽ�� 
		}
	}
	return f[m-1][n-1];
 }
 
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<uniquePaths(m,n);
	return 0;
}
