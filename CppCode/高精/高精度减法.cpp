#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10087],b[10087],c[10087];
int compare(char *p,char *q) 
{
	int lp=strlen(p);
	int lq=strlen(q);
	if(lp!=lq) return lp>lq;
	for(int i=0;i<lq;i++){
		if(p[i]!=q[i]){
			return p[i]>q[i];
		}
	}
}
int main()
{
	char s1[10087],s2[10087];
	cin>>s1>>s2;
	int flag=0;
	if(compare(s1,s2)==0){ //s1<s2 ->交换两个数 
		flag=1;
		char s3[10087];
		strcpy(s3,s1);
		strcpy(s1,s2);
		strcpy(s2,s3); 
	} 
	int la=strlen(s1);
	int lb=strlen(s2);
	for(int i=0;i<la;i++){
		a[la-i]=s1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=s2[i]-'0';
	}
	int lc=max(la,lb);
	for(int i=1;i<=lc;i++){
		if(a[i]<b[i]){
			a[i+1]--;//向前一位借 1 
			a[i]+=10;///注意   += 
		}
		c[i]=a[i]-b[i];
	}
	while(c[lc]==0&&lc>1) lc--;
	if(flag==1) printf("-");
	for(int i=lc;i>0;i--) printf("%d",c[i]);
	return 0;
 } 
