#include "unique_ptr.hpp"
#include <iostream>

class Foo {
private:
    int x;

public:
    int y;
    Foo(int x, int y) : x(x), y(y) {}
};

int main() {
    auto ptr = newUnique<int>(100);
    std::cout << *ptr << "\n";

    auto ptr2 = std::move(ptr);
    std::cout << *ptr2 << "\n";

    auto myPtr = newUnique<std::string>("Goodbye");
    std::cout << *myPtr << "\n";

    auto myPtr2 = newUnique<std::string>("Hello");
    std::cout << *myPtr2 << "\n";

    myPtr.swap(myPtr2);
    std::cout << *myPtr << "\n";
    std::cout << *myPtr2 << "\n";

    auto fooPtr = newUnique<Foo>(10, 20);
    std::cout << fooPtr.get()->y << "\n";
    return 0;
}