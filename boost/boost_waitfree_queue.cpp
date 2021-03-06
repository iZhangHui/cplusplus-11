#include <thread>
#include <iostream>
#include <atomic>
#include <boost/lockfree/spsc_queue.hpp>

using namespace std;

int producer_count = 0;
atomic<int> consumer_count(0);

boost::lockfree::spsc_queue<int, boost::lockfree::capacity<1024>> spsc_queue;

const int iterations = 10000000;

void producer(void)
{
    for (int i = 0; i != iterations; ++i) {
        int value = ++producer_count;
        while (!spsc_queue.push(value));
    }
}

atomic<bool> done(false);
void consumer(void)
{
    int value;
    while (!done) {
        while (spsc_queue.pop(value))
            ++consumer_count;
    }

    while (spsc_queue.pop(value))
        ++consumer_count;
}

int main(int argc, char* argv[])
{
    cout << "boost::lockfree::stack is ";
    if (!spsc_queue.is_lock_free())
        cout << "not";
    cout << "lockfree" << endl;

    thread producer_thread(producer);
    thread consumer_thread(consumer);
    
    producer_thread.join();
    done = true;
    consumer_thread.join();
    
    cout << "produced " << producer_count << " objects." << endl;
    cout << "consumed " << consumer_count << " objects." << endl;
}