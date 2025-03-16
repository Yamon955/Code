#include<iostream>
#include<algorithm>
using namespace std;
int s1,s2,s3,s4;
bool cmp(int a,int b){
	return a>b;
}
int time(int n,int f[])
{
	if(n==1) return f[0];
	else if(n==2) return f[0]>f[1]?f[0]:f[1];
	else{
		sort(f,f+n,cmp);
		int ltime=0,rtime=0;
		ltime+=f[0];
		rtime+=f[1];
		for(int i=2;i<n;){
			if(ltime<rtime) ltime+=f[i++];
			else if(ltime==rtime&&i<n-1){
				ltime+=f[i++];
				rtime+=f[i++];
			}
			else if(ltime==rtime&&i==n-1) ltime+=f[i++];
			else if(ltime>rtime) rtime+=f[i++];
	    }
	    return ltime>rtime?ltime:rtime;
	}
}
int main()
{
	cin>>s1>>s2>>s3>>s4;
	int a[s1+1],b[s2+1],c[s3+1],d[s4+1];
	for(int i=0;i<s1;i++) cin>>a[i];
	for(int i=0;i<s2;i++) cin>>b[i];
	for(int i=0;i<s3;i++) cin>>c[i];
	for(int i=0;i<s4;i++) cin>>d[i];
	a[s1]=time(s1,a);
	b[s2]=time(s2,b);
	c[s3]=time(s3,c);
	d[s4]=time(s4,d);
	cout<<a[s1]+b[s2]+c[s3]+d[s4];
	return 0;
	
}
