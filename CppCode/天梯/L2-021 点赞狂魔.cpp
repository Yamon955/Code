#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e3+50;

int n;
int cnt;
int num[N];

typedef struct node{
	char name[10];
	int cnt;
	int sum;
}Node;
Node no[N];

bool cmp(Node a,Node b){
	if(a.cnt != b.cnt) return a.cnt > b.cnt;
	else{
		return 1.0*a.sum/a.cnt < 1.0*b.sum/b.cnt;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		char name[10];
		int k;
		cin>>name>>k;
		set<int>s;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			s.insert(a);
		}
		strcpy(no[i].name,name);
		no[i].cnt = s.size();
		no[i].sum = k;	
	}
	sort(no+1,no+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<no[i].name<<" "<<no[i].cnt<<" "<<no[i].sum<<endl; 
	if(n >= 3){
		for(int i=1;i<=3;i++) 
		if(i == 3) printf("%s",no[i].name);
		else printf("%s ",no[i].name);
	}
	else{
		for(int i=1;i<=n;i++) printf("%s ",no[i].name);
		for(int i=n+1;i<=3;i++){
			if(i == 3) cout<<"-";
			else cout<<"- ";
		}
	}
	return 0;
}