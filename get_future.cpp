#include <iostream>
#include <utility>
#include <future>
#include <thread>
#include <vector>

int func(int x) { return x + 2; }

int main(int argc, char const *argv[])
{
	std::packaged_task<int(int)> tsk(func);
	std::future<int> fut = tsk.get_future();

	std::thread(std::move(tsk), 2).detach();

	int value = fut.get();
	std::cout << "The result is " << value << "." << std::endl;

	std::vector<std::shared_future<int>> v;

	std::shared_future<int> f = std::async(std::launch::async,
		[](int a, int b) {
			return a + b;
		}, 2, 3);

	v.push_back(f);

	std::cout << "The shared_future result is " << v[0].get() << std::endl;
	return 0;
}