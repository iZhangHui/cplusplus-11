#include <iostream>

class B1 {
public:
	~B1() { std::cout << "~B1()" << std::endl; }
};

class D1 : public B1 {
public:
	D1() : data(new char[16]) { }
	~D1() { std::cout << "~D1()" << std::endl; delete[] data; }
private:
	char* data;
};

class B2 {
public:
	B2() { std::cout << "B2()" << std::endl; }
	virtual ~B2() { std::cout << "~B2()" << std::endl; }
};

class D2 : public B2 {
public:
	D2() : data(new char[16]) { std::cout << "D2()" << std::endl; }
	virtual ~D2() { std::cout << "~D2()" << std::endl; delete[] data; }
private:
	char* data;
};

int main() {

	B1* p1 = new D1;
	delete p1;
	std::cout << std::endl;

	B2* p2 = new D2;
	delete p2;

	std::cout << "===============" << std::endl;
	return 0;
}

/*
**在这个例子中，B1和D1没有使用虚析构函数，这样的话 delete p1 时只会调用 B1 的析构函数，D1 的析构函数不会被调用，
**于是D1中的 data 就不会被delete，产生了内存泄露。
** B2 和 D2 由于加了 virtual，于是 delete p2 时会先后调用B2和D2的析构函数，这样就能够正确地析构对象。
*/
