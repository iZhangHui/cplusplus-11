#include <vector>
#include "BSTree.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> data = {1, 5, 4, 3, 2, 7, 6, 8};
	BSTree<int>* tree =  new BSTree<int>();

	for (const auto& item : data)
		tree->insert(item);

	tree->print();

	cout << "====================================" << endl;
	if (tree->maxmum() != nullptr)
		cout << "maxmum: " << tree->maxmum()->key << endl;
	if (tree->minimum() != nullptr )
		cout << "minimum: " << tree->minimum()->key << endl;

	cout << "====================================" << endl;
	tree->preOrder();
	cout << endl;
	cout << "====================================" << endl;


	tree->inOrder();
	cout << endl;
	cout << "====================================" << endl;

	tree->postOrder();
	cout << endl;
	cout << "====================================" << endl;

	cout << "Test seach:" << endl;
	cout << tree->search(3)->key<< endl;
	cout << "====================================" << endl;

	tree->remove(5);
	tree->print();

	delete tree;

	return 0;
}