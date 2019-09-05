#include <utility>
#include <string.h>
#include <iostream>

class String
{
 public:
  String()
    : data_(new char[1])
  {
    *data_ = '\0';
    std::cout << "String::String()" << std::endl;
  }

  String(const char* str)
    : data_(new char[strlen(str) + 1])
  {
    strcpy(data_, str);
    std::cout << "String::String(const char*)" << std::endl;
  }

  String(const String& rhs)
    : data_(new char[rhs.size() + 1])
  {
    strcpy(data_, rhs.c_str());
    std::cout << "String::String(const String&)" << std::endl;
  }
  /* Delegate constructor in C++11
  String(const String& rhs)
    : String(rhs.data_)
  {
  }
  */

  ~String()
  {
    delete[] data_;
    std::cout << "~String()" << std::endl;
  }

  /* Traditional:
  String& operator=(const String& rhs)
  {
    String tmp(rhs);
    swap(tmp);
    return *this;
  }
  */
 // refer to C++ Primer P459
  String& operator=(String rhs) // yes, pass-by-value
  {
    std::cout << "operator=(String rhs)" << std::endl;
    swap(rhs);
    return *this;
  }

  // C++ 11
  String(String&& rhs)
    : data_(rhs.data_)
  {
    rhs.data_ = nullptr;
    std::cout << "String::String(String&&)" << std::endl;
  }

  String& operator=(String&& rhs)
  {
    std::cout << "operator=(String&&)" << std::endl;
    swap(rhs);
    return *this;
  }

  // Accessors
  size_t size() const
  {
    return strlen(data_);
  }

  const char* c_str() const
  {
    return data_;
  }

  // Same with construtor, it can access private member
  void swap(String& rhs)
  {
    std::swap(data_, rhs.data_);
  }

 private:
  char* data_;
};

void foo(String x)
{
}

void bar(const String& x) // Just bind
{
}

String baz()
{
  String ret("world");
  return ret;
}

#include <vector>
int main()
{
  String s0;
  std::cout << "tp1----------------------" << std::endl;
  String s1("hello");
  std::cout << "tp2----------------------" << std::endl;
  String s2(s0);
  std::cout << "tp3----------------------" << std::endl;
  String s3 = s1;
  std::cout << "tp4----------------------" << std::endl;
  s2 = s1;
  std::cout << "tp5----------------------" << std::endl;

  foo(s1);
  std::cout << "tp6----------------------" << std::endl;
  bar(s1);
  std::cout << "tp7----------------------" << std::endl;
  foo("temporary");
  std::cout << "tp8----------------------" << std::endl;
  bar("temporary");
  std::cout << "tp9----------------------" << std::endl;
  String s4 = baz();
  std::cout << "tp10---------------------" << std::endl;

  std::vector<String> svec;
  // void std::vector<String>::push_back(const String& __x)
  svec.push_back(s0);
  std::cout << "tp11----------------------" << std::endl;
  svec.push_back(s1);
  std::cout << "tp12----------------------" << std::endl;
  // void std::vector<String>::push_back(String&& __x)
  svec.push_back(baz());
  std::cout << "tp13----------------------" << std::endl;
  // void std::vector<String>::push_back(String&& __x)
  svec.push_back("good job");
  std::cout << "tp14----------------------" << std::endl;
  svec.emplace_back("c++11 emplace"); // Effective Modern C++ Item42
  std::cout << "tp15----------------------" << std::endl;
}
