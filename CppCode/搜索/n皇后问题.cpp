#include<iostream>
using namespace std;
int a[1000],b[1000],c[1000],d[1000];
//a����
//b����
//c�����µ����ϵĶԽ��ߣ���+�еĺ���ͬ��
//d�����µ����ϵĶԽ��ߣ���-�еĲ���ͬ��
int total=0,n;
void print()
{
	total++;
	if(total<=3){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
void queen(int i)
{
	if(i>n){
		return;
	}
	else 
	for(int j=1;j<=n;j++){
		if(b[j]==0&&c[i+j]==0&&d[i-j+n]==0){
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+n]=1;
			if(i==n) print();
			queen(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+n]=0;
		}
	}
}
int main()
{
	cin>>n;
	queen(1);
	cout<<total;
 } 
