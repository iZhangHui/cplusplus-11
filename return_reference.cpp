#include <string>
#include <iostream>

using namespace std;

class Test {
public:
	Test() { cout << "Test constructor." << endl; }
	Test(const Test&) { cout << "Test copy constuctor." << endl; }
};

Test test1(Test& input)
{
	return input;
}

Test& test2(Test& input)
{
	return input;
}

int main()
{
	Test test;

	cout << "**********************" << endl;
	Test a = test1(test);
	cout << "======================" << endl;
	Test b = test2(test);
	cout << "======================" << endl;
	Test& d = test2(test);
	cout << "======================" << endl;

	// string& c = test1(test); //compiler error
}