#include "unique_ptr.hpp"
#include <iostream>

int main() {
    auto arr = newUnique<int[]>(10);
    auto arr2 = newUnique<int[]>(20);
    arr[0] = 10;
    arr.swap(arr2);
    std::cout << arr2[0] << "\n";

    auto ptr1 = newUnique<int>(10);
    auto ptr2 = newUnique<int>(20);
    std::cout << *ptr1 << "\n";
    ptr1.swap(ptr2);
    std::cout << *ptr1 << "\n";

    auto ptr3 = newUnique<int>(30);
    ptr3 = std::move(ptr1);
    std::cout << *ptr3 << "\n";

    auto ptr4 = std::move(ptr3);
    std::cout << *ptr4 << "\n";

    return 0;
}