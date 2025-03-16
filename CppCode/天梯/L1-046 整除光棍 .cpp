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
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e4+50;

int x;
int main()
{
	cin>>x;
	int r = 1;    //记录余数 
	int cnt = 1;  //记录 1 的位数 
	while(r < x){
		r = r*10+1;
		cnt ++;
	}
	//除法原理 
	while(1){
		printf("%d",r/x);  
		r = r%x;
		if(r == 0){  //余数为 0 证明可以整除 
			break;
		}
		r = r*10+1;  //余数补一个 1，即 余数*10+1 
		cnt++;
	}
	cout<<" "<<cnt;
}

