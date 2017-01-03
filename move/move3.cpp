#include <iostream>

class HugeMem {
public:
	HugeMem(int size) : sz(size > 0 ? size : 1)
	{
		c = new int[sz];
	}
	HugeMem(HugeMem&& rhs) : c(rhs.c), sz(rhs.sz)
	{
		rhs.c = nullptr;
	}
	~HugeMem()
	{
		delete c;
	}
// private:
	int* c;
	int sz;
};

class Moveable {
public:
	Moveable() : i(new int(3)), h(1024) {}
	Moveable(Moveable&& rhs) : i(rhs.i), h(std::move(rhs.h))
	{
		rhs.i = nullptr;
	}

// private:
	int* i;
	HugeMem h;
};


Moveable getTemp()
{
	Moveable tmp = Moveable();
	std::cout << std::hex << "Huge Mem from " << __func__
			  << " @" << tmp.h.c << std::endl;
	return tmp;
}

int main(int argc, char const *argv[])
{
	Moveable a(getTemp());
	std::cout << std::hex << "Huge Mem from " << __func__
			  << " @" << a.h.c << std::endl;
	return 0;
}

// clang++ -std=c++11 -o move3.exe move3.cpp -fno-elide-constructors
