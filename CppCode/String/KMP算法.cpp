#include<iostream>
#include<string>
using namespace std;
int Next[100000];
void find_Next(string t)
{
	int k=-1,j=0;
	Next[0]=-1;
	while(j<t.length()){
		if(k==-1||t[j]==t[k]){
			Next[++j]=++k;
		}
		else k=Next[k];
	} 
	for(int i=0;i<t.length();i++){
		cout<<Next[i]<<" ";
	}
} 
void KMP(string s1,string s2)
{
	int i=0,j=0;
	while(i<s1.length()){
		if(s2[j]==s1[i]){
			i++;
			j++;
		}
		else {
			if(Next[j]==-1) i++;
			else   j=Next[j];
		}
		if(j==s2.length()) {
			cout<<"yes";
			break;
		}
		} 
	if(i==s1.length()) cout<<"no";
}
int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	find_Next(s2);
	KMP(s1,s2);
	return 0;
	
}
