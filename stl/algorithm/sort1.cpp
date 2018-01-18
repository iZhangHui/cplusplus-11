#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	// std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
	std::vector<int> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

	// sort using the default operator<
	std::sort(s.begin(), s.end());
	for (auto a : s) {
		std::cout << a << " ";
	}
	std::cout << "\n";

	std::sort(s.begin(), s.end(), std::greater<int>());
		for (auto a : s) {
		std::cout << a << " ";
	}
	std::cout << "\n";

	// sort using a custom function object
	struct customLess
	{
		bool operator()(int a, int b) { return a < b; }
	};
	std::sort(s.begin(), s.end(), customLess());
	for (auto a : s) {
		std::cout << a << " ";
	}
	std::cout << "\n";

	// sort using a lambda expression
	std::sort(s.begin(), s.end(), [](int a, int b) {
		return b < a;
	});
	for (auto a : s) {
		std::cout << a << " ";
	}
	std::cout << "\n";
	return 0;
}
