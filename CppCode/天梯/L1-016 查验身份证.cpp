#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e4+50;

int n;
char arr[20];
int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
char b[11] = { '1', '0', 'X', '9' ,'8' ,'7' ,'6', '5' ,'4', '3', '2' };
int main()
{
	cin>>n;
	int vis = 0;
	while(n --){
		cin>>arr;
		int flag = 0;
		int sum = 0;
		for(int i=0;i<17;i++){
			if(arr[i] == 'X'){  //前 17 位出现 X 为错误号码 
				flag = 1;
				break;
			}
			sum += (arr[i]-'0')*a[i];
		}
		sum = sum%11;
		if(arr[17] != b[sum]) flag = 1;
		if(flag) {
			cout<<arr<<endl;
			vis = 1;
			continue;
		} 
		
	}
	if(vis == 0) cout<<"All passed";
}