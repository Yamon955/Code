#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int flight_count=0;
typedef struct{
	char  flight_no[100];  //航班号
	char  start_time[100]; //起飞时间
	char  end_time[100];   //降落时间
	char  start_city[100]; //起飞城市
	char  end_city[100];   //降落城市
	char  fare[100];            //票价 
	char  fare_discount[100];   //折扣票价 
	int   is_full;    //是否满仓,剩余票
}Flight;
Flight Fl[500]; 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Printf()//统计所有航班信息
{
	FILE *fp=fopen("D:/flight.txt","r+");
	if(fp==NULL){
		cout<<"不能打开";
		exit(1);	
	}
	flight_count=0;
	char s[1000]; 
	while(fgets(s,1000,fp)!=0){
		int n=0,m=0;
		for(int i=0;s[i];i++){
			if(s[i]==' ') {
				n++;
				m=0;
			}
			else if(n==0){
				Fl[flight_count].flight_no[m++]=s[i];
			}
			else if(n==1){
				Fl[flight_count].start_time[m++]=s[i];
			}
			else if(n==2){
				Fl[flight_count].end_time[m++]=s[i];
			}
			else if(n==3){
				Fl[flight_count].start_city[m++]=s[i];
			}
			else if(n==4){
				Fl[flight_count].end_city[m++]=s[i];
			}
			else if(n==5){
				Fl[flight_count].fare[m++]=s[i];
			}
			else if(n==6){
				Fl[flight_count].fare_discount[m++]=s[i];
			}
			else if(n==7){
				if(s[i+1]!='\0')//无奈之举
				Fl[flight_count].is_full=Fl[flight_count].is_full*10+(s[i]-'0');
			}
		}
		flight_count++;//输入下一条航班的信息 
	}
	fclose(fp);
}
void Input()//录入航班信息
{
	FILE *fp;
	if ( (fp = fopen("d:\\flight.txt", "a")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }
	cout<<"请依次输入要录入的航班的航班号，起降时间，起飞抵达城市，航班票价，票价折扣，航班是否满仓(以空格为间隔):"<<endl;
	char s1[1000];
	cin>>s1;
    fputs(s1,fp);
	fclose(fp);
	Printf();
}
void Search_Fno()//按航班号查找
{
	cout<<"请输入要查询的航班号:"<<endl;
	char s[100];
	cin>>s;
	int i;
	for(i=0;i<flight_count;i++){
		if(strcmp(s,Fl[i].flight_no)==0){
			cout<<"此航班起降时间:"<<Fl[i].start_time<<" "<<Fl[i].end_time<<endl;
			cout<<"此航班起降城市:"<<Fl[i].start_city<<" "<<Fl[i].end_city<<endl;
			cout<<"此航班票价:"<<Fl[i].flight_no<<endl;
			cout<<"此航班折扣票价:"<<Fl[i].fare_discount<<endl;
			cout<<"此航班仓位情况(剩余票数):"<<Fl[i].is_full<<endl;
			break;
		}
	}
	if(i==flight_count) cout<<"查不到此航班."<<endl;
}
void Search_City()//按起降城市查找
{
	cout<<"请输入要查询航班的起降城市:"<<endl;
	char s1[100],s2[100];
	cin>>s1>>s2;
	int i;
	int n=0;
	for(i=0;i<flight_count;i++){
		if(strcmp(s1,Fl[i].start_city)==0 && strcmp(s2,Fl[i].end_city)==0){
			cout<<"查询到航班"<<(++n)<<":"<<endl;
			cout<<"此航班航班号:"<<Fl[i].flight_no<<endl;
			cout<<"此航班起降时间:"<<Fl[i].start_time<<" "<<Fl[i].end_time<<endl;
			cout<<"此航班票价:"<<Fl[i].flight_no<<endl;
			cout<<"此航班折扣票价:"<<Fl[i].fare_discount<<endl;
			cout<<"此航班仓位情况(剩余票数):"<<Fl[i].is_full<<endl;
		}
	}
	if(n==0) cout<<"查不到此航班."<<endl;
}
struct Book{
	char Pname[100];//客户姓名
	char P_no[100];//客户证件号
	char Fno[100];//乘坐航班
};
Book book[50000];//用数组下标表示订单号
int book_count=0;//订单数
void Order()//订票
{
	char s1[100],s2[100],s3[10];
	cout<<"请依次输入订票客户的姓名,证件号,订票航班号:"<<endl;
	cin>>s1>>s2>>s3;
	for(int i=0;i<flight_count;i++){
		if(strcmp(s3,Fl[i].flight_no)==0){
			if(Fl[i].is_full==0){
				cout<<"此航班票已售完."<<endl;
				int n=0;
				for(int j=0;j<flight_count;j++){
					if(strcmp(Fl[i].start_city,Fl[j].start_city)==0 && strcmp(Fl[i].end_city,Fl[j].end_city)==0 && Fl[j].is_full>0){
						cout<<"为你推荐航班"<<(++n)<<":"<<endl;
						cout<<"此航班号:"<<Fl[j].flight_no<<endl;
						cout<<"此航班起降时间:"<<Fl[j].start_time<<" "<<Fl[j].end_time<<endl;
						cout<<"此航班起降城市:"<<Fl[j].start_city<<" "<<Fl[j].end_city<<endl;
						cout<<"此航班票价:"<<Fl[j].flight_no<<endl;
						cout<<"此航班折扣票价:"<<Fl[j].fare_discount<<endl;
						cout<<"此航班仓位情况(剩余票数):"<<Fl[j].is_full<<endl;
					}
				}
				if(n==0)  cout<<"没有符合您的其他航班."<<endl;
			}
			else {
				Fl[i].is_full--;//余票减1
				book_count++;//订单数+1，即订单号
				strcpy(book[book_count].Pname,s1);
				strcpy(book[book_count].P_no,s2);
				strcpy(book[book_count].Fno,s3);
				cout<<"订票成功."<<endl;
			}
		}
	}
}
void Retire()//退票
{
	cout<<"请输入要退票的订单号"<<endl;
	int n;
	cin>>n;
	if(n<1||n>book_count) cout<<"查无此单号."<<endl;
	else if(book[n].Fno[0]=='\0') cout<<"此订单已退订."<<endl;
	else {
		for(int i=0;i<flight_count;i++){
			if(strcmp(book[n].Fno,Fl[i].flight_no)==0){
				Fl[i].is_full++;//退票，余票加1
				book[n].Pname[0]='\0';//退票后信息重置
				book[n].P_no[0]='\0';
				book[n].Fno[0]='\0';
				cout<<"退订成功."<<endl;
				break;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void interface1()
{
	cout<<"1.录入"<<endl;
	cout<<"2.查询"<<endl;
	cout<<"3.订票"<<endl;
	cout<<"4.退票"<<endl;
	cout<<"5.退出"<<endl;
	cout<<"请按相应键选择........."<<endl;

}
void interface2()
{
	cout<<"1.按照航班号查找."<<endl;
	cout<<"2.按照起降城市查找."<<endl;
}
void choose1()
{
	    int key;
		interface1();
		cin>>key;
		switch (key){
			case 1:
				Input();
				break;
			case 2:
				interface2();
				int key2;
				cin>>key2;
				switch (key2)
				{
					case 1:
						Search_Fno();
						break;
					case 2:
						Search_City();
						break;
					default:
						break;
				}
				break;
            case 3:
				Order();
				break;
			case 4:
				Retire();
				break;
			case 5:
			    exit(0);
				break;
			default:
				cout<<"输入命令有误，请重新输入."<<endl;
				break;
		}
}
int main()
{
	Printf();
	while(1){
		choose1();
	}
	return 0;
 } 
/*
10085 07:35 11:00 Qingdao HongKong 916.3 733.04 82
10086 07:50 08:37 Qingdao Beijing 588 470.4 0
10087 08:00 19:57 Qingdao NewYork 1699 1359.2 0
10088 08:35 11:12 Qingdao Guangzhou 879.6 703.68 0
10089 08:42 10:12 Qingdao Wuhan 643.9 515.12 12
10090 10:00 19:57 Qingdao NewYork 1699 1359.2 15
10091 10:12 12:56 Qingdao Wuhan 643.5 515.12 0
10092 11:50 12:37 Qingdao Beijing 588 470.4 15

*/ 



