#include <iostream>
#include <thread>

void threadfun1()
{
    std::cout << "threadfun1 - 1\r\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "threadfun1 - 2" << std::endl;
}

void threadfun2(int iParam, std::string sParam)
{
    std::cout << "threadfun2 - 1" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "threadfun2 - 2" << std::endl;
}

int main()
{
    std::thread t1(threadfun1);
    std::thread t2(threadfun2, 10, "abc");

    t1.join();
    std::cout << "join" << std::endl;
    t2.detach();
    std::cout << "detach" << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(10));
}