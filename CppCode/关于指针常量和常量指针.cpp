#include<iostream>
using namespace std;
/*
好多人认为
	常量指针是指向常量的指针，指针常量就是指针本身就是常量。
*/

int main() {

	const int a = 10;
	const int b = 11;

	const int *p = &a; //指向常量的指针（pointer to const)  p is a pointer to const int
	p = &b;            //指向可以变
	//*p = 5;          //error, 试图改变指针所指常量的值

	int c = 12;
	int d = 13;

	int* const q = &c; //常量指针(const pointer)            q is a const pointer to int  ---- 即指针本身是常量
	*q = 10;           //指向内容可以变
	//q = &d;          //指针本身为常量不可改变



	return 0;
}