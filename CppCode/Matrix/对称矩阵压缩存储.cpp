#include<iostream>
#include<stdio.h>
using namespace std;
int f[5][5];
int main()
{
	int a[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(i>j) f[i][j]=a[(i-1)*i/2+j-1];
			else    f[i][j]=a[(j-1)*j/2+i-1];
		printf("%d\t",f[i][j]); 
		}
		cout<<endl;
	}
	
	return 0;
 } 
