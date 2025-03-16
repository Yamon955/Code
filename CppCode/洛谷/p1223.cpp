#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int a[100],b[100];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(b[i]==a[j]){
				cout<<j<<" ";
				break;
			}
		}
	float sum=0.0;
	for(int i=1;i<=n;i++)
		sum+=b[i];
	printf("\n%.2lf",sum/n);
	return 0;
}
