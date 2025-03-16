#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
const int INF = 0x3f3f3f3f;
int n;
int map[2050][2050];
int get(int x,int y)
{
    int i;
    for(i=min(x,y);;i++){
        if(i%x==0&&i%y==0) break;
    }
    return i;
}
int main()
{
    for(int i=1;i<=2021;i++){
        for(int j=i+1;j<=2021;j++){
            if(fabs(i-j)>21) {
                map[i][j]=INF;
                map[j][i]=INF;
            }
            else {
                map[i][j] = lcm(i,j);
                map[j][i] = map[i][j];
            }
        }
    }
    for(int k=1;k<=2021;k++){
        for(int i=1;i<=2021;i++){
            for(int j=1;j<=2021;j++){
                map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
            }
        }
    }
    cout<<map[1][2021];
    return 0;
}
//10266837