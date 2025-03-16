//HDU 2072
#include <iostream>
#include <string>
#include <set>
#include<sstream>
 
using namespace std;
 
set<string> words;  //set集合会自动去重
 
int main(){
	string row,ptr;
 
	//getline(cin,row) 用row来保存一行的内容
	while(getline(cin,row)&&row!="#"){
 
		words.clear();
 
		//定义一个stringstream类型的对象
		stringstream str(row);
 
		//这道题要考虑前面有N个空格，中间有N个空格，后面也有N个空格....然后就是输入空格....
		//str >> input 给input赋值
		while(str >> ptr){
			words.insert(ptr);
		}
 
 
		cout<<words.size()<<endl;
	}
 
	return 0;
}
/*
you are my friend
#
Sample Output
4
*/