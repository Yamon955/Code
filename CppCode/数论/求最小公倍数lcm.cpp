#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b!=0) return gcd(b,a%b);
    else return a;
}
int lcm(int a,int b)//����С������
{
    return a/gcd(a,b)*b;
}
int main()
{
    int a,b;
    while(cin>>a>>b){
        cout<<"���Լ��"<<gcd(a,b)<<endl;
        cout<<"��С������"<<lcm(a,b)<<endl;
    }
    return 0;
}