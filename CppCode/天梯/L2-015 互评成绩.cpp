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
const int N = 1e4+50;

int  n,k,m;
double num[N];


int main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		double Max = -1;
		double Min = 101; 
		for(int j=1;j<=k;j++){
			double a;
			scanf("%lf",&a);  //double 用scanf输入要用 %lf  用printf输出用 %f
			Max = max(Max,a);
			Min = min(Min,a);
			num[i] += a;
		}
		num[i] -= Max;
		num[i] -= Min;
		//printf("%.3f",1.0*num[i]);
	}

	sort(num+1,num+n+1);
	for(int i=n-m+1;i<=n;i++){
		if(i == n) printf("%.3f",1.0*num[i]/(k-2));
		else printf("%.3f ",1.0*num[i]/(k-2));
	}
	return 0;

}
