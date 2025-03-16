//AtCoder arc096_a
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
int a,b,c,x,y;
int x_num,y_num;
int l_x,l_y;
long long ans;
int main()
{
	cin>>a>>b>>c>>x>>y;
	if(a+b<=2*c){
		ans =(long long)x*a+y*b; 
	}
	else if(a+b>2*c){
		int Min = min(x,y);
		ans += Min*c*2;
		if(Min==x){
			if(b>2*c) ans += (y-Min)*2*c;
			else ans+= (y-Min)*b;
		}
		else{
			if(a>2*c) ans += (x-Min)*2*c;
			else ans+=(x-Min)*a;
		}
	}
	cout<<ans;
	return 0;
}
/*
Sample Input 1
1500 2000 1600 3 2
Sample Output 1
7900
It is optimal to buy four AB-pizzas and rearrange them into two A-pizzas and two B-pizzas, then buy additional one A-pizza.

Sample Input 2
1500 2000 1900 3 2
Sample Output 2
8500
It is optimal to directly buy three A-pizzas and two B-pizzas.

Sample Input 3
1500 2000 500 90000 100000
Sample Output 3
100000000
It is optimal to buy 
200000
 AB-pizzas and rearrange them into 
100000
 A-pizzas and 
100000
 B-pizzas. We will have 
10000
 more A-pizzas than necessary, but that is fine.
 */