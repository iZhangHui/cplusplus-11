#include <iostream>

using namespace std;

class Foo {
private:
	int i;
	// int j;
};

int main(int argc, char const *argv[])
{
	cout << sizeof(char) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(unsigned) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << "###################" << endl;

	cout << sizeof(uint32_t) << endl;
	cout << sizeof(uint64_t) << endl;

	cout << "===================" << endl;
	cout << sizeof(Foo) << endl;
	Foo foo;
	cout << sizeof(foo) << endl;
	Foo& ref = foo;
	cout << sizeof(ref) << endl;
	Foo* ptr = new Foo();
	cout << sizeof(ptr) << endl;

	return 0;
}
