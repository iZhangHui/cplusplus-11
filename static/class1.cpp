#include <iostream>

class class1_t {
public:
	class1_t () { std::cout << "class1_t::class1_t()" << std::endl; }
};

static class1_t s_class1;