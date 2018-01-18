#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[10] = {100, 200, 300};

    int (*p)[10] = &arr;

    std::cout << arr[0] << std::endl;
    std::cout << (*p)[1] << std::endl;

    // int (*p1)[20] = &arr;

    return 0;
}
