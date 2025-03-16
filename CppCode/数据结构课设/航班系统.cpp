#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int flight_count=0;
typedef struct{
	char  flight_no[100];  //�����
	char  start_time[100]; //���ʱ��
	char  end_time[100];   //����ʱ��
	char  start_city[100]; //��ɳ���
	char  end_city[100];   //�������
	char  fare[100];            //Ʊ�� 
	char  fare_discount[100];   //�ۿ�Ʊ�� 
	int   is_full;    //�Ƿ�����,ʣ��Ʊ
}Flight;
Flight Fl[500]; 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Printf()//ͳ�����к�����Ϣ
{
	FILE *fp=fopen("D:/flight.txt","r+");
	if(fp==NULL){
		cout<<"���ܴ�";
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
				if(s[i+1]!='\0')//����֮��
				Fl[flight_count].is_full=Fl[flight_count].is_full*10+(s[i]-'0');
			}
		}
		flight_count++;//������һ���������Ϣ 
	}
	fclose(fp);
}
void Input()//¼�뺽����Ϣ
{
	FILE *fp;
	if ( (fp = fopen("d:\\flight.txt", "a")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }
	cout<<"����������Ҫ¼��ĺ���ĺ���ţ���ʱ�䣬��ɵִ���У�����Ʊ�ۣ�Ʊ���ۿۣ������Ƿ�����(�Կո�Ϊ���):"<<endl;
	char s1[1000];
	cin>>s1;
    fputs(s1,fp);
	fclose(fp);
	Printf();
}
void Search_Fno()//������Ų���
{
	cout<<"������Ҫ��ѯ�ĺ����:"<<endl;
	char s[100];
	cin>>s;
	int i;
	for(i=0;i<flight_count;i++){
		if(strcmp(s,Fl[i].flight_no)==0){
			cout<<"�˺�����ʱ��:"<<Fl[i].start_time<<" "<<Fl[i].end_time<<endl;
			cout<<"�˺����𽵳���:"<<Fl[i].start_city<<" "<<Fl[i].end_city<<endl;
			cout<<"�˺���Ʊ��:"<<Fl[i].flight_no<<endl;
			cout<<"�˺����ۿ�Ʊ��:"<<Fl[i].fare_discount<<endl;
			cout<<"�˺����λ���(ʣ��Ʊ��):"<<Fl[i].is_full<<endl;
			break;
		}
	}
	if(i==flight_count) cout<<"�鲻���˺���."<<endl;
}
void Search_City()//���𽵳��в���
{
	cout<<"������Ҫ��ѯ������𽵳���:"<<endl;
	char s1[100],s2[100];
	cin>>s1>>s2;
	int i;
	int n=0;
	for(i=0;i<flight_count;i++){
		if(strcmp(s1,Fl[i].start_city)==0 && strcmp(s2,Fl[i].end_city)==0){
			cout<<"��ѯ������"<<(++n)<<":"<<endl;
			cout<<"�˺��ຽ���:"<<Fl[i].flight_no<<endl;
			cout<<"�˺�����ʱ��:"<<Fl[i].start_time<<" "<<Fl[i].end_time<<endl;
			cout<<"�˺���Ʊ��:"<<Fl[i].flight_no<<endl;
			cout<<"�˺����ۿ�Ʊ��:"<<Fl[i].fare_discount<<endl;
			cout<<"�˺����λ���(ʣ��Ʊ��):"<<Fl[i].is_full<<endl;
		}
	}
	if(n==0) cout<<"�鲻���˺���."<<endl;
}
struct Book{
	char Pname[100];//�ͻ�����
	char P_no[100];//�ͻ�֤����
	char Fno[100];//��������
};
Book book[50000];//�������±��ʾ������
int book_count=0;//������
void Order()//��Ʊ
{
	char s1[100],s2[100],s3[10];
	cout<<"���������붩Ʊ�ͻ�������,֤����,��Ʊ�����:"<<endl;
	cin>>s1>>s2>>s3;
	for(int i=0;i<flight_count;i++){
		if(strcmp(s3,Fl[i].flight_no)==0){
			if(Fl[i].is_full==0){
				cout<<"�˺���Ʊ������."<<endl;
				int n=0;
				for(int j=0;j<flight_count;j++){
					if(strcmp(Fl[i].start_city,Fl[j].start_city)==0 && strcmp(Fl[i].end_city,Fl[j].end_city)==0 && Fl[j].is_full>0){
						cout<<"Ϊ���Ƽ�����"<<(++n)<<":"<<endl;
						cout<<"�˺����:"<<Fl[j].flight_no<<endl;
						cout<<"�˺�����ʱ��:"<<Fl[j].start_time<<" "<<Fl[j].end_time<<endl;
						cout<<"�˺����𽵳���:"<<Fl[j].start_city<<" "<<Fl[j].end_city<<endl;
						cout<<"�˺���Ʊ��:"<<Fl[j].flight_no<<endl;
						cout<<"�˺����ۿ�Ʊ��:"<<Fl[j].fare_discount<<endl;
						cout<<"�˺����λ���(ʣ��Ʊ��):"<<Fl[j].is_full<<endl;
					}
				}
				if(n==0)  cout<<"û�з���������������."<<endl;
			}
			else {
				Fl[i].is_full--;//��Ʊ��1
				book_count++;//������+1����������
				strcpy(book[book_count].Pname,s1);
				strcpy(book[book_count].P_no,s2);
				strcpy(book[book_count].Fno,s3);
				cout<<"��Ʊ�ɹ�."<<endl;
			}
		}
	}
}
void Retire()//��Ʊ
{
	cout<<"������Ҫ��Ʊ�Ķ�����"<<endl;
	int n;
	cin>>n;
	if(n<1||n>book_count) cout<<"���޴˵���."<<endl;
	else if(book[n].Fno[0]=='\0') cout<<"�˶������˶�."<<endl;
	else {
		for(int i=0;i<flight_count;i++){
			if(strcmp(book[n].Fno,Fl[i].flight_no)==0){
				Fl[i].is_full++;//��Ʊ����Ʊ��1
				book[n].Pname[0]='\0';//��Ʊ����Ϣ����
				book[n].P_no[0]='\0';
				book[n].Fno[0]='\0';
				cout<<"�˶��ɹ�."<<endl;
				break;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void interface1()
{
	cout<<"1.¼��"<<endl;
	cout<<"2.��ѯ"<<endl;
	cout<<"3.��Ʊ"<<endl;
	cout<<"4.��Ʊ"<<endl;
	cout<<"5.�˳�"<<endl;
	cout<<"�밴��Ӧ��ѡ��........."<<endl;

}
void interface2()
{
	cout<<"1.���պ���Ų���."<<endl;
	cout<<"2.�����𽵳��в���."<<endl;
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
				cout<<"����������������������."<<endl;
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



