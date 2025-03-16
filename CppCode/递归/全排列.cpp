#include<iostream>
#include<cstdio>
using namespace std;
int list[100],n;
void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
void Perm(int list[],int k,int m)
{
	if(k==m){
		for(int i=0;i<=m;i++) cout<<list[i]<<" ";
		cout<<endl;
	}
	else {
		for(int i=k;i<=m;i++){
			swap(list[k],list[i]);
			Perm(list,k+1,m);
			swap(list[k],list[i]);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>list[i];
	Perm(list,0,n-1);
	return 0;
 } 
