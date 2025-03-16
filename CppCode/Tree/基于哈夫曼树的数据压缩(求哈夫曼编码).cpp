#include<iostream>
#include<string.h> 
#include<algorithm>
using namespace std;
int num_weight[26];//Ҷ�ӽ���Ȩֵ 
int num_ch=0;//Ҷ�ӽ����� 
void number_ch(char *s)//ͳ���ַ�Ƶ��  ��Ƶ��ΪȨֵ   �ַ�ֻ����Сд��ĸ 
{
	int count[26]={0};
	for(int i=0;i<strlen(s);i++){
		count[s[i]-'a']++;//����ascllֵΪ�����±� 
	}
	for(int i=0;i<26;i++){
		if(count[i]!=0) {
			num_weight[num_ch++]=count[i];//��ascllֵ��СΪ˳�򽫸���ĸƵ�ʷ���num_weight[]�У������±�ʾ�����num_ch��ֵ 
			char ch=i+'a';//��ascllֵ��С�����������ĸ 
			cout<<ch<<":"<<count[i]<<"  ";//�����ĸ�Լ���Ӧ��Ȩֵ 
		}
	}
	cout<<endl;
} 
//////////////////////////////////////////////////////////////
typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
void CreateHuffmanTree(HuffmanTree &T,int n)//������������ 
{
	if(n<=1) return ;
	int m=2*n-1;//����һ����n��Ҷ�ӽڵ㣬û��1�Ƚ�㣬��n0(0�Ƚ��)=n2(2�Ƚ��)+1 ,���Դ˹��������ܵĽ�����Ϊ m=n0+n2=2n-1 
	T=new HTNode[m+1];//T[0]��ʹ�� ��T[m]��ʾ���ڵ� 
	for(int i=1;i<=m;i++){
		T[i].parent=0;T[i].lchild=0;T[i].rchild=0;//ÿ����Ԫ��˫�ף����Һ����±궼��ʼ��Ϊ0 
	}
	int j=0;
	for(int i=1;i<=n;i++){
		T[i].weight=num_weight[j];//�����Ӧ��Ȩֵ 
		j++;
	}
	int flag[m+1]={0},temp_weight[100];
	int s1,s2;//�����е�Ȩֵ��ѡ��������С�� 
	for(int i=n+1;i<=m;i++){
		int count_num=0;
		for(int j=1;j<=i-1;j++){
			while(flag[j]!=0){//�жϵ�j������Ƿ��Ѿ�ʹ�ù� 
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
void CreateHuffmanCode(HuffmanTree T,char** &HC,int n)//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬���浽�����HC�� 
{
	HC=new char*[n+1];//HC[0]��ʹ�� 
	char *cd=new char[n]; //������ʱ����ַ�i����Ŀռ� 
	cd[n-1]='\0';//��������� 
	int start,c,f;
	for(int i=1;i<=n;i++){//����ַ������������ 
		start=n-1;//start��ʼָ����󣬼��������λ�� 
		c=i;f=T[i].parent;//fָ����c��˫�׽�� 
		while(f!=0){     //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�����ڵ� 
			--start;
			if(T[f].lchild==c) cd[start]='0';//���c��f�����ӣ������ɴ���0 
			else               cd[start]='1';//���c��f���Һ��ӣ������ɴ���1 
			c=f;      //�������ϻ��� 
			f=T[f].parent;
		}     //�����i���ַ��ı��뱣�浽cd[]�� 
		HC[i]=new char[n-start]; //Ϊ��i���ַ��������ռ� 
		strcpy(HC[i],&cd[start]);//����õı������ʱ�ռ�cd�и��Ƶ�HC�ĵ�ǰ���� 
	}
	delete cd;//�ͷ���ʱ�ռ� 
}
void disp_ch_HuffmanCode(HuffmanTree T,char *s,char **HC,int n)//��ӡ���������� 
{
	int count[26]={0};
	for(int i=0;i<strlen(s);i++){
		count[s[i]-'a']++;
	}
	char ch_[26];//��ascllֵ��С��С���������Ÿ����ַ�   
	int n1=1;
	for(int i=0;i<26;i++){
		if(count[i]>0) {
			char a=i+'a';
			ch_[n1++]=a;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ch_[i]<<":"<<HC[i]<<" ";//���ÿ���ַ���Ӧ�Ĺ��������� 
	}                                 //��i���ַ�����ch_[i] ,������Ӧ����HC[i]�� 
	cout<<endl;
	char Huffman_[200];//����ַ������������������� 
	int w1=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=T[i].weight;j++){
			int w2=0;
			while(HC[i][w2]!='\0') Huffman_[w1++]=HC[i][w2++];
		}
	for(int i=1;i<w1;i++) cout<<Huffman_[i];//����˱��� 
	cout<<endl;
	for(int i=1;i<w1;){  //�ɹ�������������ַ��� 
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
�������� 
aaaaaaabbbbbccdddd 
aacccb 
00 
������� 
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
