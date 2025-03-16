#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
char s[1000000],w[5000][100];//数组w[]用来存放所有单词 
clockid_t start,stop;//时间
int key;//界面控制开关 
int word_count;//统计单词的种类 
typedef struct{
	char s[100];//存放单词 
	int number;//出现次数 
}Word; //单词结构体 
Word word[5000];//存放不重复的单词 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort_Word(Word w[])//对结构体数组w[]里面的字符串按照字典序排序,以便于按照字典序输出 
{
	Word w1[word_count];
	int num=1,j;//计数 
	w1[0]=w[0];
	for(int i=1;i<word_count;i++){
		for(j=0;j<num;j++){
			if(strcmp(w[i].s,w1[j].s)<0){
				for(int m=num;m>j;m--){
					w1[m]=w1[m-1];
				}
				w1[j]=w[i];
				num++;
				break;
			}
		}
		if(j==num){
			w1[j]=w[i];
			num++;
		}
	}
	for(int i=0;i<word_count;i++) w[i]=w1[i];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
///////////顺序表 
typedef struct{
	Word *elem;
	int len;
}SqList;//顺序表 
SqList L;
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
void print_SqList1(SqList L)//顺序表顺序查找词频统计 
{
	
	/*for(int i=0;i<L.len;i++){
		cout<<L.elem[i].s<<" "<<L.elem[i].number<<endl;
	}*/
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile1.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"单词总数%d\n",word_count);

	for(int i=0;i<L.len;i++)
		fprintf(fp,"%s     %d\n",L.elem[i].s,L.elem[i].number);

	fclose(fp);
}
void print_SqList2(SqList L)//顺序表折半查找词频统计
{
	
	/*for(int i=0;i<L.len;i++){
		cout<<L.elem[i].s<<" "<<L.elem[i].number<<endl;
	}*/
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile3.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"单词总数%d\n",word_count);

	for(int i=0;i<L.len;i++)
		fprintf(fp,"%s     %d\n",L.elem[i].s,L.elem[i].number);

	fclose(fp);
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
	stop = clock();     /*  停止计时  */
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
float get_aveSearchlegth_HalfSearh(SqList L,Word w[])//获得平均查找长度 
{
	int sum=0;//总的查找此数 
	for(int i=0;i<word_count;i++){ //遍历查找每个单词的查找次数 
		int l=0,r=L.len-1,n=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(strcmp(L.elem[mid].s,w[i].s)==0){//找到查找的单词 
			 	sum+=n; //找到此单词后将此单词的查找次数加到sum中 
				break;
			}	
			else if(strcmp(L.elem[mid].s,w[i].s)>0) {
				n++;//查找此数加一 
				r=mid-1;
			}
			else if(strcmp(L.elem[mid].s,w[i].s)<0){
				n++;//查找此数加一 
			 	l=mid+1;
		 	} 
		}
	}
	return (sum*1.0)/word_count;
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
		printf("平均查找长度: %.1f\n",get_aveSearchlegth_HalfSearh(L,word)); 
	}
	
 } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////链表 
