#include <iostream>

class class2_t {
public:
	class2_t() { std::cout << "class2_t::class2_t()" << std::endl; }
	~class2_t() { std::cout << "class2_t::~class2_t()" << std::endl; }
};

static class2_t s_class2;

int main()
{
	std::cout << "main tp1------->" << std::endl;
	return 0;
	std::cout << "main tp2------->" << std::endl;
}