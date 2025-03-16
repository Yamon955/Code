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
const int N = 1e4+50;

int n;
double a[N];
int cnt[N];

typedef struct node{
	int num;
	double money;
	int cnt;
}people;
people po[N];

bool cmp(people c,people d)
{
	if(c.money != d.money)
		return c.money > d.money;
	else if(c.cnt != d.cnt)
		return c.cnt > d.cnt;
	else 
		return c.num < d.num;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k --){
			int P;
			double M;
			cin>>P>>M;
			a[P] += M;
			cnt[P]++;
			a[i] -= M; 
		}
	}
	for(int i=1;i<=n;i++){
		po[i].num = i;
		po[i].money = a[i];
		po[i].cnt = cnt[i];
	}
	sort(po+1,po+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%d %.2f\n",po[i].num,po[i].money/100);
	}
	return 0;
 } 

