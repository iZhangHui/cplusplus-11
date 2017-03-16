#include <iostream>
#include <stdlib.h>
#include <string.h>

/*
*局部重载new和delete（可以使用成员函数和友元函数两种方式重载）
*
*使用new分配某个重载了new的累的对象空间时，先调用new的重载函数,
*再调用该类的构造函数，如果该类的构造函数有参数要求，则必须给出对应的实参。
*
*使用了delete释放某个重载了delete的累的对象空间时，先调用类的析构函数,
*然后再调用重载的delete函数。
*/

using namespace std;

class Foo
{
friend ostream& operator<<(ostream&, const Foo&);
public:
	Foo(int a,int b,int c);
	~Foo() { cout << "Destructing" << endl; }
	void *operator new(size_t size);
	void operator delete(void* p);
private:
	int x,y,z;
};

Foo::Foo(int a,int b,int c) : x(a), y(b), z(c)
{
	cout << "Constructing" << endl;;
}

void* Foo::operator new(size_t size)
{
	cout << "in Foo new" << endl;
	return new char[size];
}

void Foo::operator delete(void* p)
{
	cout << "in Foo delete" << endl;
	delete [] static_cast<char*>(p);
}

ostream& operator<<(ostream& os, const Foo& obj)
{
	os << obj.x << ",";
	os << obj.y << ",";
	os << obj.z << "\n";
	return os;
}

int main(int argc,char *argv[])
{
	try {
		Foo* p1 = new Foo(1,2,3);
		Foo* p2 = new Foo(4,5,6);

		cout << *p1 << *p2;
		delete p1;
		delete p2;

	} catch(bad_alloc &memExp) {
		cerr << memExp.what() << endl;
		abort();
	}

	cout << "=====================" << endl;

	int* pnum = new int(10);

	cout << "num = " << *pnum << endl;
	delete pnum;
	cout << "Application Run Successfully!" << endl;
	return 0;
}