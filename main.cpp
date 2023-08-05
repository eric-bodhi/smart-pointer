#include "unique_ptr.hpp"
#include <iostream>

struct Foo {
    int x = 10;
    int y = 20;
};

int main() {
    auto ptr = newUnique<int>(42);
    std::cout << *ptr << "\n";

    auto ptr2 = std::move(ptr);
    std::cout << *ptr2 << "\n";

    auto myPtr = newUnique<std::string>("Hello");
    std::cout << *myPtr << "\n";

    auto fooPtr = newUnique<Foo>(Foo{});
    std::cout << fooPtr.get()->x << "\n";

    return 0;
}
