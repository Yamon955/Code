//QDUOJ - 1072
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
char s[N][55],low[N][55];
int n;
int Binary_search(int l,int r,int x)
{
	while(l < r){
		int mid = (l+r)>>1;
		if(strcmp(low[mid],s[x]) < 0){
			l = mid + 1 ;
		}
		else r = mid;
	}
	return l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	
	strcpy(low[1],s[1]);
	int ans = 1;
	for(int i=2;i<=n;i++){
		if(strcmp(low[ans],s[i]) < 0){
			strcpy(low[++ans],s[i]);
		}
		else {
			int pos = Binary_search(1,ans,i);
			strcpy(low[pos],s[i]);
		}
	}
	cout<<ans<<endl;

}
/*
4
yu
hong
sen
yyds
--->3
*/