#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b!=0) return gcd(b,a%b);
    else return a;
}
int lcm(int a,int b)//求最小公倍数
{
    return a/gcd(a,b)*b;
}
int main()
{
    int a,b;
    while(cin>>a>>b){
        cout<<"最大公约数"<<gcd(a,b)<<endl;
        cout<<"最小公倍数"<<lcm(a,b)<<endl;
    }
    return 0;
}