//AtCoder arc095_a
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
typedef struct node{
	int idx;
	int val;
}Node;
Node a[200005];
int f[200005],d[200005];
bool cmp(Node a,Node b){
	return a.val<b.val;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int val;
		cin>>val;
		a[i].idx = i;
		a[i].val = val;
        f[i] = val;
        d[i] = val;
	}
	sort(f+1,f+n+1);
    int mid = n/2;
	for(int i=1;i<=n;i++){
		if(d[i]<=f[mid]) cout<<f[mid+1]<<endl;
        else cout<<f[mid]<<endl;

	}
	return 0;
}