#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


int main(int argc, char const *argv[])
{
	auto num_cpus = std::thread::hardware_concurrency();
	std::cout << "Launching " << num_cpus << " threads\n";

	std::mutex iomutex;
	std::vector<std::thread> threads(num_cpus);
	for (auto i = 0; i < num_cpus; ++i) {
		threads[i] = std::thread([&iomutex, i]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(200));

			std::lock_guard<std::mutex> iolock(iomutex);
			std::cout << "Thread #" << i << " is running\n";
		});
	}

	for (auto& t : threads) {
		t.join();
	}
	return 0;
}