#ifndef UNIQUE_PTR_TPP
#define UNIQUE_PTR_TPP

// Definition of the class template member functions
template <typename T>
UniquePtr<T>::UniquePtr(T *rawPtr) : ptr(rawPtr)
{
    std::cout << "Ptr constructed" << "\n";
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete ptr;
    std::cout << "Ptr deconstructed" << "\n";
}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr)
{
    other.ptr = nullptr;
    std::cout << "Move Constructor" << "\n";
}

template <typename T>
UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr &&other) noexcept
{
    if (this != &other)
    {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        std::cout << "Move assignment" << "\n";
    }

    return *this;
}

template <typename T>
const T &UniquePtr<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T *UniquePtr<T>::get()
{
    return ptr;
}

template <typename T>
const T *UniquePtr<T>::get() const
{
    return ptr;
}

// Definition of the function template
template <typename T, typename... Args>
UniquePtr<T> newUnique(Args &&...args)
{
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

#endif // UNIQUE_PTR_TPP
