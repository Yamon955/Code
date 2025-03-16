//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int T,n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(i%2)
			for(int j=1;j<=m;j++)
				printf("#");
		else{
			cnt++;
			if(cnt%2){
				for(int j=1;j<=m-1;j++)
					printf(".");
				printf("#");
			}
			else{
				printf("#");
				for(int j=1;j<=m-1;j++)
					printf(".");
			}
				
		}
		printf("\n");
	}


	return 0;
}
/*
Sample Input
9 9

Sample Output
#########
........#
#########
#........
#########
........#
#########
#........
#########
*/