#include<iostream>
#include<malloc.h>
#include<cstdio>
using namespace std;
#define Maxsize 255
#define ok 1
#define error 0
typedef struct{
	char *ch;
	int length;
}HString;
int StrAssign(HString &t,char*chars)//����һ����ֵ���ڴ�����chars�Ĵ�t
{
	if(t.ch) free(t.ch);//�ͷ�tԭ�еĿռ�
	int i;
	char* c;
	for(i=0,c=chars;*c!='\0';i++,c++);
	if(!i) {
		t.ch=NULL;
		t.length=0;
	}
	else {
		if(!(t.ch=(char *)malloc(i*sizeof(char)))) return error;
		for(int j=0;j<i;j++)
			t.ch[j]=chars[j];
		t.length=i;
	}
	return ok;
 } 
int Strlength(HString s)//����s��Ԫ�ظ�������Ϊ���ĳ���
{
	return s.length;
 } 
int Strcompare(HString s,HString t)//��s>t�򷵻�ֵ>0,��s=t�򷵻�ֵ=0,��s<t�򷵻�ֵ<0
{
	for(int i=0;i<s.length&&i<t.length;i++)
		if(s.ch[i]!=t.ch[i]) return s.ch[i]-t.ch[i];
	return s.length-t.length;
 } 
int Clearstring(HString &s)//��s��Ϊ�մ������ͷ�s��ռ�Ŀռ�
{
	if(s.ch) {
		free(s.ch);
		s.ch=NULL;
	}
	s.length=0;
	return ok;
}
int Concat(HString &t,HString s1,HString s2)//s1,s2���ӳ��´�t 
{
	if(t.ch) free(t.ch);//�ͷžɿռ� 
	t.length=s1.length+s2.length;
	t.ch=(char *)malloc(t.length*sizeof(char));
	if(!(t.ch)) return error;
	for(int i=0;i<s1.length;i++) t.ch[i]=s1.ch[i];
	for(int i=s1.length,j=0;j<s2.length;i++,j++) t.ch[i]=s2.ch[j];
	return ok;
}
int Substring(HString s,HString &sub,int pos,int len)//1<=pos<=Strlength(s)&&0<=len<=Strlength(s)-pos+1
{                                          //����s�е�pos���ַ��𳤶�Ϊlen���Ӵ�
	if(pos<1||pos>Strlength(s)||len<0||len>=Strlength(s)-pos+1) return error;
	if(sub.ch) free(sub.ch);
	if(!(sub.ch=(char *)malloc(len*sizeof(char)))) return error;
	for(int j=0,i=pos-1;j<len;j++,i++) sub.ch[j]=s.ch[i];
	sub.length=len;
	return ok;	
}
int main()
{
	HString t,s1,s2,sub;
	char *chars;
	cout<<"input chars:";
	cin>>chars;
	char *c=chars;
	while(*c){
		cout<<*c;
		c++;
	}
	StrAssign(t,chars);
	cout<<"StrAssign(t,chars):";
	for(int i=0;i<t.length;i++) cout<<t.ch[i];
	cout<<"the length of t:"<<Strlength(t)<<endl;
	cout<<"input s1:";
	for(int i=0;i<s1.length;i++) cout<<s1.ch[i];
	cout<<"input s2:";
	cin>>s2.ch;
	cout<<"the compare(s1,s2):"<<Strcompare(s1,s2)<<endl;
	cout<<"the t after concat(t,s1,s2):";
    Concat(t,s1,s2);
    for(int i=0;i<t.length;i++) cout<<t.ch[i];
    cout<<"the substring of t:";
    Substring(t,sub,2,3);
    for(int i=0;i<sub.length;i++) cout<<sub.ch[i];
    return 0;
	
}

