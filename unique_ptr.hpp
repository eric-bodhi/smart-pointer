#pragma once

#include <iostream>
#include <type_traits>

template <typename T>
class UniquePtr {
private:
    T* ptr;

public:
    explicit UniquePtr(T* rawPtr = nullptr) : ptr(rawPtr) {
        std::cout << "Ptr constructed"
                  << "\n";
    }

    ~UniquePtr() {
        delete[] ptr;
        std::cout << "Ptr deconstructed"
                  << "\n";
    }

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
        std::cout << "Move Constructor"
                  << "\n";
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
            std::cout << "Move assignment"
                      << "\n";
        }

        return *this;
    }
    T& operator*() {
        return *ptr;
    }

    const T& operator*() const {
        return *ptr;
    }

    T* get() {
        return ptr;
    }

    // Const version of get()
    const T* get() const {
        return ptr;
    }

    T& operator[](size_t index) const {
        return ptr[index];
    }

    void swap(UniquePtr<T>& other) noexcept {
        std::swap(ptr, other.ptr);
    }
};

template<typename T>
UniquePtr<std::remove_extent_t<T>> newUnique(std::size_t n) requires (std::is_array_v<T>) {
    using J = std::remove_extent_t<T>;
    return UniquePtr<J>({ new J[n]{} });
}

template <typename T, typename... Args>
UniquePtr<T> newUnique(Args&&... args) requires (!std::is_array_v<T>) {
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}