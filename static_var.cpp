#include <iostream>

class StaticClass
{
public:
	StaticClass(const int input) : var(input)
	{
		std::cout << "StaticClass constructor." << std::endl;
	}
	~StaticClass() { std::cout << "StaticClass destructor." << std::endl; }
private:
	int var;
};

class Test
{
public:
	Test() { std::cout << "Test constructor." << std::endl; }
	static int static_print();
private:
	static int static_int;
	static StaticClass static_class;
};

int Test::static_int = static_print();
StaticClass Test::static_class = 2;

int Test::static_print()
{
	std::cout << "Call static_print function." << std::endl;
	return 1;
}

int main(int argc, char const *argv[])
{
	std::cout << "Enter main function." << std::endl;

	Test test;

	return 0;
}
