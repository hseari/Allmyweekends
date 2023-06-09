#pragma once
#include "list.h"

template <typename T>
class stack {
private:
    Node<T>* top;
    list<T> l;

public:
    stack() : top(nullptr) {}
    
    bool empty() {
        return l.empty();
    }

    template <typename T>
    void push(T data) {
        l.push_front(data);
    }

    template <typename T>
    void push_back(T data) {
        l.push_back(data);
    }

    template <typename T>
    T pop() {
        T a = l.find_ind<T>(0);
        l.remove_front<T>();
        return a;
    }

    template <typename T>
    T get_top() {
        return l.getfirstval<T>();
    }

    int get_size() {
        return l.getsize();
    }

    void clear() {
        l.clear();
    }
    
};
