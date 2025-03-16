#include<iostream>
#include<cstdio>
using namespace std;
int f[1000],b[1000],n;
void Copy(int c[],int d[],int l,int r)
{
	for(int i=l;i<=r;i++) c[i]=d[i];
}
void Merge(int c[],int d[],int l,int m,int r)//合并c[l:m]和c[m+1:r]到d[l:m] 
{
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r){
		if(c[i]<=c[j])	d[k++]=c[i++];
		else            d[k++]=c[j++];
		
	}
	if(i>m)
			for(int h=j;h<=r;h++) d[k++]=c[h];	
	else 
			for(int h=i;h<=m;h++) d[k++]=c[h];
	//for(int i=l;i<=r;i++) c[i]=d[i];//加上此步后可省略Copy函数 
}
void MergeSort(int a[],int left,int right)
{
	if(left<right){
		int mid=(left+right)/2;
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,b,left,mid,right);
		Copy(a,b,left,right);
	}
	
	
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>f[i];
	MergeSort(f,0,n-1);
	for(int i=0;i<n;i++) cout<<f[i]<<" ";
	return 0;
}
