#include <string>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::string str = "Hello world!";
	std::vector<std::string> vec;

	// uses the push_back(const T&) overload, which means
	// we'll incur the cost of copying str
	vec.push_back(str);
	std::cout << "After copy, str is " << str << std::endl;

	// uses the rvalue reference push_back(T&&) overload,
	// which means no strings will be copied; instead, the contents
	// of str will be moved into the vector.  This is less
	// expensive, but also means str might now be empty.
	vec.push_back(std::move(str));
	std::cout << "After move, str is " << str << std::endl;

	std::cout << "The contents of the vector are " << vec[1] << std::endl;
	return 0;
}