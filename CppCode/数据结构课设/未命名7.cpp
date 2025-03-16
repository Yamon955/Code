#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
char s[1000],w[100][100]; 
clockid_t start,stop;//时间
typedef struct{
	char s[100];//存放单词 
	int number;//出现次数 
}Word; //单词结构体 
////////////////////////////////////////////////////////////////////////// 
///////////顺序表 
typedef struct{
	Word *elem;
	int len;
}SqList;//顺序表 
void Init_SqList(SqList &L)//创建一个顺序表，即开辟空间 
{
	L.elem=(Word *)malloc(5000*sizeof(Word));
	L.len=0;
}
void SqList_Insert(SqList &L,Word a)//插入到顺序表中 
{
	if(L.len==0){
		strcpy(L.elem[L.len].s,a.s);
		L.elem[L.len].number=a.number;
		L.len++;
	}
	else {
		int i;
		for(i=0;i<L.len;i++){
			if(strcmp(L.elem[i].s,a.s)>0){//单词排序，字典序小的在前，便于折半查找 
				for(int j=L.len;j>i;j--){
					strcpy(L.elem[j].s,L.elem[j-1].s);
					L.elem[j].number=L.elem[j-1].number;
				}
				strcpy(L.elem[i].s,a.s);
				L.elem[i].number=a.number;
				L.len++;
				break;
			}
		}
		if(i==L.len) {
			strcpy(L.elem[i].s,a.s);
			L.elem[i].number=a.number;
			L.len++;
		}
	}
}
void print(SqList L)//顺序表打印 
{
	for(int i=0;i<L.len;i++){
		cout<<L.elem[i].s<<" "<<L.elem[i].number<<endl;
	}
}
void SqSearch_SqList(SqList L,char a[])//基于顺序表的顺序查找 
{
	int i;
	start = clock();        /*  开始计时  */
	for(int j=0;j<=100000;j++) //查找多次 
	for(i=0;i<L.len;i++){
		if(strcmp(L.elem[i].s,a)==0){//找到查找的单词 
			break;
		}
	}
	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(i==L.len){
		cout<<"查找失败."<<endl;
	}
	else{
		printf("此单词的词频为: %d\n",L.elem[i].number);
		printf("查找该单词所花的时间: %fms\n",duration);
		printf("平均查找长度: %.1f\n",(L.len+1.0)/2);
	}
} 
void HalfSearch_SqList(SqList L,char a[])//基于顺序表的折半查找 
{
	int mid,l,r;
	start = clock();
	for(int j=0;j<=100000;j++){
		l=0,r=L.len-1;
		while(l<=r){
			mid=(l+r)/2;
			if(strcmp(L.elem[mid].s,a)==0)//找到查找的单词 
				break;	
			else if(strcmp(L.elem[mid].s,a)>0) r=mid-1;
			else if(strcmp(L.elem[mid].s,a)<0) l=mid+1;
		}
	}
	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(l>r) cout<<"查找失败."<<endl;
	else{
		printf("此单词的词频为: %d\n",L.elem[mid].number);
		printf("查找该单词所花的时间: %fms\n",duration);
		printf("平均查找长度: \n"); 
	}
	
 } 
