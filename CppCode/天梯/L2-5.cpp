#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#include<map>
#include<set>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 10005;
int n,m;
set<int>s[55];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        while(x--){
            int y;
            cin>>y;
            s[i].insert(y);
        }
    }
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        set<int>::iterator it;
        int sum = s[x].size()+s[y].size();
        int cnt = 0;
        for(it = s[x].begin();it!=s[x].end();it++){
            if(s[y].find(*it) != s[y].end()){
                cnt++;
            }
        }
        //cout<<cnt<<" "<<sum<<endl;
        printf("%.2f\%\n",1.0*cnt/(sum-cnt)*100);
    }

}
/*
输入样例：
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
结尾无空行
输出样例：
50.00%
33.33%
*/
