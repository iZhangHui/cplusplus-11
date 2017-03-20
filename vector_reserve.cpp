
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Foo {
public:
    Foo() { }
    Foo(int i, string s) : i(i), s(s) { cout << "constructor" << endl; }
    Foo(const Foo& c) : i(c.i + 100), s(c.s + "copy") { cout << "copy constructor" << endl; }

    int i;
    string s;
};

int main(int argc, char const *argv[])
{
    vector<Foo> v;
    //v.reserve(2);
    v.push_back(Foo(1, "hello"));

    v.emplace_back(3, "world");

    return 0;
}
