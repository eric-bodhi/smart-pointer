#include <iostream>

template <typename T>
class UniquePtr
{
private:
    T *ptr;

public:
    UniquePtr(T *rawPtr = nullptr) : ptr(rawPtr)
    {
        std::cout << "Ptr constructed"
                  << "\n";
    }

    ~UniquePtr()
    {
        delete ptr;
        std::cout << "Ptr deconstructed"
                  << "\n";
    }

    UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
        std::cout << "Move Constructor"
                  << "\n";
    }

    UniquePtr &operator=(UniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
            std::cout << "Move assignment"
                      << "\n";
        }

        return *this;
    }

    T &operator*()
    {
        return *ptr;
    }

    T *get()
    {
        return ptr;
    }
};

template <typename T, typename... Args>
UniquePtr<T> newUnique(Args &&...args)
{
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}
