//https://www.dotcpp.com/oj/problem2646.html
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
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e6+50,M=1e9+7;

int p,q,s;
double n;

ll gcd(ll a,ll b)
{
	if(b) return gcd(b,a%b);
	else return a;
	 
}
int main()
{
	cin>>p>>q>>s;
	ll w = pow(10,q-p+1);
	ll f = s%w;
	ll d = s / w;
	ll k = pow(10,p-1);
	
	ll a = d*(w-1)*k + f*k;  //通分后的分子 
	ll b = k*(w-1)*k;        //通分后的分母 
	//cout<<a<<b<<endl;
	ll g = gcd(a,b);
	///cout<<g<<endl;
	cout<<a/g<<" "<<b/g<<endl;
	
}

/*
该题就是运用循环小数的特点：

纯循环小数转化为分数：如0.4285742857…

找到循环体42857，该循环体有5位，故而0.4285742857…就是42857/99999，这里有5个9

这个公式自已也可以推导，对于真分数X/Y来说，

X/Y = L/(10^n - 1)

其中L为循环节，n为循环节位数

混合循环小数转化为分数：如0.14285742857…

大致方法和1中类似，不过注意的是这里的0.1不在循环体内，但可以转化为
0.1+(0.4285742857...)/10，0.1转换为分数1/10，循环体部分用1中的方法来得到分数再/10即可。1/10+42857/99999/10。如果要得到最简分数，那么可以使用辗转相除法求得二者的最大公约数，之后再用最大公约数同时除以分子和分母即可。

*/