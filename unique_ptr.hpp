#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

#include <iostream>
#include <utility>

// Template declaration for the entire header
template <typename T>
class UniquePtr
{
private:
    T *ptr;

public:
    explicit UniquePtr(T *rawPtr = nullptr);

    ~UniquePtr();

    UniquePtr(UniquePtr &&other) noexcept;

    UniquePtr &operator=(UniquePtr &&other) noexcept;

    const T &operator*() const;

    T *get();

    const T *get() const;
};

// Template declaration for the function template
template <typename T, typename... Args>
UniquePtr<T> newUnique(Args &&...args);

// Include the template implementation
#include "unique_ptr.tpp"

#endif // UNIQUE_PTR_HPP
