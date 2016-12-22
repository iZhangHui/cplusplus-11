
#include <algorithm>
#include <memory>
#include <iostream>
#include <cassert>

// template <typename T>
// class Buffer
// {
// public:
// 	// default constructor
// 	Buffer() :
// 		_size(16),
// 		_buffer(new T[16])
// 	{
// 		std::cout << "default constructor" << std::endl;
// 	}

// 	// constructor
// 	Buffer(const std::string& name, size_t size) :
// 		_name(name),
// 		_size(size),
// 		_buffer(new T[size])
// 	{
// 		std::cout << "constructor" << std::endl;
// 	}

// 	// copy constructor
// 	Buffer(const Buffer& rhs) :
// 		_name(rhs._name),
// 		_size(rhs._size),
// 		_buffer(new T[rhs._size])
// 	{
// 		std::cout << "copy constructor" << std::endl;
// 		T* source = rhs._buffer.get();
// 		T* dest = _buffer.get();
// 		std::copy(source, source + rhs._size, dest);
// 	}

// 	// copy assignment operator
// 	Buffer& operator=(const Buffer& rhs)
// 	{
// 		if (this != &rhs) {
// 			_name = rhs._name;

// 			if (_size != rhs._size) {
// 				_buffer = nullptr;
// 				_size = rhs._size;
// 				_buffer = _size > 0 ? new T[_size] : nullptr;
// 			}

// 			T* source = rhs._buffer.get();
// 			T* dest = _buffer.get();
// 			std::copy(source, source + rhs._size, dest);
// 		}

// 		return *this;
// 	}

//    // move constructor
// 	Buffer(Buffer&& temp) :
// 		_name(std::move(temp._name)),
// 		_size(temp._size),
// 		_buffer(std::move(temp._buffer))
// 	{
// 		std::cout << "move constructor" << std::endl;
// 		temp._buffer = nullptr;
// 		temp._size = 0;
// 	}

//    // move assignment operator
// 	Buffer& operator=(Buffer&& temp)
// 	{
// 		std::cout << "move assignment operator" << std::endl;
// 		assert(this != &temp); // assert if this is not a temporary

// 		_buffer = nullptr;
// 		_size = temp._size;
// 		_buffer = std::move(temp._buffer);

// 		_name = std::move(temp._name);

// 		temp._buffer = nullptr;
// 		temp._size = 0;

// 		return *this;
// 	}

// private:
// 	std::string _name;
// 	size_t _size;
// 	std::unique_ptr<T[]> _buffer;
// };


template <typename T>
class Buffer
{
private:
	std::string          _name;
	size_t               _size;
	std::unique_ptr<T[]> _buffer;

public:
	// constructor
	Buffer(const std::string& name = "", size_t size = 16):
		_name(name),
		_size(size),
		_buffer(size ? new T[size] : nullptr)
	{}

	// copy constructor
	Buffer(const Buffer& rhs):
		_name(rhs._name),
		_size(rhs._size),
		_buffer(rhs._size ? new T[rhs._size] : nullptr)
	{
		T* source = rhs._buffer.get();
		T* dest = _buffer.get();
		std::copy(source, source + rhs._size, dest);
	}

	// move constructor
	Buffer(Buffer&& temp) : Buffer()
	{
		swap(*this, temp);
	}

	// copy assignment operator
	Buffer& operator=(Buffer rhs)
	{
		 swap(*this, rhs);
		 return *this;
	}

	friend void swap(Buffer& lhs, Buffer& rhs) noexcept
	{
		using std::swap;
		swap(lhs._name  , rhs._name);
		swap(lhs._size  , rhs._size);
		swap(lhs._buffer, rhs._buffer); // swap the pointers
	}
};

template <typename T>
Buffer<T> getBuffer(const std::string& name)
{
	Buffer<T> b(name, 128);

	return b; // RVO
	// return std::move(b);
}

int main(int argc, char const *argv[])
{
	Buffer<int> b1; // default
	Buffer<int> b2("buf2", 64); // constructor
	Buffer<int> b3 = b2; // copy constructor

	std::cout << "=============" << std::endl;
	Buffer<int> b4 = getBuffer<int>("buf4");
	std::cout << "*************" << std::endl;
	b1 = getBuffer<int>("buf5");
	return 0;
}
