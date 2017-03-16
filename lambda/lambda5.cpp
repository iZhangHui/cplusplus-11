
#include <iostream>
#include <typeinfo>

/*
**
*The type of the lambda-expression (which is also the type
*of the closure object) is a unique, unnamed non-union class
*type — called the closure type — whose properties are described below.
*This class type is not an aggregate (8.5.1). The closure type is
*declared in the smallest block scope, class scope, or namespace scope
*that contains the corresponding lambda-expression. [..]
*/
#define LAMBDA [](int i)->long { return 0l; }

int main ()
{
  long (*pFptr)(int) = LAMBDA;  // ok
  auto pAuto = LAMBDA;  // ok

  std::cout << typeid(*pAuto).name() << std::endl;
  std::cout << typeid(*pFptr).name() << std::endl;

  std::cout << typeid(pAuto).name() << std::endl;
  std::cout << typeid(pFptr).name() << std::endl;
}