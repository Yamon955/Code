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

int l,r;
int main()
{
	cin>>l>>r;
	int sum = 0;
	int cnt = 0;
	for(int i=l;i<=r;i++){ 
		sum += i;
		cnt++;
		printf("%5d",i);
		//printf("%05d",i); 用 0 来填充空字符
		//printf("%-5d",i);  左对齐 
		if(cnt == 5){
			cout<<endl;
			cnt = 0;
		} 
		
	}
	if((r-l+1)%5 != 0) cout<<endl;
	printf("Sum = %d",sum);
}
