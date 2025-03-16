//cf1494B
// 这道题可以很容易的分析出来角角的四个位置是起决定性作用的四个位置，
// 并且这个位置只有两种可能性：放（1）或者不放（0）而且只有四个角，因此我们就很轻易地想到了枚举，
// （时间复杂度很低）每一个角角的位置我都枚举出来，如果有这种可能的flag=1，所有情况都不符合的则flag=0，
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool check(int n,int u){
	return u<=n-2&&u>=0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int f=0;
		int u,r,d,l;
		cin>>u>>r>>d>>l;
		for(int t1=0;t1<=1;t1++){
			for(int t2=0;t2<=1;t2++){
				for(int t3=0;t3<=1;t3++){
					for(int t4=0;t4<=1;t4++){
						if(check(n,u-t1-t2)&&check(n,r-t2-t3)&&check(n,d-t3-t4)&&check(n,l-t4-t1))f=1;
					}
				}
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
Input
4
5 2 5 3 1
3 0 0 0 0
4 4 1 4 0
2 1 1 1 1
Output
YES
YES
NO
YES
*/
