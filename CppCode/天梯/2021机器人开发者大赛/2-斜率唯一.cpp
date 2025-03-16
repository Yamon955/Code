/*
*****一对互质的整数可以唯一地表示一个斜率，所以这里可以将木棋的xy坐标同时除他们的gcd，变成两个互质的整数******

用形如map<pair,vector<pair>这样的结构存储，就完成了分类。


枚举每个方向，这样处理：
先把这个方向上的所有点根据到原点的距离排序。
从前往后枚举，如果有连续的一段木棋的p值全都是1，那么把它们一起击倒得到的收益和分别击倒得到的收益是一样的，可以合并击倒。
如果单个木棋的p值大于1，肯定是单独击倒划算，就单独击倒。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#include<map>
#include<utility>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
map<pair<int,int>,int>mp;
int x[N],y[N],w[N];
struct node{
	int k;
	int w;
};

vector<node>xl,xr,yl,yr;
vector<node>v[N];
int cnt;
int n,sum;
bool cmp(node a,node b)
{
	return a.k < b.k;
}
int getans(vector<node> v)
{
	int ans = 0;
	if(v.size() == 1) return 1;
	sort(v.begin(),v.end(),cmp);
	v.push_back({inf,0});
	for(int i=1;i<v.size();i++){
		if(v[i].w == v[i-1].w && v[i].w == 1);
		else ++ans;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>w[i];
		sum += w[i];
	}
	for(int i=1;i<=n;i++){
		if(!x[i]){
			if(y[i] > 0) yl.push_back({y[i],w[i]});
			else yr.push_back({-y[i],w[i]});
		}
		else if(!y[i]){
			if(x[i] > 0) xl.push_back({x[i],w[i]});
			else xr.push_back({-x[i],w[i]});
		}
		else{
			int d = __gcd(abs(x[i]),abs(y[i]));
			x[i] /= d;
			y[i] /= d;
			if(!mp.count({x[i],y[i]})){
				mp[{x[i],y[i]}] = ++cnt;
				v[cnt].push_back({d,w[i]});
			}
			else v[mp[{x[i],y[i]}]].push_back({d,w[i]});
		}
	}
	int num = 0;
	for(int i=1;i<=cnt;i++)
		num += getans(v[i]);
	num += getans(xl);
	num += getans(xr);
	num += getans(yl);
	num += getans(yr);
	cout<<sum<<" "<<num;
}
/*
输入样例:
11
1 2 2
2 4 3
3 6 4
-1 2 2
-2 4 3
-3 6 4
-1 -2 1
-2 -4 1
-3 -6 1
-4 -8 2
2 -1 999
结尾无空行
输出样例:
1022 9
*/
