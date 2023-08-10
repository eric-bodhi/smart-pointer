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
    auto arr = newUnique<int[]>(10);
    auto arr2 = newUnique<int[]>(20);
    arr[0] = 10;
    arr.swap(arr2);
    std::cout << arr2[0] << "\n";
    return 0;
}