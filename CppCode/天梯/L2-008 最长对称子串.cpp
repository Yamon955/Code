#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+50;


char s[N];
int Max=1;  //初值为 1 
int main()
{
	cin.getline(s,1005);
	int len = strlen(s);
	for(int i=0;i<len;i++){
		for(int j=len-1;j>i;j--){
			int flag = 0;
			for(int k=i,w=j;k<=w;k++,w--){
				if(s[k] != s[w]){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				Max = max(Max,j-i+1); 
			}
		}
	}
	cout<<Max<<endl;
	return 0;
}