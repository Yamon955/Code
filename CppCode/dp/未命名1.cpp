#include<iostream>
using namespace std;
int main()
{
	int n,sum;
	for( n=1;;n++){
		sum=0;
		for(int i=n;;i++){
			sum+=i;
			if(sum%2==0&&sum==236) {
				cout<<n;
				return 0;
			}
			else if(sum>236||sum%2!=0) break;
		}
	}
	return 0;
 } 
