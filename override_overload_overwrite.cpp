#include <stdio.h>
#include <iostream>
class Base
{
public:
	void F() { std::cout << "Base.F()" << std::endl; }

	virtual void G() { std::cout << "Base.G()" << std::endl; }

	int Add(int x, int y) { return x + y; }

	// overload add
	float Add(float x, float y) { return x + y; }
};

class Derived : public Base
{
public:
	// overwrite parent's function
	void F() { std::cout << "Derived.F()" << std::endl; }

	// override parent virtual funciton
	virtual void G() override
	{
		std::cout << "Derived.G()" << std::endl;
	}
};


int main(int argc, char const *argv[])
{
	Base* pBase = new Derived();
	pBase->F(); // Base.F
	pBase->G(); // Derived.G
	pBase->Add(1, 2);
	pBase->Add(1.2f, 2.1f);


	Derived* pD = new Derived();
	pD->F(); // Derived.F
	pD->G(); // Derived.G
	pD->Add(1, 2);
	pD->Add(2.1f, 1.2f);

	delete pBase;
	delete pD;

	return 0;
}
