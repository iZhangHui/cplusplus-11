#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> dict;
	string s;
	while (cin >> s)
		++dict[s];

	for (auto item : dict)
		cout << item.first << ": " << item.second << "\n";


	// map<int, string> dict;
	// int i = 0;
	// string s;
	// while (cin >> s)
	// 	dict[i++] = s;

	// cout << "Min: " << dict.begin()->second << endl;
	// cout << "Max: " << (--dict.end())->second << endl;

	return 0;
}