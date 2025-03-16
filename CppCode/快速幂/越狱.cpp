#include<iostream>
#include<cstdio>
using namespace std;
/*
监狱有连续编号为  1  到  n  的  n  个房间，每个房间关押一个犯人。
有  m  种宗教，每个犯人可能信仰其中一种。
如果相邻房间的犯人信仰的宗教相同，就可能发生越狱。
求有多少种状态可能发生越狱。
输入格式
共一行，包含两个整数  m  和  n 。
输出格式
可能越狱的状态数，对  100003  取余。
数据范围
1≤m≤10^8 ,
1≤n≤10^12
*/
/*
思路：
一共  m^n种
不会越狱的状态  m*(m-1)^(n-1)种
会发生越狱的状态  (m^n)-m*(m-1)^(n-1)
/*
取模运算性质  (a-b)%p = [(a%p)-(b%p)]%p
证明：设 a=k1*p+q1--->a%p=q1----
        b=k2*p+q2--->b%p=q2----
        (a-b)=(k1-k2)*p+q1-q2
        (a*b)%p=(q1-q2)%p=[(a%p)-(b%p)]%p
*/
typedef long long ll;
const int tt=100003;
ll n,m;
ll qsm(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%tt;
        }
        a=(a*a)%tt;
        b>>=1;
    }
    return ans;
}
int main()
{
    cin>>m>>n;
    ll sum=qsm(m,n);
    ll w=(m*qsm(m-1,n-1))%tt;
    cout<<(sum-w+tt)%tt;//sum-w可能为负数
    return 0;
}
/*
2 3-->6
2 10-->1022
*/