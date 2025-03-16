#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	FILE *fp=fopen("InFile.txt","r+");
	if(fp==NULL){
		cout<<"不能打开";
		exit(1);	
	}
	
	
	 fclose(fp);	
	return 0;
}
