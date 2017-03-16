#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <vector>
#include <iostream>

#include <pthread.h>

int main(int argc, char const *argv[])
{
	constexpr uint32_t num_threads = 4;
	std::mutex iomutex;
	std::vector<std::thread> threads(num_threads);

	for (auto i = 0; i < num_threads; ++i) {
		threads[i] = std::thread([&iomutex, i]() {
			while (true) {
				std::this_thread::sleep_for(std::chrono::milliseconds(900));

				std::lock_guard<std::mutex> iolock(iomutex);
				std::cout << "Thread #" << i << ": on CPU" << sched_getcpu() << "\n";
			}
		});

		cpu_set_t cpuset;
		CPU_ZERO(&cpuset);
		CPU_SET(i, &cpuset);
		int rc = pthread_setaffinity_np(threads[i].native_handle(),
										sizeof(cpu_set_t), &cpuset);
		if (rc != 0) {
			std::cerr << "Error calling pthread_setaffinity_np: " << rc << "\n";
		}
	}

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}