#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Person {
	int a, b;

	//全局函数实现的运算符重载声明为类的友元函数，使其可以访问类内私有数据成员
	//friend Person operator+(Person& p1, Person& p2);
	//friend Person operator+(Person& p1, int val);
	friend ostream& operator<<(ostream& out, Person& p);
	//friend Person& operator++(Person& p);
	//friend Person operator++(Person& p , int);

public:
	Person() {
		//cout << "调用空参构造函数" << endl;
	}
	Person(int a, int b) {
		this->a = a;
		this->b = b;
		//cout << "调用构造函数" << endl;
	}
	Person(const Person& p) { //建议拷贝构造函数加上 const ,否则当临时对象作为拷贝构造函数的参数时会报错 例： Person p = Person(Person(a,b))   https://www.coder.work/article/30400
		this->a = p.a;
		this->b = p.b;
		//cout << "调用拷贝构造函数" << endl;
	}
	//https://blog.csdn.net/weixin_43734095/article/details/104465307  讲的很好 
	// 实现 p1 + p2
	Person operator+(Person& p) { //若不使用 引用& 类型作为形参，则实参传递给形参时会多调用一次拷贝构造函数
		Person tmp;
		tmp.a = a + p.a;
		tmp.b = b + p.b;
		return tmp;
	}
	//实现 p1 + (int)
	Person operator+(int val) {
		Person tmp;
		tmp.a = a + val;
		tmp.b = b + val;
		return tmp;
	}
	// 成员函数无法重载 << 左移输出符 实现输出自定义数据类型
	//ostream& operator<<(ostream& out) {
	//	out << "a = " << a << " b = " << b << endl;
	//	return out;
	//}

	//实现前置自增 ++p   返回 引用 类型是为了一直对一个数据进行递增 ++(++a)
	Person& operator++() {
		//先 ++
		a++; b++;
		//再返回
		return *this;
	}
	//实现后置自增 p++
	Person operator++(int) {
		//先返回 (记录当前值)
		Person tmp = *this;
		//再 ++
		a++; b++;
		return tmp;
	}
	//重载 赋值= 运算符 ----> 存在 深、浅拷贝问题 【指针问题，在堆区由程序员开辟和释放，浅拷贝可能导致重复释放某一个堆区空间】
	/*
		Person p = p1 		//初始化时  调用拷贝构造函数  
		Person p2;
		p2 = p1;            //单纯赋值运算时，调用重载的赋值运算符
	*/
	Person& operator=(Person &p) {     
		a = p.a;
		b = p.b;
		return *this;
	}
	bool operator==(Person& p) {
		if (a == p.a && b == p.b) return true;
		else return false;
	}
	bool operator!=(Person& p) {
		if (a != p.a || b != p.b) return true;
		else return false;
	}
	~Person() {
		//cout << "调用析构函数" << endl;
	}
	void print() {
		cout << a << " " << b << endl;
	}
};

//只能由全局函数实现左移重载
ostream& operator<<(ostream& out, Person& p) {
	out << setw(20) << "a = " << p.a << " b = " << p.b << endl;
	return out;
}
/*
//也可使用全局函数实现运算符重载，若类内、全局函数均实现了运算符重载，优先调用类内的运算符重载函数
Person operator+(Person& p1, Person& p2) {
	Person tmp;
	tmp.a = p1.a + p2.a;
	tmp.b = p1.b + p2.b;
	return tmp;

}
Person operator+(Person& p1, int val) {
	Person tmp;
	tmp.a = p1.a + val;
	tmp.b = p1.b + val;
	return tmp;
}
ostream& operator<<(ostream& out, Person& p) {
	out << "a = " << p.a << " b = " << p.b << endl;
	return out;
}
Person& operator++(Person& p) {
	p.a++; p.b++;
	return p;
}
Person operator++(Person& p, int) {
	Person tmp = p;
	p.a++; p.b++;
	return tmp;
}

*/

class myadd {
public:
	//重载（）操作符，也称为仿函数
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
	void operator()(string s) {
		cout << s << endl;
	}
};
int main()
{
	Person p1(1, 1), p2(2, 2);
	cout << "p1 " << p1;
	cout << "p2 " << p2;
	Person p3 = p1 + p2;
	cout << "p3 = p1 + p2 " << p3;
	Person p4 = p1 + 2;
	cout << "p4 = p1 + 2 " << p4;
	Person p5 = p1++;
	cout << "p5 = p1++ " << p5;
	cout << "p1 " << p1;
	Person p6 = ++p1;
	cout << "p6 = ++p1" << p6;
	cout << "p1 " << p1;

	if (p1 != p2) cout << "p1 != p2" << endl;
	else cout << "p1 == p2" << endl;

	p2 = p1;
	if (p1 == p2) cout << "p1 == p2" << endl;
	else cout << "p1 != p2" << endl;

	myadd add;
	int ans = add(10, 10);
	cout << "ans = add(10, 10) = " << ans << endl;
	//匿名对象调用
	cout << "myadd()(20,20) = " << myadd()(20, 20) << endl;

	cout << "add(\"hello world\") = ";
	add("hello world");

}
