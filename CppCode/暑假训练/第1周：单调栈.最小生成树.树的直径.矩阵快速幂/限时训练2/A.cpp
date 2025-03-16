//https://vjudge.net/contest/450440#overview
//AtCoder arc095_b  
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int n;
int a[100005];
int Max,Min;
int idx;
long long ans = 1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	Max = a[1];
	idx = 1;
	for(int i=2;i<=n;i++){
		if(a[i] > Max){
			Max = a[i];
			idx = i;
		}
		//if(a[i] < Min) Min = a[i];
	}
	double mid = 1.0*Max/2;
	//cout<<mid<<endl;
	int Min;
	double len = Max;
	for(int i=1;i<=n;i++){
		if(i==idx) continue;
		if(a[i]>mid){
			if(len>a[i]-mid){
				len = a[i]-mid;
				Min = a[i];
			}
		}
		else{
			if(len>mid-a[i]){
				len = mid-a[i];
				Min = a[i];
			}
		}
		
	}
	cout<<Max<<" "<<Min<<endl;
	return 0;
	
}