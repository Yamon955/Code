//poj2196
#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 25;
int n,m;
int Solve(int base,int num)
{
	int sum = 0;
	while(num){
		sum += num%base;
		num /= base;
	}
	return sum;
}
int main()
{
	for(int i=2991;i<=9999;i++){
		if(Solve(10,i)==Solve(12,i) && Solve(10,i)==Solve(16,i))
			cout<<i<<endl;

	}
	return 0;
}