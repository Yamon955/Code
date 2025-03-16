#include<iostream>
#include<cstring>
using namespace std;
int a[550],b[550],c[550];
int main()
{
	char s1[550],s2[550];
	cin>>s1>>s2;
	int la=strlen(s1);
	int lb=strlen(s2);
	for(int i=0;i<la;i++){
		a[la-i]=s1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=s2[i]-'0';
	}
	int lc=max(la,lb)+1;
	for(int i=1;i<=lc;i++){
		c[i]+=a[i]+b[i];
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;
	}
	if(c[lc]==0&&lc>0) lc--;
	for(int i=lc;i>0;i--) cout<<c[i];
	return 0;
 } 
