#include<iostream>
using namespace std;
#define Maxsize 255
#define ok 1
#define error 0
typedef struct{
	char str[Maxsize];
	int length;
}Sqstring;
int Concat(Sqstring &T,Sqstring s1,Sqstring s2);
int main()
{
	Sqstring T,s1,s2;
	cin>>s1.str;
	int i;
	for(i=0;s1.str[i]!='\0';i++);
	s1.length=i;
	cin>>s2.str;
	for(i=0;s2.str[i]!='\0';i++);
	s2.length=i;
	Concat(T,s1,s2);
	for(int i=0;i<T.length;i++)
		cout<<T.str[i];
	return 0;
}
 
int Concat(Sqstring &T,Sqstring s1,Sqstring s2)
{
	if(s1.length+s2.length<=Maxsize){
		for(int i=0;i<s1.length;i++) T.str[i]=s1.str[i];
		for(int i=0,j=s1.length;i<s2.length;i++,j++) T.str[j]=s2.str[i];
		T.length=s1.length+s2.length;
		return ok;
	}
	else if(s1.length<Maxsize&&s1.length+s2.length>Maxsize){
		for(int i=0;i<s1.length;i++) T.str[i]=s1.str[i];
		for(int i=0,j=s1.length;i<Maxsize-s1.length;i++,j++) T.str[j]=s2.str[i];
		T.length=Maxsize;
		return error;
	}
	else if(s1.length==Maxsize){
		for(int i=0;i<s1.length;i++) T.str[i]=s1.str[i];
		T.length=s1.length;
		return error;
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
