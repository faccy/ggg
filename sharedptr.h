#pragma once
#ifndef _SHAREDPTR_H_
#define _SHAREDPTR_H_

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class sharedPtr {
private:
    int* count;
    T* p;
public:
    sharedPtr(T* ptr) : count(new int(1)), p(ptr) {}
    sharedPtr(sharedPtr<T>& other) : count(&(++* other.count)), p(other.p) {}
    T* operator->();
    T& operator*();
    bool isEmpty();
    sharedPtr<T>& operator=(sharedPtr<T>& other);
    ~sharedPtr();
    T* get();
    int use_count();
};

#endif //_SHAREDPTR_H_

template<typename T>
inline T* sharedPtr<T>::operator->() {
    return p;
}

template<typename T>
inline T& sharedPtr<T>::operator*() {
    return *p;
}

template<typename T>
inline bool sharedPtr<T>::isEmpty() {
    return p == nullptr;
}

template<typename T>
inline sharedPtr<T>& sharedPtr<T>::operator=(sharedPtr<T>& other) {
    ++* other.count;
    if (this->p && -- * this->count == 0)
    {
        delete count;
        delete p;
        cout << "delete called." << endl;
    }
    this->p = other.p;
    this->count = other.count;
    return *this;
}

template<typename T>
inline sharedPtr<T>::~sharedPtr() {
    if (-- * count == 0)
    {
        delete count;
        delete p;
        cout << "delete called." << endl;
    }
}

template<typename T>
inline T* sharedPtr<T>::get() {
    return p;
}

template<typename T>
inline int sharedPtr<T>::use_count() {
    return *count;
}
