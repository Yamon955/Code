#include<iostream>
#include<cstring>
using namespace std;
char s1[10],s2[10];
int len;
int find(int a)
{
	for(int i=0;i<strlen(s1);i++){
		if(s1[i]==s2[a]) return i;
	}
}
void dfs(int l1,int r1,int l2,int r2)
{
	int f=find(r2);
	cout<<s2[r2];
	if(f-1>=l1) dfs(l1,f-1,l2,r2-r1+f-1);//r1-f为右子树结点数 
	if(r1>=f+1) dfs(f+1,r1,l2+f-l1,r2-1);//f-l1为左子树结点数 
}
int main()
{
	cin>>s1>>s2;
	len=strlen(s1);
	dfs(0,len-1,0,len-1);
}
