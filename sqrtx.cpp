#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {

		int left = 0;
		int right = x / 2;

		while (left <= right) {
			auto mid = (left + right) / 2;

			if (mid * mid > x) {
				right = mid - 1;

			} else {
				left = mid + 1;
			}
		}

		return left - 1;
	}
};


int main(int argc, char const *argv[])
{
	Solution solution;

	cout << solution.mySqrt(0) << endl;
	cout << solution.mySqrt(1) << endl;
	cout << solution.mySqrt(2) << endl;
	cout << solution.mySqrt(3) << endl;
	cout << solution.mySqrt(4) << endl;

	cout << solution.mySqrt(9) << endl;
	cout << solution.mySqrt(10) << endl;

	return 0;
}