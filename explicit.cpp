#include <iostream>
using std::cout;
using std::endl;

class Circle
{
public:
	Circle() {
		cout << "Default constructor!" << endl;
	}

	Circle(double r) : R(r) {
		cout << "Circle constructor 1!" << endl;
	}

	Circle(int x, int y = 0) : X(x), Y(y) {
		cout << "Circle constructor 2!" << endl;
	}

	Circle(const Circle& c) : R(c.R), X(c.X), Y(c.Y) {
		cout << "Circle constructor 3!" << endl;
	}

	~Circle() {
		cout << "Circle destructor!" << endl;
	}

private:
	Circle& operator=(const Circle&);
	double R;
	int X;
	int Y;
};

int main(int argc, char* argv[])
{
	Circle a = 1.23;

	cout << "=======================" << endl;

	Circle b = 123;

	cout << "=======================" << endl;

	Circle c = a;

	cout << "=======================" << endl;

	Circle d = Circle(1.23);

	cout << "=======================" << endl;

	Circle e = Circle(123);

	cout << "=======================" << endl;

	Circle f = d;

	cout << "=======================" << endl;
}

// class Circle
// {
// public:
// 	Circle() {
// 		cout << "Default constructor!" << endl;
// 	}

// 	explicit Circle(double r) : R(r) {
// 		cout << "Circle constructor 1!" << endl;
// 	}

// 	explicit Circle(int x, int y =0) : X(x), Y(y) {
// 		cout << "Circle constructor 2!" << endl;
// 	}

// 	explicit Circle(const Circle& c) : R(c.R), X(c.X), Y(c.Y) {
// 		cout << "Circle constructor 3!" << endl;
// 	}

// 	~Circle() {
// 		cout << "Circle decstructor!" << endl;
// 	}

// private:
// 	Circle& operator =(const Circle&);
// 	double R;
// 	int X;
// 	int Y;
// };

// int main(int argc, char* argv[])
// {
// 	// Circle a = 1.23; // build error

// 	// cout << "=======================" << endl;

// 	// Circle b = 123; // build error

// 	// cout << "=======================" << endl;

// 	// Circle c = a; // build error

// 	// cout << "=======================" << endl;

// 	// Circle d = Circle(1.23); // build error

// 	// cout << "=======================" << endl;

// 	// Circle e = Circle(123); // build error

// 	// cout << "=======================" << endl;

// 	// Circle f = d; // build error

// 	// cout << "=======================" << endl;


// 	Circle a(1.23);

// 	cout << "=======================" << endl;

// 	Circle b(123);

// 	cout << "=======================" << endl;

// 	Circle c(a);

// 	cout << "=======================" << endl;

// }