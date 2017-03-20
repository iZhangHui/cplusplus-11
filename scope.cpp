#include <iostream>

using std::cout;
using std::endl;

class Base {
public:
	Base(): mem(0) { }

protected:
	int mem;
};

class Derived : public Base {
public:
	// initializes Derived::mem to i
	// Base::mem is default initialized
	Derived(int i): mem(i) { }

	int get_mem() { return mem; }  // returns Derived::mem
	int get_base_mem() { return Base::mem; }
	//...
protected:
	int mem; // hides mem in the base
};

int main()
{
	Derived d(42);
	cout << d.get_mem() << endl;       // prints 42
	cout << d.get_base_mem() << endl;  // prints 0

	// cout << d.mem << endl;
}

