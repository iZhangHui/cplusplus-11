#include <iostream>

typedef void*(*SFThreadFuncPtr)(void* pUser);

int main(int argc, char const *argv[])
{
	SFThreadFuncPtr fp = [](void* _this) -> void* { return nullptr; };
	return 0;
}