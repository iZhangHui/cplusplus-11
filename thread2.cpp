#include <iostream>
#include <future>
#include <thread>

int main(int argc, char const *argv[])
{
	std::packaged_task<int()> task([](){ return 7; });
	std::future<int> result = task.get_future();

	std::thread(std::move(task)).detach();

	std::cout << "Waiting...";
	result.wait();
	std::cout << "Done!\n" << "Result is " << result.get() << "\n";



	std::future<int> result2 = std::async(std::launch::async, [](){ return 14; });
	std::cout << "async result:: " << result2.get() << std::endl;
	return 0;
}
