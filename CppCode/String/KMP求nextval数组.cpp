#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int nextval[100];
	int i,j,k;
	nextval[0]=-1;
	j=0,k=-1;
	while(j<s.length()){
		if(k==-1||s[j]==s[k]){
			++j;++k;
			if(s[j]!=s[k]) nextval[j]=k;
			else nextval[j]=nextval[k];
		}
		else k=nextval[k];
	}
	for(i=0;i<s.length();i++) cout<<nextval[i]<<" ";
	return 0;
}
