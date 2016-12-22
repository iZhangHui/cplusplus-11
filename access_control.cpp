#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	Base() : prot_mem(-100), priv_mem(250) { }

	// public memeber
	void pub_mem() { cout << "Base public function." << endl; }
protected:
	int prot_mem; // protected member
private:
	char priv_mem; // private member

};

class Pub_Derv : public Base {
public:
	Pub_Derv() = default;

	int f() { return prot_mem; }

	// error:private members are inacessible to derived classes
	// char g() { return priv_mem; }
};

class Priv_Derv : private Base {
public:
	Priv_Derv() = default;
	// private derivation doesn't affect access in the derived class
	// only affect derived class's user!!!
	int f1() const { return prot_mem; }
};

class Derived_from_Public : public Pub_Derv {
public:
	// ok: Base::prot_mem remains protected in Pub_Derv
	int use_base() { return prot_mem; }
};

class Derived_from_Private : public Priv_Derv {
public:
	// error: Base::prot_mem is private in Priv_Derv
	// int use_base() { return prot_mem; }
	// class Priv_Derv : protected Base
};

int main(int argc, char const* argv[])
{
	Pub_Derv d1;
	Priv_Derv d2;

	d1.pub_mem();
	//d2.pub_mem();

	cout << d2.f1() << endl;

	return 0;
}