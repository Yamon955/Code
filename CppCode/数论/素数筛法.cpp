#include<iostream>
#include<cstring>
using namespace std;
/*
质数/素数：
    问题1：输入一个n(1<=n<=10^5) 判断n是不是素数
    问题2：输入一个n(1<=n<=10^5) 筛选出1--n中的质数
    问题3：输入一个n(1<=n<=10^5) 请分解出它的质因数
*/
//如果n能整除i，那么n也能整除(n/i)----->得到n能整除的整数范围[i,n/i];--->判断条件i*i<=n的由来

//试除法判断素数----O(n^(1/2))
bool f(int n)
{
    if(n<2) return false;
    for(int i=2;i<=n/i;i++) //如果条件改为i^2<=n可能会爆int-->可修改为for(long long i=2;i*i<=n;i++) 
        if(n%i==0) return false;
    return true;
}
//埃式筛法  晒质数-----O(nlognlogn)
/*
过程：晒{2，3，4，5，6，7，8，9，10，11，12，13，14，15.....}
输出最小素数2，筛掉2的倍数{3，5，7，9，11，13，15.....}
输出最小素数3，筛掉3的倍数{5，7，11，13....}//发现多晒了6，12..
输出最小素数5，筛掉5的倍数{7，11，13....}
*/
//它的思想很简单，把1-n以内素数的整数倍的数字划掉，留下的就全是素数
int n;
int prime[100010];
int v[100010];//初始化所有的数都是素数，如果i不是素数，v[i]=1
int cnt=0;
void E_sieve(){
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            prime[cnt++]=i;
            for(int j=i+i;j<=n;j+=i){ //筛掉当前素数i的所有倍数(在n范围内),素数的倍数一定是非素数
                v[j]=1;
            }
        }
    }
}
//参考题目洛谷P3383
//线性筛法(欧拉筛法)---O(n)
//用每一个数的最小质因数来筛选--->保证了每个数被晒一遍,因此时间复杂度为O(n)
void O_sieve(){
    for(int i=2;i<=n;i++){
        if(v[i]==0) prime[cnt++]=i;//如果是素数，放进素数数组中
        for(int j=0;i*prime[j]<=n&&j<cnt;j++){ //枚举i之前的所有质数  
            v[prime[j]*i]=1;//晒质数,素数的i倍筛掉
            if(i%prime[j]==0) break;//最关键的步骤，保证了每个数最多被筛一次，将时间复杂度降到了线性。
        }
    }
}
 /*
如果i%prime[j]==0,prime[j]是i的最小质因子，prime[j]*i最小质因子是prime[j]
如果i%prime[j]!=0,i的最小质因子大于prime[j],但是prime[j]*i最小质因子还是prime[j]
从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
如果i的最小质因数是 Prime[s]，那么 Prime[s]更早被枚举到（因为我们从小到大枚举质数），当时就要break）
*/
int main()
{
    cin>>n;
    //E_sieve();
    O_sieve();
    for(int i=0;i<cnt;i++) cout<<prime[i]<<" ";
    return 0;
}