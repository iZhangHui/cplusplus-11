#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* instance()
	{
		std::call_once(_once, []{ _singleton = new Singleton; });
		return _singleton;
	}
private:
	static std::once_flag _once;
	static Singleton *_singleton;
};

Singleton* Singleton::_singleton = nullptr;
std::once_flag Singleton::_once;


// clang++ -std=c++11 -o singleton.exe singleton.cpp -lpthread
int main(int argc, char const *argv[])
{
	// Singleton* instance = Singleton::instance();
	cout << Singleton::instance() << endl;

	thread t([]{ cout << Singleton::instance() << endl; });
	t.join();
	return 0;
}