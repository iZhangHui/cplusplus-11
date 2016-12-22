#include <atomic>    // for atomics
#include <future>    // for async() and futures
#include <thread>    // for this_thread
#include <chrono>    // for durations
#include <iostream>

using namespace std;

// clang++ -std=c++11 -o mutex_atomic.exe mutex_atomic.cpp -pthread

// Not thread safe data structor
// Would not get corret result for multi-threads
class Foo {
public:
    Foo() : _data(0) { }
    void add()
    {
        ++_data;
    }

    int get()
    {
        return _data;
    }
private:
    int _data;
};

class Foo_Mutex {
public:
    Foo_Mutex() : _data(0) { }
    void add()
    {
        std::lock_guard<std::mutex> lg(m);
        ++_data;
    }

    int get()
    {
        std::lock_guard<std::mutex> lg(m);
        return _data;
    }
private:
    int _data;
    std::mutex m;
};

class Foo_Atomic {
public:
    Foo_Atomic() : _data(0) { }
    void add()
    {
        ++_data;
    }

    int get()
    {
        return _data;
    }
private:
    std::atomic<int> _data;
};


int main()
{
    // Foo foo;
    // Foo_Mutex foo;
    Foo_Atomic foo;

    auto start = chrono::system_clock::now();
    auto p = std::async(std::launch::async, [&]{
        for (int i = 0; i < 1000000; i++)
            foo.add();
    });
    auto c = std::async(std::launch::async, [&]{
        for (int i = 0; i < 1000000; i++)
            foo.add();
    });

    p.wait();
    c.wait();

    auto duration = chrono::system_clock::now() - start;
    cout << "result:" << foo.get() << endl;
    cout << "duration:" << chrono::duration_cast<chrono::milliseconds>(duration).count() << "ms" << std::endl;
    // cout << "duration:" << chrono::duration_cast<chrono::microseconds>(duration).count() << "us" << std::endl;

}