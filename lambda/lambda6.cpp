#include <iostream>
#include <utility>
#include <memory>

int main() {
    // std::unique_ptr<int> important = std::make_unique<int>(1);
    auto important = std::make_unique<int>(1);
    // auto add = [v1 = 1, v2 = std::move(important)](int x, int y) {
    //     return x+y+v1+(*v2);
    // };

    auto add = [&](auto x, auto y) {
        return x+y+(*important);
    };

    // auto add = [=](int x, int y) {
    //     return x+y+(*important);
    // };

    std::cout << add(3, 4) << std::endl;
    std::cout << add(1.1,  2.2) << std::endl;
    
    return 0;
}