#include<stdio.h>
int a[101],n;//����ȫ�ֱ�������������Ҫ���Ӻ�����ʹ�� 
void quicksort(int left,int right){
	int i,j,k,temp;
	if(left>right)//����Ҫ����֤���������Խ��� 
	  return;
	i=left;
	j=right;
	temp=a[left];//temp���ǻ�׼�� 
	while(i<j){
		while(a[j]>=temp && i<j)//Ҫ���ҵ����ң�˳�����Ҫ 
		  j--;
		while(a[i]<=temp && i<j)//�ٴ��������� 
		  i++;
	    if(i<j){//��������û������ʱ 
	    	k=a[i];
	    	a[i]=a[j];
	    	a[j]=k;//�����������������е�λ�� 
		}
	}
	a[left]=a[i];//��׼����λ 
	a[i]=temp;
	quicksort(left,i-1);//����������ߵģ�����һ���ݹ�Ĺ��� 
	quicksort(i+1,right);//���������ұߵģ�����һ���ݹ�Ĺ��� 
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	quicksort(1,n);//����������� 
	for(i=1;i<=n;i++)
	  printf("%d ",a[i]);//��������Ľ�� 
	return 0;
}
	

