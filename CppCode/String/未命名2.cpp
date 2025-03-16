#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int next[100];
	string t,s;
	cin>>t;
	cin>>s;
	int j,k;
	j=0,k=-1;
	next[0]=-1;
	while(j<s.length()){
		if(k==-1||s[j]==s[k])
			next[++j]=++k;
		else k=next[k];
	}
	for(int i=0;i<s.length();i++) cout<<next[i]<<" ";
		j=0;
		int i=0;
		while(j<s.length()&&i<t.length()){
			if(t[i]==s[j]){
				i++;
				j++;
			}
		     else {
		     	if(next[j]==-1) i++;
		     	else j=next[j];
			 }
		}
	if(i==t.length()) cout<<"no";
	else cout<<"yes";
	
	return 0;
 } 
