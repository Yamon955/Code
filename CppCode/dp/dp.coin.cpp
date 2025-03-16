//--------------动态规划-------求解用不同面值的硬币凑成总面值为m所需硬币最小数----------------
//样例：2 5 7    27 ===> 5            1 2 5   11===>3
//-----------27=7+5+5+5+5--------------------11=5+5+1-------------------------- 
//时间复杂度O(m*n) 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>
using namespace std;
int n=3;//the number of coins
int coin(int a[],int m)//数组a中存放的是不同面值的硬币，m表示需要凑成的总数 
{
	int f[m+1];
	int i,j;
	f[0]=0;//初始条件 
	for(i=1;i<=m;i++){
		f[i]=INT_MAX;//INT_MAX表示正无穷大，f[i]=正无穷表示拼不出来总面值i;例如f[-1]=f[-2]=....=正无穷 
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












