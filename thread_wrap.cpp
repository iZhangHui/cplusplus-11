#include <thread>
#include <chrono>
#include <iostream>

class Thread {
public:
	Thread() : _stop(false) { }
	virtual ~Thread();
	void start();
	void join();
	void yield();

protected:
	virtual void run() = 0;
	bool _stop;

private:
	std::thread _thread;
};


void Thread::start()
{
	_thread = std::thread(&Thread::run, this);
}

void Thread::join()
{
	_stop = true;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	_thread.join();
}

void Thread::yield()
{
	std::this_thread::yield();
}

Thread::~Thread() {
}


class DerivedThread : public Thread {
public:
	virtual void run()
	{
		while (!_stop) {
			std::cout << "Hello thread." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	}
};

int main(int argc, char const *argv[])
{
	Thread* t = new DerivedThread();
	t->start();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	t->join();
	delete t;

	return 0;
}