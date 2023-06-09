#pragma once
#include <iostream>
#include <string>
#include "list.h"
#include "stack.h"

class calculator {
private:
    stack<int> st;
    std::string exp;

public:
    int calc(const std::string& exp);
};
