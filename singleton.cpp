#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* instance()
	{
		std::call_once(_once, [](){ _singleton = new Singleton; });
		return _singleton;
	}
protected:
	Singleton() {};
	~Singleton();
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

	// delete Singleton::instance();

	thread t([]{ cout << Singleton::instance() << endl; });
	t.join();
	return 0;
}


// class Singleton {
// public:
// 	static Singleton& Instance()
// 	{
// 		static Singleton inst;
// 		return inst;
// 	}

// 	Singleton& operator=(const Singleton&) = delete; // Prevent assignment
// 	~Singleton() = delete; // Prevent unwanted destruction

// protected:
// 	Singleton(); // Prevent construction
// 	Singleton(const Singleton&); // Prevent construction by copying
// 	// Singleton& operator=(const Singleton&); // Prevent assignment
// 	// ~Singleton(); // Prevent unwanted destruction
// };