////////链表 
typedef struct Lnode{
	Word data;
	struct Lnode *next;
}Lnode,*Linklist;
void Init_Linklist(Linklist &L)//初始化链表 
{ 
    L = (Linklist)malloc(sizeof(Lnode)); 
    L->next = NULL; 		
}
void Linklist_Insert(Linklist &L,Word a)
 {
 	Lnode *p=L;
 	while(p->next){
 		p=p->next;
	 }
	 Lnode *s=(Linklist)malloc(sizeof(Lnode));
	 s->data=a;
	 s->next=p->next;
	 p->next=s;
 }
 int Displist(Linklist L)//链表打印 
{
	Lnode *p=L->next;
	while(p){
		cout<<p->data.s<<" "<<p->data.number<<endl;
		p=p->next;
	}
}
void SqSearch_Linklist(Linklist L,char a[]) 
{
	Lnode* p;
	start = clock();
	for(int j=0;j<=100000;j++){
		p=L->next;
		while(p){
			if(strcmp(p->data.s,a)==0) break;
			else p=p->next;
		}
	}
	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(!p) cout<<"查找失败."<<endl;
	else{
		printf("此单词的词频为: %d\n",p->data.number);
		printf("查找该单词所花的时间: %fms\n",duration);
		printf("平均查找长度: \n"); 
	}
}
/////////////////////////////////////////////////////////////////////////////////// 
//////二叉排序树
typedef struct BiTNode{
	Word data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
int SearchBST_(BiTree &T,Word a,BiTree f,BiTree &p)
{                           
	if(!T){					
        p=f;                             
		return 0;
	}
	else
		if(strcmp(T->data.s,a.s)==0){
			p=T;
			return 1;
		}
		else
			if(strcmp(T->data.s,a.s)>0) return SearchBST_(T->lchild,a,T,p);
			else       return SearchBST_(T->rchild,a,T,p);
}
void InsertBST(BiTree &T,Word e) 
{
	BiTree p,s;
	if(!SearchBST_(T,e,NULL,p)){
		s=(BiTree)malloc(sizeof(BiTNode));
		strcpy(s->data.s,e.s);
		s->data.number=e.number;
		s->lchild=s->rchild=NULL;
		if(!T) T=s;
		else
			if(strcmp(p->data.s,e.s)>0) p->lchild=s;
			else if(strcmp(p->data.s,e.s)<0) p->rchild=s;
	} 
}
void CreateBST(BiTree &T,Word a[],int n)//创建二叉排序树 
{
	T=NULL;//初始为空树 
	int i=0;
	while(i<n){
		InsertBST(T,a[i]);
		i++;
	}
 }
 void mid(BiTree T)//中序遍历二叉排序树 
{
	if(T!=NULL){
		mid(T->lchild);
		cout<<T->data.s<<endl;
		mid(T->rchild);	
    }
 } 
/////////////////////////////////////////////////////////////////////////// 
int eq(Word word,char w[]){//判断两个单词是否一样 
	int flag=1;
	for(int j=0;word.s[j]!='\0'&&w[j]!='\0';j++){
		if(word.s[j]!=w[j]) {
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	FILE *fp=fopen("InFile.txt","r+");
	if(fp==NULL){
		cout<<"不能打开";
		exit(1);	
	}
	int count=0,n=0,num;
	char ch;
	while((ch=fgetc(fp))!=EOF){
		s[count++]=ch;//将文件中的所有字符提取到字符数组s中
	}
	for(int i=0;i<count;i++){
		if(s[i]>='a'&&s[i]<='z') {
			w[num][n]=s[i];n++;
		}
		else if(s[i]>='A'&&s[i]<='Z'){
			char ch=s[i]-'A'+'a';
			w[num][n]=ch;
			n++;
		}
		else{
			num++;
			n=0;
		}
	}
	Word word[5000];//存放不重复的单词 
	count=0;//记录单词的种类数 
	for(int i=0;i<num;i++){
		int x=0,flag=0;
		if(w[i][0]>='a'&&w[i][0]<='z'){
			for(x=0;x<count;x++){
				if(eq(word[x],w[i])) {
					flag=1;
					break;
				} 
			}
			if(flag==1){//如果两个单词一样 
				word[x].number++; 
			}
			else{ 
				for(int j=0;w[i][j]!='\0';j++) word[count].s[j]=w[i][j];
				word[count].number++;
				count++;
			}	
		} 
	}
	SqList L;
	Init_SqList(L);
	for(int i=0;i<count;i++){
		SqList_Insert(L,word[i]);
	} 
	print(L);
	Linklist L2;
	Init_Linklist(L2);
	for(int i=0;i<count;i++){
		Linklist_Insert(L2,word[i]);
	}
	cout<<endl;
	Displist(L2);
	cout<<endl;
	BiTree T;
	CreateBST(T,word,count);
	mid(T);
	cout<<"Enter a word"<<endl;
	char c[100];
	cin>>c;
	HalfSearch_SqList(L,c);
	//SqSearch_SqList(L,c);
	 fclose(fp);	
	return 0;
}

