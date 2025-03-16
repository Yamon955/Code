#include<iostream>
using namespace std;
#include<stdio.h>
double a,b,c,d;

int main()
{
	cin>>a>>b>>c>>d; 
	double l,m,i;
	int s=0;
	for(i=-100;i<=100;i+=0.001){
		double r=i+0.001;
		if((a*i*i*i+b*i*i+c*i+d)*(a*r*r*r+b*r*r+c*r+d)<0){
			printf("%.2lf ",i);
			s++;
		}
		if(s==3) break;
	}
	return 0;
 } 
