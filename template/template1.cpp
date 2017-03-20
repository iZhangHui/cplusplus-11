// C++模板编译期求值
#include <iostream>

using namespace std;

template<unsigned n>
struct Factorial {
	static const unsigned v = n * Factorial<n - 1>::v;  // 递归
};

// 模板特化，也是上面递归的终止条件
template<>
struct Factorial<1> {
	static const unsigned v = 1;
};

// 模板特化，只匹配Factorial<0>情况
template<>
struct Factorial<0> {
	static const unsigned v = 0;
};

int main() {
	cout << Factorial<5>::v << endl;    // 120
	cout << Factorial<1>::v << endl;    // 1
	cout << Factorial<0>::v << endl;    // 0
}
