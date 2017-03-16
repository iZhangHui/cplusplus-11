
#include <limits.h>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

int find_max_subarray(const vector<int>& input)
{
	int max_sum = input[0];

	for (int i = 0; i < input.size(); ++i) {
		int sum = 0;
		for (int j = i; j < input.size(); ++j) {
			sum += input[j];
			if (sum > max_sum) {
				max_sum = sum;
			}
		}
	}

	return max_sum;
}

// tuple<int,int,int> find_max_subarray(const vector<int>& input)
// {
// 	tuple<int,int,int> result(0, 0, INT_MIN);

// 	for (int i = 0; i < input.size(); ++i) {
// 		int sum = 0;
// 		for (int j = i; j < input.size(); ++j) {
// 			sum += input[j];
// 			if (sum > get<2>(result)) {
// 				get<0>(result) = i;
// 				get<1>(result) = j;
// 				get<2>(result) = sum;
// 			}
// 		}
// 	}

// 	return result;
// }

// int main(int argc, char const *argv[])
// {
// 	std::vector<int> test = {2, 4, -7, 5, 2, -1, 2, -4, 3};

// 	tuple<int,int,int> result = find_max_subarray(test);
// 	cout << "left = " << get<0>(result) << " "
// 		<< "right = " << get<1>(result) << " "
// 		<< "max_sum = " << get<2>(result)
// 		<< endl;

// 	return 0;
// }

// int find_max_subarray(const vector<int>& input)
// {
// 	int sum = 0;
// 	int max_sum = 0;

// 	for (auto item : input) {
// 		sum += item;
// 		if (sum > max_sum) {
// 			max_sum = sum;

// 		} else if (sum < 0) {
// 			sum = 0;
// 		}
// 	}

// 	return max_sum;
// }

// The divide-and-conquer solution
tuple<int,int,int> find_max_crossing_subarray(const vector<int>& array)
{

	int sum = 0;
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;

	int mid = array.size() / 2;
	tuple<int,int,int> result{-1, -1, 0};

	for (int i = mid; i > 0; --i) {
		sum += array[i];
		if (sum > left_sum) {
			left_sum = sum;
			get<0>(result) = i;
		}
	}

	sum = 0;
	for (int j = mid + 1; j < array.size(); ++j) {
		sum += array[j];
		if (sum > right_sum) {
			right_sum = sum;
			get<0>(result) = j;
		}
	}

	get<2>(result) = left_sum + right_sum;

	return result;
}

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high) {
	if (high == low + 1) {
		max_subarray result = {low, high, A[low]};
		return result;
	} else {
		unsigned mid = (low + high) / 2;
		max_subarray left = find_maximum_subarray(A, low, mid);
		max_subarray right = find_maximum_subarray(A, mid, high);
		max_subarray cross = find_max_crossing_subarray(A, low, mid, high);

		if (left.sum >= right.sum && left.sum >= cross.sum) {
			return left;

		} else if (right.sum >= left.sum && right.sum >= cross.sum) {
			return right;

		} else {
			return cross;
		}
	}
}

// The mixed algorithm
// max_subarray find_maximum_subarray_mixed(int A[], unsigned low, unsigned high) {
// 	if (high - low < CROSSOVER_POINT) {
// 		return find_maximum_subarray_brute(A, low, high);
// 	}
// 	else {
// 		unsigned mid = (low + high) / 2;
// 		max_subarray left = find_maximum_subarray_mixed(A, low, mid);
// 		max_subarray right = find_maximum_subarray_mixed(A, mid, high);
// 		max_subarray cross = find_max_crossing_subarray(A, low, mid, high);

// 		if (left.sum >= right.sum && left.sum >= cross.sum) {
// 			return left;

// 		} else if (right.sum >= left.sum && right.sum >= cross.sum) {
// 			return right;

// 		} else {
// 			return cross;
// 		}
// 	}
// }

int main(int argc, char const *argv[])
{
	std::vector<int> test = {2, 4, -7, 5, 2, -1, 2, -4, 3};

	cout << find_max_subarray(test) << endl;
	return 0;
}