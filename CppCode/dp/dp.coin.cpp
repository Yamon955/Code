//--------------��̬�滮-------����ò�ͬ��ֵ��Ӳ�Ҵճ�����ֵΪm����Ӳ����С��----------------
//������2 5 7    27 ===> 5            1 2 5   11===>3
//-----------27=7+5+5+5+5--------------------11=5+5+1-------------------------- 
//ʱ�临�Ӷ�O(m*n) 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>
using namespace std;
int n=3;//the number of coins
int coin(int a[],int m)//����a�д�ŵ��ǲ�ͬ��ֵ��Ӳ�ң�m��ʾ��Ҫ�ճɵ����� 
{
	int f[m+1];
	int i,j;
	f[0]=0;//��ʼ���� 
	for(i=1;i<=m;i++){
		f[i]=INT_MAX;//INT_MAX��ʾ�������f[i]=�������ʾƴ����������ֵi;����f[-1]=f[-2]=....=������ 
		for(j=0;j<n;j++){
			if(i>=a[j]&&f[i-a[j]]!=INT_MAX)
			  f[i]=min(f[i-a[j]]+1,f[i]);
		}
		
	}
	if(f[m]==INT_MAX) f[m]=-1;
	return f[m];
}
int main()
{
	int a[n],i,m;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	cout<<coin(a,m);
	return 0;
}












