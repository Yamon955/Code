#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main()
{
	FILE *fp = fopen("InFile.txt","r");
	if(fp==NULL){
		printf("cna't.\n");
		exit(0);
	}
	return 0;
 } 
