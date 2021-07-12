#pragma once
#ifndef _KSOSTRING_H_
#define _KSOSTRING_H_

#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

template<typename T>
class KsoString {
private:
    list<T> elements;
    int size;
public:
    KsoString(T* str, int n);
    KsoString(KsoString<T>& ks);
    T operator [] (int index);
    KsoString<T>& operator = (const KsoString<T>& ks);
    void insert(T t, int index);
    void deleteChar(int index);
    void pushBack(T t);
    auto findElement(T t);
    void modifyElement(int index, T t);
    int elementsNum();
    void PrintAll();
};

#endif //_KSOSTRING_H_

template<typename T>
inline KsoString<T>::KsoString(T* str, int n) {
    size = n;
    for (int i = 0; i < n; ++i) {
        elements.push_back(str[i]);
    }
}

template<typename T>
inline KsoString<T>::KsoString(KsoString<T>& ks) {
    size = ks.size;
    elements.clear();
    for (int i = 0; i < size; ++i) {
        elements.push_back(ks[i]);
    }
}

template<typename T>
inline T KsoString<T>::operator[](int index) {
    if (index >= size || index < 0) {
        return '0';
    }
    else {
        auto it = elements.begin();
        while (index--) {
            it++;
        }
        return *it;
    }
}

template<typename T>
inline KsoString<T>& KsoString<T>::operator=(const KsoString<T>& ks) {
    size = ks.size();
    elements.clear();
    for (int i = 0; i < size; ++i) {
        elements.push_back(ks[i]);
    }
    return this;
}

template<typename T>
inline void KsoString<T>::insert(T t, int index) {
    if (index > size) {
        cout << "索引越界!" << endl;
    }
    else {
        auto it = elements.begin();
        while (index--) {
            it++;
        }
        elements.insert(it, t);
        size++;
    }
}

template<typename T>
inline void KsoString<T>::deleteChar(int index) {
    if (index > size) {
        cout << "索引越界!" << endl;
    }
    else {
        auto it = elements.begin();
        while (index--) {
            it++;
        }
        elements.erase(it);
        size--;
    }
}

template<typename T>
inline void KsoString<T>::pushBack(T t) {
    elements.push_back(t);
    size++;
}

template<typename T>
inline auto KsoString<T>::findElement(T t) {
    auto it = elements.begin();
    for (; it != elements.end(); it++) {
        if (*it == t) {
            return it;
        }
    }
    return it;
}

template<typename T>
inline void KsoString<T>::modifyElement(int index, T t) {
    if (index > size) {
        cout << "索引越界!" << endl;
    }
    else {
        auto it = elements.begin();
        while (index--) {
            it++;
        }
        *it = t;
    }
}

template<typename T>
inline int KsoString<T>::elementsNum() {
    return size;
}

template<typename T>
inline void KsoString<T>::PrintAll() {
    for (auto ele : elements) {
        cout << ele << " ";
    }
    cout << endl;
}
