#include<stdio.h>
int a[101],n;//定义全局变量，这两个需要在子函数中使用 
void quicksort(int left,int right){
	int i,j,k,temp;
	if(left>right)//很重要，保证函数最后可以结束 
	  return;
	i=left;
	j=right;
	temp=a[left];//temp就是基准数 
	while(i<j){
		while(a[j]>=temp && i<j)//要从右到左找，顺序很重要 
		  j--;
		while(a[i]<=temp && i<j)//再从左向右找 
		  i++;
	    if(i<j){//当两个数没有相遇时 
	    	k=a[i];
	    	a[i]=a[j];
	    	a[j]=k;//交换两个数在数组中的位置 
		}
	}
	a[left]=a[i];//基准数归位 
	a[i]=temp;
	quicksort(left,i-1);//继续处理左边的，这是一个递归的过程 
	quicksort(i+1,right);//继续处理右边的，这是一个递归的过程 
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	quicksort(1,n);//快速排序调用 
	for(i=1;i<=n;i++)
	  printf("%d ",a[i]);//输出排序后的结果 
	return 0;
}
	

