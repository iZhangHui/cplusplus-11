/*
*这个类很有意思，让一个被shared_ptr管理生命周期的类能够在自己的成员函数内部访问shared_ptr。有点绕。
*举个例子，下面的代码在函数f内部通过this构造了shared_ptr对象，然后打印x_的值。
*/
#include <iostream>
#include <memory>

using namespace std;

// class B {
// public:
// 	B(): x_(4) {
// 		cout << "B::B()" << endl;
// 	}

// 	~B() {
// 		cout << "B::~B()" << endl;
// 	}

// 	void f() {
// 		shared_ptr<B> p(this);
// 		cout << p->_x << endl;
// 		//shared_from_this();
// 	}

// private:
// 	int _x;
// };

// int main(int argc, char** argv)
// {
// 	shared_ptr<B> x(new B);
// 	x->f();
// 	return 0;
// }


/*
编译通过，但是运行结果：
B::B()
4
B::~B()
B::~B()
两次析构B对象，这是个灾难。
现在试一下enable_shared_from_this：
*/
class A : public enable_shared_from_this<A> {
public:
	A() : _x(4) {
		cout << "A::A()" << endl;
	}

	~A() {
		cout << "A::~A()" << endl;
	}

	shared_ptr<A> f() {
		// cout << shared_from_this()->_x << endl; // this way is okay too
		shared_ptr<A> p = shared_from_this();
		cout << p->_x << endl;
		return p;
	}

private:
	int _x;
};

int main(int argc, char** argv)
{
	shared_ptr<A> x = make_shared<A>();
	shared_ptr<A> p = x->f();
	return 0;
}

/*
运行结果：
[cpp]
A::A()
0
A::~A()
那么，为什么需要这样做呢？在自己的类里面访问自己的成员，其实只是个示例代码，一定必要都没有。

不过有一种可能，就是f函数需要返回自己的指针给调用者，难道这样写么？

[cpp]
A* f();
一个裸指针返回出去，失控了。谁也不知道调用者会干什么？
比较聪明的方法是设计成：

shared_ptr<A> f()

好了，这就是为什么我们需要enable_shared_from_this。
*/


// 防止回调的时候之前在callback里面所绑定的指针已经失效
// shared_ptr increase ref count, so could not deconstructor