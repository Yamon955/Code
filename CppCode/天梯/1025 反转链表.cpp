#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6+50; 

int st,n,k;
typedef struct node{
	int data;
	int next;
	int fir;
}Node;
Node no[N];

int main()
{
	cin>>st>>n>>k;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		no[a].data = b;
		no[a].next = c;
		if(c!=-1) no[c].fir = a;
	}
	int tmp = st;
	int cnt = 0;
	while(tmp != -1){
		cnt ++;  //统计有效节点数，并不是所有节点都会用的上
		tmp = no[tmp].next;
	}
	n = cnt; //n = 有效节点个数
    
	int w = 0;
	while(n-w >= k){
		for(int i=1;i<k;i++){
			st = no[st].next;
		}
		int end = no[st].next;
		if(w != 0) printf("%05d\n",st);
		for(int i=1;i<=k;i++){
			printf("%05d ",st);
			printf("%d ",no[st].data);
			if(i != k) 
				printf("%05d\n",no[st].fir);
			st = no[st].fir;
		}	
		w += k;	
		st = end;
	}
	if(st != -1){
		printf("%05d\n",st);
		for(int i=w+1;i<=n;i++){
			printf("%05d ",st);
			printf("%d ",no[st].data);
			if(i != n) printf("%05d\n",no[st].next);
			else cout<<"-1";
			st = no[st].next;
		}
	}
	else cout<<"-1";
}
/*
输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/