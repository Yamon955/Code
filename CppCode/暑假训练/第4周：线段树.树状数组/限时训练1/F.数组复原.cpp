//CodeForces - 987E
// 考虑两个数字的时候我们交换 2x 次跟没交换一样，交换2x+1次才有效
// n个数字的时候，交换3n或7n+1次同样有很多没有用的操作。
// 假设有效操作为cnt，那么剩下的都是无效操作，无效操作一定为2x次（即偶数次），
// 因为奇数次操作一定会引起两个数位置的变化。如果（3n-cnt）为偶数就是Petr操作的，如果（7n+1-cnt）为偶数那么就是Um_nik操作的。
// 所以我们计算cnt就好了，其实cnt就是我们把这个序列每次交换两个数字，变为原序列，有效交换的次数。

#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
int n;
int a[N];
int main()
{
    while(cin>>n && n){
        for(int i=1;i<=n;i++) cin>>a[i];
        int cnt = 0;
        for(int i=1;i<=n;i++){
            while(a[i] != i){
                swap(a[i],a[a[i]]);  //关键
                cnt ++;
            }
        }
        if ((3*n-cnt)&1) printf("Um_nik\n");
        if ((7*n+1-cnt)&1) printf("Petr\n");
    }
    return 0;
}