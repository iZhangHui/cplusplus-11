#include <queue>
#include <iostream>

using namespace std;

class Foo
{
public:
	Foo() { cout << "Default constructor." << endl; }
	Foo(const Foo&) { cout << "copy constructor." << endl; }
	Foo(Foo&&) { cout << "move constructor." << endl; }
	Foo& operator=(Foo&&) { cout << "move assign" << endl; return *this; }
	~Foo() { cout << "Destructor" << endl; }
};


queue<Foo> data_queue;

void pop_wrap(Foo& value)
{
	cout << "==================" << endl;
	value = std::move(data_queue.front());
	cout << "==================" << endl;
	data_queue.pop();
	cout << "==================" << endl;
}



int main(int argc, char const *argv[])
{
	Foo foo1;
	data_queue.push(foo1);
	cout << "***************" << endl;

	data_queue.push(Foo());
	cout << "###############" << endl;

	Foo ref;
	pop_wrap(ref);
	return 0;
}