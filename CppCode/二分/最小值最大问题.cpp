/* POJ2456 */
/*��n��ţ����ѡm���Ž�ţ���൱��һ���߶����� n ���㣬ѡȡ m ���㣬ʹ�����ڵ�֮�����С����ֵ���
���ȸ���n��ţ���λ�ã���ôÿ��ţ��֮�����С�����Ǻ���������ţ��֮
��ľ��롣��ˣ��ȸ�ţ���λ���Ÿ��򡣽���һͷţ����0��λ�ã�
���ַ�������������d�����ǰһͷţ�ŵ���xi������Ҫ����һͷ�ŵ�
����xi+d<=xj����С��xj����������֤�������ͷţ֮��ľ��붼����ȵ�ǰ����СֵС�����ÿ���������������žͿ�����Ϊ��Сֵ��
*/ 
 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std;
int n,m;
int a[100005],v[100005];
int judge(int d)
{
	int count=1;//ע���һֻţ�Ѿ��Ž�ţ��a[0]λ���� ���ʳ�ֵΪ1 
	int last=0; 
	for(int i=1;i<n;i++){
		if(a[i]-a[last]>=d){ //a[i]���ţ������һ��ţ��a[last]�����ڵ���d����ʾ�����ٷŽ�ţ
			last=i;
			count++;//�ַŽ�һͷţ 
		}
	} 
	if(count>=m) return 1;//����ţ�������� 
	else return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);//��ţ���������� 
	int minn=1;//��С����Ϊ1 
	int maxn=a[n-1]-a[0];//������Ϊţ�������ļ�ȥţ������С�� 
	while(minn<maxn){
		int mid=(minn+maxn+1)>>1;
		if(judge(mid)) minn=mid;
		else maxn=mid-1;
	}
	cout<<minn<<endl;//����Ϊʲô������l-1�أ����赽�����һ�������Ĵ�mid����ʱl = mid + 1 ����ô��һ���ض���������l = r�˳�����ʱ����ʵΪl - 1����������mid 
	return 0;
}
/*
5 3
1
2
8
4
9
-->3
*/

