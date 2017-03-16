#include <thread>
#include <iostream>

class Wrapper {
public:
	void member1() {
			std::cout << "i am member1" << std::endl;
	}
	void member2(const char *arg1, unsigned arg2) {
			std::cout << "i am member2 and my first arg is (" << arg1 << ") and second arg is (" << arg2 << ")" << std::endl;
	}
	std::thread member1Thread() {
			return std::thread([=] { member1(); });
	}
	std::thread member2Thread(const char *arg1, unsigned arg2) {
			return std::thread([=] { member2(arg1, arg2); });
	}

	 std::thread member3Thread(const char *arg1, unsigned arg2) {
			return std::thread([=] { std::cout << arg1 << " " << arg2 << std::endl; });
	}
};

int main(int argc, char** argv)
{
	Wrapper *w = new Wrapper();
	std::thread tw1 = w->member1Thread();
	std::thread tw2 = w->member2Thread("hello", 100);
	std::thread tw3 = w->member3Thread("lambda test", 200);
	tw1.join();
	tw2.join();
	tw3.join();
	return 0;
}