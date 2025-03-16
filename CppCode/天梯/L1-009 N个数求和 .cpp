#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e9+50;

int n;
ll a1,a2,b1,b2;
long long int gcd(long long int a,long long int b)  //只有当 ab 同时为 0 ，他们的最大公因数才为 0 
{
  return b?gcd(b,a%b):a;
}
int main()
{
	cin>>n;
	scanf("%lld/%lld",&a1,&a2);
	n -= 1;
	while(n --){
		scanf("%lld/%lld",&b1,&b2);
		ll t = a2*b2/__gcd(a2,b2);
		a1 = t/a2*a1 + t/b2*b1;
		a2 = t;
		t = __gcd(a1,a2);
		a1 /= t;
		a2 /= t;
	}
	ll zhengshu = a1/a2;
	a1 = a1%a2;
	if(zhengshu == 0) {
		if(a1 == 0) printf("0");
		else{
			printf("%lld/%lld",a1,a2);
		}
	}
	else{
		if(a1 != 0) {
			printf("%lld ",zhengshu);
   			printf("%lld/%lld",a1,a2);
		}
		else{
			printf("%lld",zhengshu);
		}
	}
	
 } 
