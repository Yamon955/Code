//洛谷 P-1439
/*我们可以以第一个串为标准，用第二个串来匹配第一个串，看能匹配多少，所以，其实第一个串的每个数字其实影响不大，只有知道它对应了第二串的哪个数字就好了，那么我们为什么不把他给的串重新定义一下？
比如他的样例：3 2 1 4 5 我们把他变成 1 2 3 4 5 用一个数组记录一下每个数字变成了什么，相当于离散化了一下3-1；2-2；1-3；4-4；5-5；
现在我们的第二串1 2 3 4 5 按我们离散化的表示：3 2 1 4 5
可能有些人已经懂了，我们把第一个串离散化后的数组是满足上升，反过来，满足上升的也就是满足原串的排列顺序的，（如果你不懂的话可以多看几遍这个例子）O(∩_∩)O~
好了 ，现在的问题就变成了求一个最长不下降序列！好了！解决完成！
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int low[N];
int a[N],b[N],idx[N],L[N];
int n;
int Binary_Search(int l,int r,int x)
{
    while(l < r){
        int mid = (l+r)>>1;
        if(low[mid] < x) l = mid+1;
        else r = mid;
    }
    return l;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        idx[a[i]] = i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        L[i] = idx[b[i]];
    } 
    low[0] = L[0];
    int len = 0;
    for(int i=1;i<=n;i++){
        if(L[i] >= low[len]){  //O(nlogn)求最长不下降子序列
            low[++len] = L[i];
        }
        else{
            int pos = Binary_Search(1,len,L[i]);
            low[pos] = L[i];
        }
    }
    cout<<len<<endl;
    return 0;
}
/*
5 
3 2 1 4 5
1 2 3 4 5
--->3
*/

