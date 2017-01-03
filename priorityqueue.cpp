#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<float> pq;

	// insert three elements into the priority queue
	pq.push(66.6);
	pq.push(22.2);
	pq.push(44.4);

	// read and print two elements
	cout << pq.top() << ' ';
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();

	// insert three more elements
	pq.push(11.1);
	pq.push(55.5);
	pq.push(33.3);

	// skip one element
	pq.pop();

	// const float& top = pq.top();

	// pop and print remaining elements
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << endl;

	return 0;
}