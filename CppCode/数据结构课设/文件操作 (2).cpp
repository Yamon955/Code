#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	FILE *fp=fopen("InFile.txt","r+");
	if(fp==NULL){
		cout<<"���ܴ�";
		exit(1);	
	}
	
	
	 fclose(fp);	
	return 0;
}
