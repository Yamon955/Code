#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Person {
	int a, b;

	//ȫ�ֺ���ʵ�ֵ��������������Ϊ�����Ԫ������ʹ����Է�������˽�����ݳ�Ա
	//friend Person operator+(Person& p1, Person& p2);
	//friend Person operator+(Person& p1, int val);
	friend ostream& operator<<(ostream& out, Person& p);
	//friend Person& operator++(Person& p);
	//friend Person operator++(Person& p , int);

public:
	Person() {
		//cout << "���ÿղι��캯��" << endl;
	}
	Person(int a, int b) {
		this->a = a;
		this->b = b;
		//cout << "���ù��캯��" << endl;
	}
	Person(const Person& p) { //���鿽�����캯������ const ,������ʱ������Ϊ�������캯���Ĳ���ʱ�ᱨ�� ���� Person p = Person(Person(a,b))   https://www.coder.work/article/30400
		this->a = p.a;
		this->b = p.b;
		//cout << "���ÿ������캯��" << endl;
	}
	//https://blog.csdn.net/weixin_43734095/article/details/104465307  ���ĺܺ� 
	// ʵ�� p1 + p2
	Person operator+(Person& p) { //����ʹ�� ����& ������Ϊ�βΣ���ʵ�δ��ݸ��β�ʱ������һ�ο������캯��
		Person tmp;
		tmp.a = a + p.a;
		tmp.b = b + p.b;
		return tmp;
	}
	//ʵ�� p1 + (int)
	Person operator+(int val) {
		Person tmp;
		tmp.a = a + val;
		tmp.b = b + val;
		return tmp;
	}
	// ��Ա�����޷����� << ��������� ʵ������Զ�����������
	//ostream& operator<<(ostream& out) {
	//	out << "a = " << a << " b = " << b << endl;
	//	return out;
	//}

	//ʵ��ǰ������ ++p   ���� ���� ������Ϊ��һֱ��һ�����ݽ��е��� ++(++a)
	Person& operator++() {
		//�� ++
		a++; b++;
		//�ٷ���
		return *this;
	}
	//ʵ�ֺ������� p++
	Person operator++(int) {
		//�ȷ��� (��¼��ǰֵ)
		Person tmp = *this;
		//�� ++
		a++; b++;
		return tmp;
	}
	//���� ��ֵ= ����� ----> ���� �ǳ�������� ��ָ�����⣬�ڶ����ɳ���Ա���ٺ��ͷţ�ǳ�������ܵ����ظ��ͷ�ĳһ�������ռ䡿
	/*
		Person p = p1 		//��ʼ��ʱ  ���ÿ������캯��  
		Person p2;
		p2 = p1;            //������ֵ����ʱ���������صĸ�ֵ�����
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
		//cout << "������������" << endl;
	}
	void print() {
		cout << a << " " << b << endl;
	}
};

//ֻ����ȫ�ֺ���ʵ����������
ostream& operator<<(ostream& out, Person& p) {
	out << setw(20) << "a = " << p.a << " b = " << p.b << endl;
	return out;
}
/*
//Ҳ��ʹ��ȫ�ֺ���ʵ����������أ������ڡ�ȫ�ֺ�����ʵ������������أ����ȵ������ڵ���������غ���
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
	//���أ�����������Ҳ��Ϊ�º���
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
	//�����������
	cout << "myadd()(20,20) = " << myadd()(20, 20) << endl;

	cout << "add(\"hello world\") = ";
	add("hello world");

}
