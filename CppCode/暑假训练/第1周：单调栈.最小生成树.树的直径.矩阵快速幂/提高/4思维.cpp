#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,m,k;
int map[5005][5005];
int row_t[100005],col_t[100005]; //时间戳
int row_data[100005],col_data[100005];
int time; //记录出现的时间及出现的次序
/*
记录一下每一行每一列最后被变成了什么，以及时间戳

然后我们在判断这个格子最后是啥的时候，只用看他所在的这一行和这一列的时间戳哪个比较晚就好了
*/
int main()
{
    cin>>n>>m>>k;
    for(int j=1;j<=k;j++){
        int a,b,c;
        cin>>a>>b>>c; 
        if(a==1){
            row_t[b] = ++time;
            row_data[b] = c;
        }
        else if(a==2) {
            col_t[b] = ++time;
            col_data[b] = c;
        }
        
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(row_t[i] == col_t[j]) cout<<"0 ";
            else{
                int ans = row_t[i] > col_t[j] ? row_data[i] : col_data[j];
                cout<<ans<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
Input
3 3 3
1 1 3
2 2 1
1 2 2
Output
3 1 3 
2 2 2 
0 1 0 
Input
5 3 5
1 1 1
1 3 1
1 5 1
2 1 1
2 3 1
Output
1 1 1 
1 0 1 
1 1 1 
1 0 1 
1 1 1 
*/
