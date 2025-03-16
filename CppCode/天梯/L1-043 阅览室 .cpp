#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int N = 1e7+50;

int n;
int vis[N];
int st[N];

int change(char *s)
{
	int sum = 0;
	sum += ( (s[0] - '0')*10 + (s[1]-'0'))*60;
	sum += (s[3] - '0')*10;
	sum += s[4] - '0';
	return sum;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int id;
		char op,t[10];
		long long avg = 0,cnt = 0;
		mem(vis,0);
		while(cin>>id>>op>>t){ 
			if(id == 0) {
				if(cnt == 0) cout<<"0 0"<<endl;
				else{
					cout<<cnt<<" "<<int(1.0*avg/cnt+0.5)<<endl; //四舍五入
				}
				break;
			}
			if(op == 'S'){
				vis[id] = 1;
				st[id] = change(t);
			}
			else{
				if(vis[id] == 1){
					cnt++;
					vis[id] = 0;
					int Endtime = change(t);
					//cout<<Endtime<<endl<<endl;
					avg += Endtime - st[id];
				}
			}
			
		}
	}
	return 0;
}
