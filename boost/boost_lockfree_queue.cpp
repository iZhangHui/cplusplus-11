 // Test boost lock free queue
// g++ -std=c++11 -o boost_queue.exe boost_queue.cpp -lpthread -lboost_system
// clang++-std=c++11 -o boost_queue.exe boost_queue.cpp -lpthread -lboost_system -latomic

#include <thread>
#include <atomic>
#include <utility>
#include <iostream>
#include <vector>

#include <boost/lockfree/queue.hpp>

using namespace std;

atomic<int> producer_count(0);

atomic<int> consumer_count(0);

boost::lockfree::queue<int> queue(512);


const int iterations = 1000000;

const int producer_thread_count = 4;

const int consumer_thread_count = 2;

void producer(void)
{
	for (int i = 0; i != iterations; ++i) {
		int value = ++producer_count;
		cout << "*";
		while (!queue.push(value));
	}
}

atomic<bool> done(false);

void consumer(void)
{
	int value;

	while (!done) {
		while (queue.pop(value)) {
			cout << ".";
			++consumer_count;
		}
	}

	while (queue.pop(value))
		++consumer_count;
}

int main(int argc, char* argv[])
{
	cout << "boost::lockfree::queue is ";
	if (!queue.is_lock_free())
		cout << "not ";
	cout << "lockfree" << endl;

	vector<thread> producer_threads;
	vector<thread> consumer_threads;

	for (int i = 0; i != producer_thread_count; ++i) {
		// thread p(producer);
		// producer_threads.push_back(std::move(p));
		producer_threads.emplace_back(producer);
	}

	for (int i = 0; i != consumer_thread_count; ++i) {
		// thread c(consumer);
		// consumer_threads.push_back(std::move(c));
		consumer_threads.emplace_back(consumer);
	}

	for (thread& item : producer_threads) {
		item.join();
	}

	done = true;
	cout << "done" << endl;

	for (thread& item : consumer_threads) {
		item.join();
	}

	cout << "produced " << producer_count << " objects." << endl;
	cout << "consumed " << consumer_count << " objects." << endl;

	return 0;
}
