#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[9];
int main()
{
    for(int i=0;i<10;i++) f[i]=2021;
    int flag = 1;
    int i;
    for(i=1;;i++){
        int j = i;
        while(j){
            if(f[j%10]!=0){  //如果当前数的卡片还有
                f[j%10] -= 1;
            }
            else flag = 0;
            j = j/10;
        }
        if(flag==0) break;
    }
    cout<<i-1;
    return 0;
}
//3181