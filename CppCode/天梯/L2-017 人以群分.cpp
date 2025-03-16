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
const int N = 1e5+50;

int n;
int a[N];

int main()
{
	cin>>n;
	int s = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s += a[i];
	}
	sort(a+1,a+n+1);  //排序，先保证规模一致，如果总数是奇数个，则后面值较大的多一个，以此来获得最大差距
	int s1 = 0;
	for(int i=1;i<=n/2;i++) s1+=a[i];
	if(n%2 == 0){
		printf("Outgoing #: %d\n",n/2);
		printf("Introverted #: %d\n",n/2);
		printf("Diff = %d\n",s-2*s1);
	}
	else{
		printf("Outgoing #: %d\n",n/2+1);
		printf("Introverted #: %d\n",n/2);
		printf("Diff = %d\n",abs(s-2*s1));
	}
}