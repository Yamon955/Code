#include<iostream>
#include<cstring>
using namespace std;
/*
1.质因数，就是指一个正整数的约数，并且该数还属于是质数的数字，质因数有时候也被我们叫做“素因数”和“质因子”，
    举例子来说，在2×2×2=8这个等式当中，数字2是数字8的约数，且2还属于质数，我们就称2是8的质因数。”
2.分解质因数的原理每个合数都可以写成几个质数相乘的形式.其中每个质数都是这个合数的因数,叫做这个合数的质因数.
    分解质因数的含义一个合数用几个质数相乘的形式表示出来,叫做分解质因数
*/
/// 将n分解为n=(a1^x1)*(a2^x2)*(a3^x3)*......---->a1,a2,a3....都是质数--->a1,a2,a3...就叫做n的质因数
//如果n能整除i，那么n也能整除(n/i)----->得到n能整除的整数范围[i,n/i];--->判断条件i*i<=n的由来
int m;
void f(int n)//分解质因数--->可查看约数中用容器unordered_map存放底数和指数的做法
{
    for(int i=2;i*i<=n;i++){ //枚举所有可能的质因子
        if(n%i==0){  //如果满足这个条件--->i一定就是个质数
            int cnt=0;//记录指数
            while(n%i==0){
                n/=i;//整除i
                cnt++;//指数+1
            }
            cout<<i<<" "<<cnt<<endl;//输出当前得到的一个质因子i和指数cnt
        }
    }
    //如果最后n==1说明这个数的质因子已经分解完了
    if(n!=1) cout<<n<<" "<<"1"<<endl;//如果n!=1,说明没有分解完的这个数n还是要分解数的一个质因子，且指数为1
    //判断最后一个数还是不是n的质因子，不要忘记这最后一个数
}

//如果分解 100！ 的质因数，上面方法不行，因为表示不出 100! 这个数
int prime[1000];
int Hash[1000];//用来存放每个质因数的指数
int cnt;
bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2;i<=n/i;i++) //如果条件改为i^2<=n可能会爆int-->可修改为for(long long i=2;i*i<=n;i++) 
        if(n%i==0) return false;
    return true;
}
void f_2(int n) //用来求 n! 的所有约数个数，同时这也提供了一个分解质因数的办法，若要分解数为 n! 也可以用其来分解
{
    for(int x=2;x<=n;x++){
        if(isPrime(x)) prime[cnt++] = x;
        int t = x;
        for(int i=0;i<cnt;i++){
            if(t == 1) break;
            while(t % prime[i] == 0){
                t /= prime[i];
                Hash[i]++;
            }
        }
    }
}


int main()
{
    cin>>m;
    while(m--){
        int n;
        cin>>n;
        f(n);
    }
    return 0;
}
