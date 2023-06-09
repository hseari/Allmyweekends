#pragma once
#include "list.h"

class queue {
private:
    Node<char>* top;
    list<char> l;

public:
    queue() = default;

    bool empty() {
        return l.empty();
    }

    void enqueue(char data) {
        l.push_back(data);
    }

    char dequeue() {
        char a = l.find_ind<char>(0);
        l.remove_front<char>();
        return a;
    }

    char peek() {
        return l.find_ind<char>(0);
    }
    char back() {
        return l.find_ind<char>(l.getsize()-2);
    }
};