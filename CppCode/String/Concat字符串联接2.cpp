#include<iostream>
using namespace std;
#define Maxsize 255
#define true 1
#define false 0
typedef char Sqstring[Maxsize+1];//0号元素存放串的长度 


int Concat(Sqstring &T,Sqstring s1,Sqstring s2)
{
	int i,j,uncut;
	if(s1[0]+s2[0]<=Maxsize) {
		for(i=1;i<=s1[0];i++)
			T[i]=s1[i];
		for(i=s1[0]+1,j=1;j<=s2[0];i++,j++)
			T[i]=s2[j];
		T[0]=s1[0]+s2[0];
		return true;
	} 
	if(s1[0]<Maxsize&&s1[0]+s2[0]>Maxsize){
		for(i=1;i<=s1[0];i++)
			T[i]=s1[i];
		T[0]=Maxsize;
		for(i=s1[0]+1,j=1;s1[0]+1+j<=T[0];i++,j++)
			T[i]=s2[j]; 
		return false;
	}
	if(s1[0]==Maxsize){
		for(i=1;i<=s1[0];i++)
			T[i]=s1[i];
	    T[0]=s1[0];
	return false;
	}
	
 } 
 
 
int main()
{
	int i;
	Sqstring s1,s2,T;
	s1="5abcde";
	s2="4fghj";
	Concat(T,s1,s2);
	cout<<T;
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
