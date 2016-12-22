//#include <stdlib.h>

#include <iostream>
using namespace std;

class Test
{
public:
	 Test() {};
	~ Test() {};

	void TestWork(int index)
	{
		cout << "TestWork 1" << endl;
	}

	void TestWork(void* index)
	{
		cout << "TestWork 2" << endl;
	}

};

int main(int argc, char const *argv[])
{
	Test test;

	//test.TestWork(NULL);
	test.TestWork(nullptr);

	int* ptr = nullptr;
	*ptr = 0;

	return 0;
}