typedef struct Lnode{
	Word data;
	struct Lnode *next;
}Lnode,*Linklist;
Linklist L2;
void Init_Linklist(Linklist &L)//初始化链表 
{ 
    L = (Linklist)malloc(sizeof(Lnode)); 
    L->next = NULL; 		// 指针域为空
}
void Linklist_Insert(Linklist &L,Word a)//链表插入 
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
 int print_Linklist(Linklist L)//链表的顺序查找的词频统计 
{
	Word w1[word_count]; 
	int n=0;
	Lnode *p=L->next;
	while(p){
		w1[n++]=p->data;
		p=p->next;
	}
	sort_Word(w1);
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile2.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"单词总数%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w1[i].s,w1[i].number);

	fclose(fp);
}
float get_aveSearchlength_Linklist(Linklist L,Word w[])
{
	int sum=0;//总的查找次数 
	for(int i=0;i<word_count;i++){//遍历查找每个单词的查找次数 
		Lnode *p=L->next;
		int n=1; 
		while(p){
			if(strcmp(p->data.s,w[i].s)==0){
				sum+=n;//找到此单词后将此单词的查找次数加到sum中 
				break;
			}
			else {
				n++;//查找此数加一 
				p=p->next;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
void SqSearch_Linklist(Linklist L,char a[])//基于链表表的顺序查找 
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
		printf("平均查找长度: %.1f\n", get_aveSearchlength_Linklist(L2,word)); 
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//////二叉排序树
typedef struct BiTNode{
	Word data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
BiTree T;
int SearchBST_(BiTree &T,Word a,BiTree f,BiTree &p)
{                            //在二叉排序树中查找关键字等于a的元素
	if(!T){					//若查找成功，则指针p指向该数据元素结点并返回1,否则指针p指向查找路径上访问的最后一个结点并返回0,指针f指向T的双亲,其初始调用值为NULL 
        p=f;                             
		return 0;
	}
	else
		if(strcmp(T->data.s,a.s)==0){//判断是否有重复单词，没必要，因为单词已经筛选，不会出现重复单词 
			p=T;
			return 1;
		}
		else
			if(strcmp(T->data.s,a.s)>0) return SearchBST_(T->lchild,a,T,p);
			else       return SearchBST_(T->rchild,a,T,p);
}
BiTree Search_BiTree(BiTree T,char a[])//在二叉排序树中查找
								       //若查找成功，则返回该数据元素结点的指针，否则返回空指针
{
	if(T==NULL) return T;
	if(strcmp(T->data.s,a)==0) return T;
	else if(strcmp(T->data.s,a)>0) Search_BiTree(T->lchild,a);
	else if(strcmp(T->data.s,a)<0) Search_BiTree(T->rchild,a);
}
void InsertBST(BiTree &T,Word e)//插入到二叉排序树中 
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
void CreateBST(BiTree &T,Word a[],int n)//创建二叉排序树 ,n表示单词种类数 
{
	T=NULL;//初始为空树 
	int i=0;
	while(i<n){
		InsertBST(T,a[i]);
		i++;
	}
}
int n=0;
void mid(BiTree T,Word w[])//中序遍历二叉排序树 
{
	if(T!=NULL){
		mid(T->lchild,w);
		w[n++]=T->data;//中序遍历得到的单词结构体数组w[]即为按字典序排好的 
		mid(T->rchild,w);	
    }
} 
void print_BiTree(BiTree T,Word w[])//基于二叉排序树查找的词频统计 
{
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile4.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"单词总数%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w[i].s,w[i].number);

	fclose(fp);
}
float get_aveSearchlength_BiTree(BiTree T,Word w[])
{
	int sum=0;//总的查找次数 
	for(int i=0;i<word_count;i++){//遍历查找每个单词的查找次数 
		BiTree t=T;
		int n=1;
		while(t){
			if(strcmp(t->data.s,w[i].s)==0){
				sum+=n;//找到此单词后将此单词的查找次数加到sum中
				break;
			} 
			else if(strcmp(t->data.s,w[i].s)>0){
				n++;//查找次数加一 
				t=t->lchild;
			}
			else if(strcmp(t->data.s,w[i].s)<0){
				n++;//查找次数加一 
				t=t->rchild;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
 
void Search_BiTree2(char *s)//为了输出时间另外写的查找函数 
{
			int flag;
			BiTree q;
			start = clock();    /*  开始计时  */
			for(int i=0;i<=100000;i++){
				flag=0;
				q=Search_BiTree(T,s);
				if(q==NULL){ //查找失败 
					flag=1;
				}
			}
			stop = clock();     /*  停止计时  */
			double duration = ((double)(stop - start));// / CLK_TCK;
			if(flag==1) cout<<"查找失败"<<endl;
			else {
				printf("此单词的词频为: %d\n",q->data.number);
				printf("查找该单词所花的时间: %fms\n",duration);
				printf("平均查找长度: %.1f\n",get_aveSearchlength_BiTree(T,word));
			}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///哈希(散列表)查找----基于开放地址法的哈希查找----------- 
const int Table_size=6000; //哈希表长，当存储的单词种类过多时表长可相应增大 
typedef struct{
	Word *elem;//数组元素存储，动态分配数组 
	int  num;//当前数据元素的个数 
}HashTable; 
HashTable HT;
void Create_HashTable(HashTable &Ta)//创建哈希表 
{
	Ta.elem=(Word *)malloc(Table_size*sizeof(Word));
	Ta.num=0;
}
int Hash(char *p)//求哈希地址(除留余数法)  将字符串所有字母的ASCLL值相加对表长取余 
{
	int tmp=0;
	for(int i=0;p[i]!='\0';i++){
		tmp+=int(p[i]);
	}
	return tmp%Table_size;//返回字符串在哈希表中的位置下标 
}
void HashTable_Insert(HashTable &Ta,Word key)
{
	int tmpAdress=Hash(key.s);//得到哈希地址 
	while(Ta.elem[tmpAdress].s[0]!='\0'){  //冲突   while(Ta.elem[tmpAdress].s!='\0') ????
		tmpAdress=(++tmpAdress)%Table_size;//线性探测再散列 处理冲突 
	}
	strcpy(Ta.elem[tmpAdress].s,key.s);
	Ta.elem[tmpAdress].number=key.number; 
	Ta.num++;
 } 
float get_aveSearchlength_Hash(HashTable Ta,Word w[])
{
	int sum=0;//总的查找次数 
	for(int i=0;i<word_count;i++){//遍历查找每个单词的查找次数 
		int tmpAdress=Hash(w[i].s);
		int n=1;
		while(1){
			if(strcmp(Ta.elem[tmpAdress].s,w[i].s)==0){
				sum+=n;//找到此单词后将此单词的查找次数加到sum中
				break;
			} 
			else {
				n++;//查找次数加一 
				tmpAdress=(++tmpAdress)%Table_size;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
void Search_Hash(HashTable Ta,char *q)//哈希查找 
{
	int tmpAdress,flag;
	start = clock();       /*  开始计时  */
	for(int j=0;j<=100000;j++){
		flag=0;
		tmpAdress=Hash(q);
		while(strcmp(Ta.elem[tmpAdress].s,q)!=0){//当前位置不是q 
			if(Ta.elem[tmpAdress].s[0]=='\0'){
				flag=1;
				break;
			}
			tmpAdress=(++tmpAdress)%Table_size;//继续往下查找 
		}
	}
	stop = clock();           /*  停止计时  */
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(flag==1) cout<<"查找失败"<<endl;
	else {
		printf("此单词的词频为: %d\n",Ta.elem[tmpAdress].number);
		printf("查找该单词所花的时间: %fms\n",duration);
		printf("平均查找长度: %.1f\n",get_aveSearchlength_Hash(HT,word));
	}
}
void print_HashTable(HashTable Ta)//开放地址法哈希查找词频统计 
{
	Word w[5000];
	int n=0;
	for(int i=0;i<Table_size;i++){
		if(Ta.elem[i].s[0]>='a'&&Ta.elem[i].s[0]<='z'){  //if(Ta.elem[i].s=='\0')???
			w[n++]=Ta.elem[i];
		}
	}
	sort_Word(w);
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile5.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"单词总数%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w[i].s,w[i].number);

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///哈希(散列表)查找----基于链地址法的哈希查找-----------
typedef struct HashNode{
	Word elem;
	struct HashNode *next;
}HashNode,*HashList;
HashList HL[Table_size];
void Create_HashList(HashList &HL)//创建哈希链表 
{
	HL=(HashList)malloc(sizeof(HashNode));
	HL->next=NULL;
} 
void HashList_Insert(HashList HL[],Word a)//插入到哈希链表 
{
	int tmpAdress=Hash(a.s);//获取哈希地址 
	HashNode *p=HL[tmpAdress];
	while(p->next){
		p=p->next; 
	}
	HashNode *q=(HashList)malloc(sizeof(HashNode));
	q->elem=a;
	q->next=p->next;
	p->next=q;
}
float get_aveSearchlength_HashList(HashList HL[],Word w[])
{
	int sum=0;//总的查找次数 
	for(int i=0;i<word_count;i++){//遍历查找每个单词的查找次数 
		int tmpAdress=Hash(w[i].s);
		int n=1;
		HashNode *p=HL[tmpAdress]->next;
		while(p){
			if(strcmp(p->elem.s,w[i].s)==0){
				sum+=n;//找到此单词后将此单词的查找次数加到sum中
				break;
			} 
			else {
				n++;//查找次数加一 
				p=p->next;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
void Search_HashList(HashList HL[],char *s)//链式哈希查找 
{
	int tmpAdress,flag;
	HashNode *p;
	start = clock();   /*  开始计时  */
	for(int i=0;i<=100000;i++){
		tmpAdress=Hash(s);
		flag=0;
		p=HL[tmpAdress]->next;
		while(p){
			if(strcmp(p->elem.s,s)==0){ //查找到此单词 
				flag=1;
				break;
			}
			else p=p->next;
		}
	}
	stop = clock();     /*  停止计时  */
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(flag==0) cout<<"查找失败"<<endl;
	else {
		printf("此单词的词频为: %d\n",p->elem.number);
		printf("查找该单词所花的时间: %fms\n",duration);
		printf("平均查找长度: %.1f\n",get_aveSearchlength_HashList(HL,word));
	}
	
} 
void print_HashList(HashList HL[])//链地址法哈希查找词频统计 
{
	Word w[5000];
	int n=0; 
	for(int i=0;i<Table_size;i++){
		HashNode *p=HL[i]->next;
		while(p){
			w[n++]=p->elem;
			p=p->next;
		}
	}
	sort_Word(w);
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile6.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"单词总数%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w[i].s,w[i].number);

	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/////////////////////////设置界面 
void Interface1()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"1.基于线性表的查找"<<endl;
	cout<<"2.基于二叉排序树的查找"<<endl;
	cout<<"3.基于哈希表的查找"<<endl;
	cout<<"4.退出"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;//控制命令 
	cout<<endl;
}
void Interface2()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于线性表的查找————"<<endl; 
	cout<<"1.顺序查找"<<endl;
	cout<<"2.折半查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;
	cout<<endl;
}
void Interface3()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————顺序查找————"<<endl;
	cout<<"1.基于顺序表的顺序查找"<<endl;
	cout<<"2.基于链表的顺序查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;
	cout<<endl;
 }
void Interface4() 
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于顺序表的顺序查找————"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl; 
	cout<<"3.返回上一级"<<endl; 
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key; 
	cout<<endl;
 } 
 void Interface5() 
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于链表的顺序查找————"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl; 
	cout<<"3.返回上一级"<<endl; 
	cout<<"请按相应数字键进行选择"<<endl; 
	cin>>key;
	cout<<endl;
 } 
 void Interface6() 
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于顺序表的折半查找————"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl; 
	cout<<"3.返回上一级"<<endl; 
	cout<<"请按相应数字键进行选择"<<endl; 
	cin>>key;
	cout<<endl;
 } 
void Interface7()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于二叉排序树的查找————"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl; 
	cout<<"3.返回上一级"<<endl; 
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;
	cout<<endl;
}
void Interface8()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于哈希表的查找————"<<endl;
	cout<<"1.基于开放地址法的哈希查找"<<endl;
	cout<<"2.基于链地址法的哈希查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;
	cout<<endl;
 } 
 void Interface9()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于开放地址法的哈希查找————"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl; 
	cout<<"3.返回上一级"<<endl; 
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;
	cout<<endl;
}
 void Interface10()
{
	cout<<"/***基于不同策略的单词统计和检索系统***/"<<endl;
	cout<<"————基于链地址法的哈希查找————"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl; 
	cout<<"3.返回上一级"<<endl; 
	cout<<"请按相应数字键进行选择"<<endl;
	cin>>key;
	cout<<endl;
}
void choose1();
void choose2();
void choose3();
void choose4();
void choose5();
void choose6();
void choose7();
void choose8();
void choose9();
void choose10();

void choose1()
{
	Interface1();
	switch(key){
		case 1:
			choose2();
			break;
		case 2:
			choose3();
			break;
		case 3:
			choose4();
			break;
		case 4:
			exit(0);//执行退出命令 
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;
	}
}
void choose2()
{
	Interface2(); 
	switch(key){
		case 1:
			choose5();
			break;
		case 2:
			choose6(); 
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;		
	}
}
void choose5()
{
	Interface3();
	switch(key){
		case 1:
			choose7();
			break;
		case 2:
			choose8();
			break;
		case 3:
			choose2();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;		
	}
}
void choose7()
{
	Interface4();
	switch(key){
		case 1:
			print_SqList1(L);
			break;
		case 2:
			cout<<"请输入待查找单词:";
			char s[100];
			cin>>s;
			SqSearch_SqList(L,s);
			break;
		case 3:
			choose5();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;		
	}
}
void choose8()
{
	Interface5();
	switch(key){
		case 1:
			cout<<word_count<<endl;
			print_Linklist(L2);
			break;
		case 2:
			cout<<"请输入待查找单词:";
			char s[100];
			cin>>s;
			SqSearch_Linklist(L2,s);
			break;
		case 3:
			choose5();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;		
	}
}
void choose6()
{
	Interface6();
	switch(key){
		case 1:
			print_SqList2(L);
			break;
		case 2:
			cout<<"请输入待查找单词:";
			char s[100];
			cin>>s;
			HalfSearch_SqList(L,s);
			break;
		case 3:
			choose2();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;
		}
}
void choose3()
{
	Interface7();
	switch(key){
		case 1:
			Word w2[5000];
			mid(T,w2);
			print_BiTree(T,w2);
			break;
		case 2:
		cout<<"请输入待查找单词:";
			char s[100];
			cin>>s;
			Search_BiTree2(s);
			break;
		case 3:
			choose2();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;
		}
}
void choose4()
{
	Interface8();
	switch(key){
		case 1:
			choose9();
			break;
		case 2:
			choose10();
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;
		}
}
void choose9()
{
	Interface9();
	switch(key){
		case 1:
			print_HashTable(HT);
			break;
		case 2:
			cout<<"请输入待查找单词:";
			char s[100];
			cin>>s;
			Search_Hash(HT,s);
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;
		}
}
void choose10()
{
	Interface10();
	switch(key){
		case 1:
			print_HashList(HL);
			break;
		case 2:
			cout<<"请输入待查找单词:";
			char s[100];
			cin>>s;
			Search_HashList(HL,s);
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"输入命令错误"<<endl;
			break;
		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	FILE *fp=fopen("D://test.txt","r+");
	if(fp==NULL){
		cout<<"不能打开";
		exit(1);	
	}
	int count,n=0,num;
	char ch;
	while((ch=fgetc(fp))!=EOF){
		s[count++]=ch;//将文件中的所有字符提取到字符数组s中，实际上没必要 
	}
	fclose(fp);//关闭文件 
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
	count=0;//记录单词的种类数 
	for(int i=0;i<num;i++){
		int x=0,flag=0;
		if(w[i][0]>='a'&&w[i][0]<='z'){
			for(x=0;x<count;x++){
				if(strcmp(word[x].s,w[i])==0){
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
	word_count=count;
	Init_SqList(L);
	for(int i=0;i<count;i++){
		SqList_Insert(L,word[i]);
	} 	
	Init_Linklist(L2);
	for(int i=0;i<count;i++){
		Linklist_Insert(L2,word[i]);
	}
	CreateBST(T,word,count);
	Create_HashTable(HT);
	for(int i=0;i<count;i++){
		HashTable_Insert(HT,word[i]);
	}
	for(int i=0;i<Table_size;i++){
		Create_HashList(HL[i]);
	} 
	for(int i=0;i<count;i++){
		HashList_Insert(HL,word[i]);
	}
	choose1();//进入选择界面 
	return 0;
}

