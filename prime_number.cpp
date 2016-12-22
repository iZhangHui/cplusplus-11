/*
*这个问题归结于这样的命题：
*正整数A，设它的平方根为Q
*1、如果存在一个大于1小于Q的整数可以整除A，则必然存在一个大于Q小于A的整数可以整除A；
*2、如果不存在一个大于1小于Q的整数可以整除A，则必然也不存在一个大于Q小于A的整数可以整除A。
*
*先证明第1条
*设B是一个大于1小于Q的整数，且B可以整除A。按整除的定义存在一个整数C，使得 B * C ＝ A
*C必然大于Q。因为如果C小于等于Q，则B * C <= B * Q < Q * Q = A。这与整除定义相矛盾。
*
*再证明第2条
*设C是一个整数，Q < C < A，且C可以整除A。按整除的定义存在一个整数B，使得 B * C ＝ A
*由于 Q < C 所以 B < Q(证明方法同上，不再赘述)，这与题设2矛盾，所以这样的C不存在。
*
*证毕
*/
#include <cmath>
// #include <algorithm>
#include <iostream>

bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	std::vector<int> test;
	for (int i = 2; i < 101; ++i) {
		test.push_back(i);
	}

	for (int item : test) {
		if (is_prime(item))
			std::cout << item << std::endl;
	}
	return 0;
}