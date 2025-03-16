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

int n;
int Max;
int st;
int main()
{
	cin>>n;
	for(int i=2;i<=sqrt(n);i++){
		int j = i;
		int cnt = 0;
		int t = n;
		int tmp = i;
		while(t%tmp == 0){
			cnt++;
			j++;
			tmp *= j;
		}
		if(Max < cnt){
			Max = cnt;
			st = i;
		}
	}
	
	if(Max){
		cout<<Max<<endl;
		cout<<st;
		for(int i=1;i<Max;i++){
			cout<<"*"<<st+i;
		}
	}
	else{  //如果 n 为素数 
		cout<<"1"<<endl;
		cout<<n<<endl;
	}
		
	return 0;
 } 

