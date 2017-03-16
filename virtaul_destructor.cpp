#include <iostream>

class A1 {
public:
	~A1() { std::cout << "~A1()" << std::endl; }
};
class B1 : public A1 {
public:
	B1() : data(new char[16]) { }
	~B1() { std::cout << "~B1()" << std::endl; delete[] data; }
private:
	char* data;
};

class A2 {
public:
	A2() { std::cout << "A2()" << std::endl; }
	virtual ~A2() { std::cout << "~A2()" << std::endl; }
};
class B2 : public A2 {
public:
	B2() : data(new char[16]) { std::cout << "B2()" << std::endl; }
	virtual ~B2() { std::cout << "~B2()" << std::endl; delete[] data; }
private:
	char* data;
};

int main() {

	A1* p1 = new B1;
	delete p1;
	std::cout << std::endl;

	A2* p2 = new B2;
	delete p2;

	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	return 0;
}

/*
**在这个例子中，A1和B1没有使用虚析构函数，这样的话 delete p1 时只会调用 A1 的析构函数，B1的析构函数不会被调用，
**于是B1中的 data 就不会被delete，产生了内存泄露。
**A2和B2由于加了 virtual，于是 delete p2 时会先后调用B2和A2的析构函数，这样就能够正确地析构对象。
*/
