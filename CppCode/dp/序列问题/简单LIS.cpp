//POJ-2533
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
int n;
int dp[N];
int a[N];
int low[N];
int Binary_Search(int l,int r,int x)
{
    while(l < r){
        int mid = (l+r)>>1;
        if(low[mid] < x) l = mid+1;
        else r = mid;
    }
    return l;
}
int LIS()  //O(n*logn)做法 
{
    low[1] = a[1];
    int len = 1;
    for(int i=2;i<=n;i++){
        if(a[i] > low[len]){
            low[++len] = a[i];
        }
        else{
            int pos = Binary_Search(1,len,a[i]);
            low[pos] = a[i];
        }
    }
    return len;

}
int main()
{
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		 int ans = 0;
		//  dp[1] = 1;
		 for(int i=1;i<=n;i++){
            dp[i] = 1;
		 	for(int j=1;j<i;j++){
		 		if(a[i] > a[j])
		 			dp[i] = max(dp[i],dp[j]+1);
		 	}
            ans = max(ans,dp[i]);
		 }
		 cout<<ans<<endl;
        //cout<<LIS()<<endl;
	}
	return 0;
}
/*
Sample Input
7
1 7 3 5 9 4 8
Sample Output
4
*/