#include <iostream>
#include <vector>

class Foo {
friend std::ostream& operator<<(std::ostream&, const Foo&);
public:
	Foo() = default;
	Foo(int foo): i(foo) { std::cout << "ctor" << std::endl; }
	Foo(const Foo& f) {
		std::cout << "copy constructor" << std::endl;
		i = f.i;
	}
	void print() { std::cout << i << std::endl; }
private:
	int i;
};

std::ostream& operator<<(std::ostream& os, const Foo& f)
{
	os << f.i;
	return os;
}

int main(int argc, char const *argv[])
{
	int numbers[] = {1, 2, 3, 4, 5};

	std::cout << "numbers:" << std::endl;

	for (auto number : numbers)
	{
		std::cout << number << std::endl;
	}

	std::vector<Foo> c = { Foo(4), Foo(3), Foo(2), Foo(1) };
	// for (auto item : c) {
	for (auto& item : c) {
		std::cout << item << std::endl;
	}

	return 0;
}