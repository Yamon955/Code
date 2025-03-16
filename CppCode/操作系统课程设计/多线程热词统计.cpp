//Linux
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<map>
#include<string>
#include<cstring>
#include<dirent.h>
#include<vector>
#include<thread>
#include<iomanip>
#include<cmath>
#include<queue>
#include<pthread.h>
#include <sys/types.h>
#include <errno.h>
using namespace std;
map<string,int>mp;
char dir[300];
int cnt = 0;
vector<string>allFileName;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
struct node{
	string s;
	int cnt;
	node(string tmps,int tmpcnt){
		s=tmps;
		cnt=tmpcnt;
	}
	bool operator<(const node& a)const{
		return cnt<a.cnt;
	}
};
priority_queue<node>q;
void *f1(const char* file,string str)
{
	FILE *f = fopen(file,"r");
	if(f==NULL){
		cout<<"打开失败"<<endl;
		exit(-1);
	}
	char c;
	int i=0;
	string word="";
	c=fgetc(f);
	while(c!=EOF){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
			word += c;
		}
		else{
			if(word==""){
				c=fgetc(f);
				continue;
			}
			mp[word]++;
			word="";
		}
		c=fgetc(f);
	}
	fclose(f);
	cout<<"单词总数为:"<<mp[str]<<endl;

}
vector<string> getFilesList(string dirpath){
    DIR *dir=opendir(dirpath.c_str());
    if(dir==NULL){
        cout<<"opendir error"<<endl;
    }
 
    vector<string> allPath;
    struct dirent *entry;
    while((entry=readdir(dir))!=NULL){
        if(entry->d_type==DT_DIR){//It's dir
            if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0) 
                continue;
            string dirNew=dirpath+"/"+entry->d_name;
            vector<string> tempPath = getFilesList(dirNew);
            allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
        }else{
            string name = entry->d_name;
            string imgdir = dirpath +"/"+ name;
            if(name[name.size()-1]=='t' && name[name.size()-2]=='x' && name[name.size()-3]=='t' && name[name.size()-4]=='.') //判断txt文件，会发现有一个不是txt文件
                allPath.push_back(imgdir);
        }
    }
    closedir(dir);
    return allPath;
}
void *MyThread(void *arg)
{
	pthread_mutex_lock(&mutex);
	FILE *f=fopen(allFileName[cnt++].c_str(),"r");
	cout<<allFileName[cnt-1].c_str()<<" "<<cnt<<endl;//输出所有文件
	if(f==NULL){
		cout<<"打开失败"<<endl;
		exit(-1);
	}
	pthread_mutex_unlock(&mutex);
	char c;
	string word="";
	c=fgetc(f);
	while(c!=EOF){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
		{
			word+=c;
		}
		else
		{
			if(word=="")
			{
				c=fgetc(f);
				continue;
			}
			while(pthread_mutex_lock(&mutex)!=0);
			mp[word]++;
			word="";
			pthread_mutex_unlock(&mutex);
		}
		c=fgetc(f);
	}
	fclose(f);
}





int main()
{
	cout<<"1.统计单词词频"<<endl;
	cout<<"2.统计小说中的热词及其出现次数"<<endl;
	cout<<"intput 1 or 2:"<<endl;
	string s1,s2;
	int op;
	cin>>op;
	if(op==1){
		cout<<"输入路径"<<endl;
		cin>>s1;
		cout<<"输入要统计词频的单词"<<endl;
		cin>>s2;
		f1(s1.c_str(),s2);
	}
	else {
		string Path;
		cout<<"输入路径"<<endl;
		cin>>dir;
		allFileName=getFilesList(dir);
		cout<<"该路径下文件总数为:"<<allFileName.size()<<endl;
		pthread_t myt[allFileName.size()+1];
		int j = 0;
		for(int i=0;i<allFileName.size();i++){
			while(pthread_create(&myt[i],NULL,MyThread,NULL)!=0);//循环直到创建成功
			if(i%500==0||i==allFileName.size()-1){ //避免线程申请过多而导致后序的申请不到
				for(;j<i;j++){
					pthread_join(myt[j],NULL);
				}
			}
		}
		map<string,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
			q.push(node(it->first,it->second));
		for(int i=1;i<=10;i++){
			cout<<i<<".\t"<<q.top().s<<"\t"<<q.top().cnt<<endl;
			q.pop();
		}

	}
	return 0;
}

