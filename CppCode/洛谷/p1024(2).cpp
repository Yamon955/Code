#include<iostream>
using namespace std;
#include<stdio.h>
double a,b,c,d;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
	cin>>a>>b>>c>>d; 
	double l,r,m;
	int i,s=0;
	for(i=-100;i<100;i++){
		l=i;
		r=i+1;
		if(f(l)==0){
			printf("%.2lf ",l);
			s++;
		}
		if(f(l)*f(r)<0){
			while((r-l)>=0.001){
				m=(r+l)/2;
				if(f(m)*f(r)<=0) l=m;
				else            r=m;
			}
			printf("%.2lf ",l);
			s++;
		}
		if(s==3) break;
	}
	return 0;
}
	
