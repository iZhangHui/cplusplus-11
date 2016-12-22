#include <iostream>

int main(int argc, char* argv[])
{
	float a = 1.0f;
	float b = -1.0f;
	float c = 0.5f;
	float d = -0.5f;
	float e = 1.5f;
	float f = -1.5;

	std::cout << static_cast<int>(a) << std::endl;
	std::cout << static_cast<int>(b) << std::endl;
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << static_cast<int>(d) << std::endl;
	std::cout << static_cast<int>(e) << std::endl;
	std::cout << static_cast<int>(f) << std::endl;
}