#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int ans;
int arr[9] = {1,2,3,4,5,6,7,8,9};
int getNum(int x,int y,int *arr)
{
    int res = 0;
    for(int i=x;i<y;i++){
        res = res*10 + arr[i];
    }
    return res;
}
int main()
{
    while(scanf("%d",&N) != EOF){
        ans = 0;
        do{
            for(int i=1;i<=7;i++){
                for(int j=1;j<=7;j++){
                    if(i+j < 9){
                        int a = getNum(0,i,arr);
                        int b = getNum(i,i+j,arr);
                        int c = getNum(i+j,9,arr);
                            
                        if(b%c == 0 && a+b/c == N){
                            //cout<<a<<" "<<b<<" "<<c<<endl;
                            ans ++;
                        }
                    }
                }
            }

        }while(next_permutation(arr,arr+9));
        cout<<ans<<endl;
    }
    return 0;
}