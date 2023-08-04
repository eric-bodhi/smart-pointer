#include <iostream>
#include "smart-pointer.cpp"

int main()
{
    auto ptr = newUnique<int>(42);
    std::cout << *ptr << "\n";

    auto myPtr = newUnique<std::string>("Hello");
    std::cout << *myPtr << "\n";

    return 0;
}
