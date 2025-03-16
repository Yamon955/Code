#include<iostream>
#include<cstdio>
using namespace std;
/*
取模运算性质  (a*b)%p = [(a%p)*(b%p)]%p
证明：设 a=k1*p+q1--->a%p=q1----
        b=k2*p+q2--->b%p=q2----
        (a*b)=(k1*k2*p+k1*q2+k2*q1)*p+q1*q2
        (a*b)%p=(q1*q2)%p=[(a%p)*(b%p)]%p

由此性质：每乘一次对p取模  ans=(ans*a)%p     
*/

////求a^b mod p 即求a的b次方对p取模
typedef long long ll;
ll fast_power(ll a,ll b,ll p)
{
    ll ans=1;
    while(b){
         if(b&1){  //b&1 相当于 b%2
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;//相当于b/=2;
    }
   return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<fast_power(a,b,c)<<endl;
    }
    return 0;
}