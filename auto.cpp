//#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
	return t1+t2;
}

// C++14 support auto return
// auto compose(T1 t1, T2 t2)
// {
// 	return t1+t2;
// }

int main(int argc,char **argv)
{
	auto i = 10;
	cout << i << endl;

	auto v = compose(2, 3.14);
	cout << v << endl;
	return 0;
}


