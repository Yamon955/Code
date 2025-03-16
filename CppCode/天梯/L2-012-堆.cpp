#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e9+50;

int n,m,len;
int h[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		h[++len] = a;
		int now = len;
		while(now != 1){
			if(h[now] < h[now/2]) swap(h[now],h[now/2]);
			now /= 2;
		}
	}
	while(m--){
		int x,y;
		char s1[100];
		cin>>x>>s1;
		if(s1[0] == 'a'){  // x y 是否是兄弟节点 
			string s1,s2;
			cin>>y>>s1>>s2;
			int pos_x,pos_y;
			for(int i=1;i<=len;i++){
				if(h[i] == x) pos_x = i;
				if(h[i] == y) pos_y = i;
 			} 
 			if(pos_x/2 == pos_y/2) cout<<"T"<<endl;
 			else cout<<"F"<<endl;
		}
		else{
			char s2[100];
			cin>>s2;
			if(s2[0] == 'a'){  //判断 x 是否是 y 的子节点 
				string s1,s2;
				cin>>s1>>s2>>y;
				int pos_x,pos_y;
				for(int i=1;i<=len;i++){
					if(h[i] == x) pos_x = i;
					if(h[i] == y) pos_y = i;
 				} 
 				if(pos_x/2 == pos_y) cout<<"T"<<endl;
				else cout<<"F"<<endl; 
			}
			else
			{
				char s3[100];
				cin>>s3;
				if(s3[0] == 'r'){  //判断 x 是否是根节点 
					if(x == h[1]) cout<<"T"<<endl;
					else cout<<"F"<<endl;
				}
				else{    //判断 x 是否是 y 的父节点 
					char s4[100];
					cin>>s4>>y;
					int pos_x,pos_y;
					for(int i=1;i<=len;i++){
						if(h[i] == x) pos_x = i;
						if(h[i] == y) pos_y = i;
 					} 
 					if(pos_y/2 == pos_x) cout<<"T"<<endl;
 					else cout<<"F"<<endl;
				}
			}
		}
	}
}
