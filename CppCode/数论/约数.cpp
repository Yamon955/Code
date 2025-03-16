#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
vector<int>q;
/*
约数四个问题
1.求约数
2.求约数个数--->记住公式
3.求约数和
4.求最大公约数
*/
/*
q.push_back(i) 将i放进数组q的末尾
q.pop_back()  弹出最后一个元素
q.size()
q.empty()
q.begin()  返回头地址
q.end()    返回尾地址
遍历数组: for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
排序 ： sort(q.begin(),q.end()); //sort(数组头地址，数组尾地址)
*/
//求约数
//int q[1000],cnt;数组空间不好判断--->建议用动态数组vector
//1.如果n能整除i，那么n也能整除(n/i)----->得到n能整除的整数范围[i,n/i];--->判断条件i*i<=n的由来
void get_submultiple(int n)//获得n的所有约数
{
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            q.push_back(i);
            if(i!=n/i) q.push_back(n/i);//避免重复，因为i的值可能等于(n/i)--->看语句 1
        }
    }
}
//求约数个数
/*
先将n分解为质因数形式       n=(p1^a1)*(p2^a2)*(p3^a3)....*(pi^ai)
那么n的约数的个数公式为   num=(a1+1)*(a2+1)*(a3+1).....*(ai+1)  ---->公式
举例分析：360=(2^3)*(3^2)*5--->360的约数可以且只能是(2^a)*(3^b)*(5^c)---其中a为0~3，b为0~2，c为0~1 
                                --->由于a,b,c取值相互独立，由计数问题的乘法原理可知约数个数为(3+1)*(2+1)*(1+1)=24
*/
unordered_map<int,int>h;//--->相当于一个哈希表, 第一个数存底数，第二个数存指数
int get_num(int n)
{
    for(int i=2;i<=n/i;i++){ //分解质因数
        if(n%i==0){
            while(n%i==0){
                n/=i;
                h[i]++;
            }
        }
    }
    if(n!=1) h[n]++;
    int num=1;
    unordered_map<int,int>::iterator it;//迭代器遍历容器
    for(it=h.begin();it!=h.end();it++){
        num*=((*it).second+1);//套用公式
    }
    return num;
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
ll f_2(int n) //用来求 n! 的所有约数个数，同时这也提供了一个分解质因数的办法，若要分解数为 n! 也可以用其来分解
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
    ll ans = 1;
    for(int i=0;i<cnt;i++){
        if(Hash[i] != 0) ans *= Hash[i]+1; //套用公式
    }
    return ans;
}
// 例：4! 的约数个数为 8 个
//     100! 的约数个数为 39001250856960000 个


//求约数和
//先将n分解为质因数形式       n=(p1^a1)*(p2^a2)*(p3^a3)....*(pi^ai)
//公式  sum=(p1^0+p1^1+....+p1^a1)*(p2^0+p2^1+...+p2^a2)*(p3^0+p3^1+...+p3^a3)*....*(pi^0+pi^1+...+pi^ai)
int get_sum(int n)
{
    for(int i=2;i<=n/i;i++){ //分解质因数
        if(n%i==0){
            while(n%i==0){
                n/=i;
                h[i]++;
            }
        }
    }
    if(n!=1) h[n]++;

    int sum=1;
    unordered_map<int,int>::iterator it;//迭代器遍历容器
    for(it=h.begin();it!=h.end();it++){
        int tmp_sum=1;//用来存放公式中每个括号内的和，初始化为1，因为每个数的0次方为1
        for(int i=1;i<=(*it).second;i++){
            int tmp_tmpsum=1;//用来存放每个因数i次方--->初始化为 1 
            for(int j=1;j<=i;j++)
                tmp_tmpsum*=(*it).first;
            tmp_sum+=tmp_tmpsum;
        }
        sum*=tmp_sum;//套用公式
    }
    /*
    int sum=1;
    unordered_map<int,int>::iterator it;//迭代器遍历容器
    for(it=h.begin();it!=h.end();it++){
        int a=it->first,b=it->second;
        int tmp_sum=1;
        for(int i=1;i<=b;i++){
            tmp_sum=(tmp_sum*a+1);//好好理解该式子，它用来计算a^0+a^1+....+a^a1的和
        }
        sum*=tmp_sum;
    }*/
    
    return sum;
}

//求最大公约数---->辗转相除法
//公式  求(a,b)的最大公约数--->等价于 求(b,a%b) 的最大公约数
int gcd(int a,int b)
{
    if(b!=0) return gcd(b,a%b);
    else return a;
}
int main()
{

    return 0;
}
