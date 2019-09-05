#include <string>
#include <iostream>

using namespace std;

class Test {
public:
	Test() { cout << "Test constructor." << endl; }
	Test(const Test&) { cout << "Test copy constuctor." << endl; }
	~Test() { cout << "destructor" << endl; }
};

Test test1(Test& input)
{
	return input;
}

Test& test2(Test& input)
{
	return input;
}

// RVO: Return value optimization
Test test3()
{
	Test t;
	return t;
}

int main()
{
	Test test;

	cout << "**********************" << endl;
	Test a = test1(test);
	cout << "======================" << endl;
	Test b = test2(test); // copy:C++ Primer 5th P310(Chinese Version)
	cout << "======================" << endl;
	Test& c = test2(test);
	cout << "======================" << endl;
	Test d = test3(); // RVO
	// Test& d = test3();
	cout << "======================" << endl;
}