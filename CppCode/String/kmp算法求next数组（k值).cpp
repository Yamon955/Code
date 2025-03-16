#include<iostream>
#include<string>
using namespace std;
int main()
{
	string t;
	cin>>t;
	int k=-1,j=0;
	int next[t.length()];
	next[0]=-1;
	while(j<t.length()){
		if(k==-1||t[j]==t[k]){
			next[++j]=++k;
		}
		else k=next[k];
	} 
	for(int i=0;i<t.length();i++){
		cout<<next[i]<<" ";
	}
	return 0;
 } 
