#include <vector>
#include <iostream>
using namespace std;

void qsort(vector<int>& data, int l, int u)
{
	if (l >= u)
		return;

	int pivot = l;
	int left = l + 1;
	int right = u;

	while (left < right) {
		while (data[right] > data[pivot] && left < right)
			--right;

		while (data[left] < data[pivot] && left < right)
			++left;
		std::swap(data[left], data[right]);
	}

	std::swap(data[pivot], data[right]);

	qsort(data, l, right-1);
	qsort(data, right+1, u);
}

// int partition(vector<int>&data, int l, int u)

int main(int argc, char const *argv[])
{
	vector<int> test{8, 3, 4, 10, 7};
	qsort(test, 0, test.size()-1);
	for(auto i : test){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

