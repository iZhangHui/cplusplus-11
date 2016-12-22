#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x = 0;
	int y = 42;

	auto qqq = [x, &y] {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		++y;
	};

	// auto qqq = [x, &y]() mutable {
	// 	cout << "x: " << x << endl;
	// 	cout << "y: " << y << endl;
	// 	++x;
	// 	++y;
	// };

	x = y = 77;
	qqq();
	qqq();

	cout << "Finally y: " << y << endl;
	return 0;
}