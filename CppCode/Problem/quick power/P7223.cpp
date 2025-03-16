#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll N= 998244353; //可能会爆 int
int n,p;
int a[1000010];
int res=1;
ll qsm(ll a,ll b)//这里要用 long long ,因为可能会爆int
{
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%N;
		a=(a*a)%N;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>p;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		res=(res*(qsm(p,a[i])+1))%N;
	}
	cout<<res<<endl;
	return 0;
}
/*
2 2
1 4
---->51
*/