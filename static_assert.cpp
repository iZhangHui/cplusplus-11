#include <iostream>

// template <typename T1, typename T2>
// auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
// {
// 	return t1 + t2;
// }

template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
	static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
	static_assert(std::is_integral<T2>::value, "Type T2 must be integral");

	return t1 + t2;
}

int main(int argc, char const *argv[])
{
	// std::cout << add(1, 3.14) << std::endl;
	// std::cout << add("one", 2) << std::endl;

	std::cout << add(1, 3) << std::endl;

	return 0;
}