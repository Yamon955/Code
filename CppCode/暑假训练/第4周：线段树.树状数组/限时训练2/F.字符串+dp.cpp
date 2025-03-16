// CodeForces - 1196D2 
// 由于字符变换最多是R开头 RGBRGB…， G开头GBRGBR…，B开头BRGBRG… 所以枚举这3种情况来进行字符的匹配。
// dp[i]记录i位置是否需要修改，需要修改就是1，不需要就是0。从头开始进行匹配，枚举下3种情况就可以的出所有结果，找出最少的即是答案。
//  复杂度O(n)，题目说所有的n不超过2e5。
// 用c++的string输入字符串的话消耗的时候会多很多，所以还是用字符数组输入。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
char str[N], ss[3] = {'R', 'G' , 'B'};
int q, n, k, dp[N];
int main() {
	scanf("%d", &q);
    memset(dp,0,sizeof dp);
	while (q--) {
		scanf("%d%d%s", &n, &k, str + 1);	
		int ans = n; //记录最少需要修改的字符
		//分别以  RGBRGB...  GBRGBR... BRGBRG..开始   
		for (int i = 0; i < 3; i++) {
			int f = i; //记录是以哪个字母开头
			for (int j = 1; j <= n; j++) {
				dp[j] = dp [j - 1] + (str[j] != ss[f]);  //相等的话为0  不相等就要修改所以为1
				f = (f + 1) % 3; //下标是 0 1 2
				if (j >= k) {
					//已经截取了K个字符  比较最小答案
					ans = min(ans, dp[j] - dp[j - k]); 
				}
			} 
		}
		printf("%d\n", ans);
	}	
	return 0;
} 
/*
Input
3
5 2
BGGGG
5 3
RBRGR
5 5
BBBRR
Output
1
0
3
*/
