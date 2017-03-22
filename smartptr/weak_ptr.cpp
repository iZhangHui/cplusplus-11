#include <iostream>
#include <memory>
// std::shared_ptr<T> lock() const; (since C++11)
// Creates a new std::shared_ptr that shares ownership of the managed object.
// If there is no managed object, i.e. *this is empty, then the returned shared_ptr also is empty.
// Effectively returns expired() ? shared_ptr<T>() : shared_ptr<T>(*this), executed atomically.

void observe(std::weak_ptr<int> weak)
{
	if (auto observe = weak.lock()) {
		std::cout << "observe() able to lock weak_ptr<>, value = " << *observe << std::endl;

	} else {
		std::cout << "observe() unable to lock weak_ptr<>" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	std::weak_ptr<int> weak;
	std::cout << "weak_ptr<> not yet initialized." << std::endl;
	observe(weak);

	{
		auto shared = std::make_shared<int>(42);
		weak = shared;
		std::cout << "weak_ptr<> initialized with shared_ptr." << std::endl;
		observe(weak);
	}

	std::cout << "shared_ptr<> has been destructed due to scope exit." << std::endl;
	observe(weak);

	return 0;
}
