#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n,t;
	float value=0;
	cin>>n>>t;
	float w[n+1],v[n+1],f[n+1];
	int m[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
		f[i]=v[i]/w[i];
	}
	sort(f+1,f+n+1);
	int i,j;
	for(i=n;i>0;i--){
		for(j=1;j<=n;j++)
			if(f[i]==v[j]/w[j]&&m[j]==0) {
				m[j]=1;
				break;
			}
		if(t<=w[j]) {
			value+=t*f[i];
			break;
		}
		else{
			value+=v[j];
			t-=w[j];
		}			
	}
	printf("%.2f",value);
	return 0;
}
