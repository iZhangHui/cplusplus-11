#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <sched.h>


int main(int argc, char const *argv[])
{
	constexpr uint32_t num_cpus = 4;
	std::mutex iomutex;
	std::vector<std::thread> threads(num_cpus);
	for (auto i = 0; i < num_cpus; ++i) {
		threads[i] = std::thread([&iomutex, i]() {
			while (true) {
				std::this_thread::sleep_for(std::chrono::milliseconds(900));

				std::lock_guard<std::mutex> iolock(iomutex);
				std::cout << "Thread #" << i << ": on CPU " << sched_getcpu() << "\n";
			}
		});
	}

	for (auto& t : threads) {
		t.join();
	}
	return 0;
}