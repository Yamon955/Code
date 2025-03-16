#include<iostream>
#include<string.h> 
#include<algorithm>
using namespace std;
int num_weight[26];//叶子结点的权值 
int num_ch=0;//叶子结点个数 
void number_ch(char *s)//统计字符频率  以频率为权值   字符只包含小写字母 
{
	int count[26]={0};
	for(int i=0;i<strlen(s);i++){
		count[s[i]-'a']++;//按照ascll值为数组下标 
	}
	for(int i=0;i<26;i++){
		if(count[i]!=0) {
			num_weight[num_ch++]=count[i];//以ascll值大小为顺序将个字母频率放入num_weight[]中，并更新表示结点数num_ch的值 
			char ch=i+'a';//按ascll值由小到大输出各字母 
			cout<<ch<<":"<<count[i]<<"  ";//输出字母以及对应的权值 
		}
	}
	cout<<endl;
} 
//////////////////////////////////////////////////////////////
typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
void CreateHuffmanTree(HuffmanTree &T,int n)//创建哈夫曼树 
{
	if(n<=1) return ;
	int m=2*n-1;//此树一共有n个叶子节点，没有1度结点，而n0(0度结点)=n2(2度结点)+1 ,所以此哈夫曼树总的结点个数为 m=n0+n2=2n-1 
	T=new HTNode[m+1];//T[0]不使用 ，T[m]表示根节点 
	for(int i=1;i<=m;i++){
		T[i].parent=0;T[i].lchild=0;T[i].rchild=0;//每个单元的双亲，左右孩子下标都初始化为0 
	}
	int j=0;
	for(int i=1;i<=n;i++){
		T[i].weight=num_weight[j];//输入对应的权值 
		j++;
	}
	int flag[m+1]={0},temp_weight[100];
	int s1,s2;//从所有的权值中选出两个最小的 
	for(int i=n+1;i<=m;i++){
		int count_num=0;
		for(int j=1;j<=i-1;j++){
			while(flag[j]!=0){//判断第j个结点是否已经使用过 
				j++;
			} 
			temp_weight[count_num++]=T[j].weight;
		}
		sort(temp_weight,temp_weight+count_num);
		for(int j=1;j<=i-1;j++){
			if(T[j].weight==temp_weight[0]&&flag[j]==0){
				s1=j;
				flag[s1]=1;
				break;
			} 
			else if(T[j].weight==temp_weight[1]) s2=j;
		}
		for(int j=1;j<=i-1;j++){
			if(T[j].weight==temp_weight[1]&&flag[j]==0){
				s2=j;
				flag[s2]=1;
				break;
			} 
		}
		flag[s1]=1;flag[s2]=1;
		T[s1].parent=i;T[s2].parent=i;
		T[i].lchild=s1;T[i].rchild=s2;
		T[i].weight=T[s1].weight+T[s2].weight;
 	} 
}
void CreateHuffmanCode(HuffmanTree T,char** &HC,int n)//从叶子到根逆向求每个字符的哈夫曼编码，并存到编码表HC中 
{
	HC=new char*[n+1];//HC[0]不使用 
	char *cd=new char[n]; //分配临时存放字符i编码的空间 
	cd[n-1]='\0';//编码结束符 
	int start,c,f;
	for(int i=1;i<=n;i++){//逐个字符求哈夫曼编码 
		start=n-1;//start开始指向最后，即编码结束位置 
		c=i;f=T[i].parent;//f指向结点c的双亲结点 
		while(f!=0){     //从叶子结点开始向上回溯，直到根节点 
			--start;
			if(T[f].lchild==c) cd[start]='0';//结点c是f的左孩子，则生成代码0 
			else               cd[start]='1';//结点c是f的右孩子，则生成代码1 
			c=f;      //继续向上回溯 
			f=T[f].parent;
		}     //求出第i个字符的编码保存到cd[]中 
		HC[i]=new char[n-start]; //为第i个字符编码分配空间 
		strcpy(HC[i],&cd[start]);//将求得的编码从临时空间cd中复制到HC的当前行中 
	}
	delete cd;//释放临时空间 
}
void disp_ch_HuffmanCode(HuffmanTree T,char *s,char **HC,int n)//打印哈夫曼编码 
{
	int count[26]={0};
	for(int i=0;i<strlen(s);i++){
		count[s[i]-'a']++;
	}
	char ch_[26];//按ascll值大小从小到大有序存放各个字符   
	int n1=1;
	for(int i=0;i<26;i++){
		if(count[i]>0) {
			char a=i+'a';
			ch_[n1++]=a;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ch_[i]<<":"<<HC[i]<<" ";//输出每个字符对应的哈夫曼编码 
	}                                 //第i个字符存在ch_[i] ,其编码对应存在HC[i]中 
	cout<<endl;
	char Huffman_[200];//存放字符串的完整哈夫曼编码 
	int w1=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=T[i].weight;j++){
			int w2=0;
			while(HC[i][w2]!='\0') Huffman_[w1++]=HC[i][w2++];
		}
	for(int i=1;i<w1;i++) cout<<Huffman_[i];//输出此编码 
	cout<<endl;
	for(int i=1;i<w1;){  //由哈夫曼编码译出字符串 
		for(int j=1;j<=n;j++){
			int k=0,temp_i=i;
			while(Huffman_[temp_i]==HC[j][k]){
				temp_i++;k++;
			}
			if(HC[j][k]=='\0'){
				cout<<ch_[j];
				i=temp_i;
				break;
			}
		}
	} 
	cout<<endl;
}
int main()
{
	char *s;
	s=new char[100];
	cin>>s;
	while(!(s[0]=='0'&&s[1]=='0'&&s[2]=='\0')){
			number_ch(s);
		HuffmanTree T;
		CreateHuffmanTree(T,num_ch);
		for(int i=1;i<=2*num_ch-1;i++){
			cout<<i<<" "<<T[i].weight<<" "<<T[i].parent<<" "<<T[i].lchild<<" "<<T[i].rchild<<" "<<endl;
		}
		char** HC; 
		CreateHuffmanCode(T,HC,num_ch);
		disp_ch_HuffmanCode(T,s,HC,num_ch);
		//num_weight[26]={0};
		num_ch=0;
		cin>>s;
	}
	return 0;
}
/*
输入样例 
aaaaaaabbbbbccdddd 
aacccb 
00 
输出样例 
a:7 b:5 c2 d:4 
1 7 7 0 0 
2 5 6 0 03 2 5 0 0 
4 4 5 0 0 
5 6 6 3 4 
6 1 1 7 2 5 
7 1 8 0 1 6 
a:0 b:10 c:110 d:111 
000000010101010110110111111111111 
aaaaaaabbbbbccdddd 
a:2 b:1 c:3 
1 2 4 0 0 
2 1 4 0 0 
3 3 5 0 0 
4 3 5 2 1 
5 6 0 3 4 
a:11 b:10 c:0 
111110000 
aabccc
*/
