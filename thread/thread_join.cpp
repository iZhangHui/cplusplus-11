#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
 
void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // while (true) {
    //     this_thread::sleep_for(chrono::seconds(1));
    // }
}
  
int main()
{
    std::thread t(foo);
    std::cout << "before joining,joinable=" << std::boolalpha << t.joinable() << std::endl;
    t.join();
    std::cout << "after joining, joinable=" << std::boolalpha << t.joinable() << '\n';
}