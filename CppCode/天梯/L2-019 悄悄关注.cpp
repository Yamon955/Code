#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e3+50;
string name[N*2];
int num[N*2];
int sum;
int n,cnt;
set<string>s;
string ans[N*2];

bool cmp(string s,string t){
	return s<t;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		string ss;
		cin>>ss;
		s.insert(ss);
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>name[i]>>num[i];
		sum += num[i];
	}
	int flag = 0;
	for(int i=1;i<=m;i++){
		if(!s.count(name[i]) && num[i]*1.0 > 1.0*sum/m){
			ans[cnt++] = name[i];
			flag = 1;
		}
	}
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++) printf("%s\n",ans[i].c_str()); //c_str()函数,就可以把string类型得到等效字符数组，
	if(flag == 0) printf("Bing Mei You");
	return 0;
	
 } 