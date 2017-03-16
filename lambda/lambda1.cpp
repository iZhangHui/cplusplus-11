#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x = 0;
	int y = 42;

	auto f = [x, &y] {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		++y;
	};

	// auto f = [x, &y]() mutable {
	// 	cout << "x: " << x << endl;
	// 	cout << "y: " << y << endl;
	// 	++x;
	// 	++y;
	// };

	x = y = 77;
	f();
	f();

	cout << "Finally y: " << y << endl;
	return 0;
}