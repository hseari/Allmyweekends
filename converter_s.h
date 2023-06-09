#pragma once
#include <iostream>
#include "stack.h"
#include "queue.h"
#include <string>

class ñonverter {
private:
    void check_infix(const std::string& exp) {
        std::string check;
        for (int i = 0; i < exp.length() - 1; ++i) {
            if (isdigit(exp[i]) || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
                check += exp[i];
            else if (exp[i] == ' ') {
                check += '_';
                while (exp[i + 1] == ' ')
                    i++;
            }
        }
        
        for (int i = 2; i < check.length(); ++i) {
            if (isdigit(check[i]) && (check[i - 1] == '_') && isdigit(check[i - 2]))
                throw "Îøèáêà";
        }
    }

    int priority(char c) {
        if (c == '+' || c == '-')
            return 1;
        else if (c == '*' || c == '/')
            return 2;
        else
            return 0;
    }

public:
    std::string convert(const std::string& exp) {
        stack <char> st;
        std::string postfix;

        check_infix(exp);
        
        for (int i = 0; i < exp.length(); ++i) {
            char c = exp[i];
            if (c == ' ') {
                continue;
            }
            else if (isdigit(c)) {
                std::string num;
                num += c;
                while (i + 1 < exp.length() && isdigit(exp[i + 1])) {
                    num += exp[i + 1];
                    ++i;
                }
                postfix += num; 
                postfix += ' '; 
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
               
                while (!st.empty() && st.get_top<char>() != '(') {
                    postfix += st.get_top<char>();
                    st.pop<char>();
                }
                
                if (!st.empty())
                    st.pop<char>();
            }
            else {
                while (!st.empty() && st.get_top<char>() != '(' && priority(c) <= priority(st.get_top<char>())) {
                    postfix += st.get_top<char>(); 
                    st.pop<char>();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            postfix += st.get_top<char>(); 
            st.pop<char>();
        }

        return postfix;
    }

};
