#include <iostream>



// Overload not Override!
/*
class A
{
public:
	virtual void f(short) { std::cout << "A::f" << std::endl; }
};

class B : public A
{
public:
	virtual void f(int) { std::cout << "B::f" << std::endl; }
};
*/

/*
class A
{
public:
	virtual void f(int) const { std::cout << "A::f " << std::endl; }
};
class B : public A
{
public:
	virtual void f(int) { std::cout << "B::f" << std::endl; }
};
*/


class A
{
public:
	virtual void f(short) { std::cout << "A::f" << std::endl; }
	virtual void g(short) final { std::cout << "A::g" << std::endl; }
};

class B : public A
{
public:
	// 'f' marked 'override' but does not override any member functions
	// virtual void f(int)  override  { std::cout << "B::f" << std::endl; }
	virtual void f(short) override { std::cout << "B::f" << std::endl; }

	virtual void g(float) { std::cout << "B::g" << std::endl; } // overwrite
};

int	main(int argc, char const *argv[])
{
	A* ptr1 = new B();
	ptr1->f(10);

	// always call A::g
	ptr1->g(1);
	ptr1->g(2.1); // warning: implicit conversion from 'double' to 'int' changes value from 2.1 to 2 [-Wliteral-conversion]

	//==================
	B* ptr2 = new B();
	ptr2->f(10);
	ptr2->g(2.1);

	return 0;
}