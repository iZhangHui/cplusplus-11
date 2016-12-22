#include <thread>
#include <chrono>
#include <iostream>

class Foo {
public:
	Foo() : x(0)
	{
		// t = std::thread([=]{ ++x; });
		t = std::thread([this]{ this->x++; });
	}
	Foo(const Foo&) = delete;
	~Foo() { t.join(); }
	int get() { return x; }
private:
	std::thread t;
	int x;
};

int main(int argc, char const *argv[])
{
	Foo foo;

	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	std::cout << foo.get() << std::endl;
	return 0;
}