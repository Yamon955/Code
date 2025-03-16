#include<iostream>
#include<cstring>
using namespace std;
int a[550],b[550],c[550];

//高精算法原因：int: -2^31~2^31-1     数量级为10^9;
//        long long: -2^63~2^63-1      数量级为10^18; 
//当数据较大时(a,b<=10^500)，整型数据类型无法表示运算
//因此用数组模拟高精度 
int main()
{
	char s1[550],s2[550];
	cin>>s1>>s2;
	int la=strlen(s1);
	int lb=strlen(s2);
	for(int i=0;i<la;i++){
		a[la-i]=s1[i]-'0';  //将字符转换为数字，并且将字符转置以便于计算 
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=s2[i]-'0';
	}
	int lc=max(la,lb)+1;
	for(int i=1;i<=lc;i++){  //c[1]储存个位，c[2]存储十位依次类推 
		c[i]+=a[i]+b[i];  //用+=的原因是为了加上前面产生的进位 
		c[i+1]=c[i]/10;  //将产生的进位先加到下一位中，呼应上一条语句用+=的原因 
		c[i]=c[i]%10;    //对10取余 
	}
	if(c[lc]==0 && lc>0)  //删除前导0(例如计算结果可能为 02546201->第一位为0，需删除)  条件lc>0是为了避免计算结果为0时而将此正确结果当作前导0删除 
		lc--; 
	for(int i=lc;i>0;i--) cout<<c[i];
	return 0; 
 } 
