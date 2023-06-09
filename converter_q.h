#pragma once
#include <iostream>
#include "queue.h"
#include <string>

class ñonverter {
private:
   
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
      
        std::string postfix;
        queue q;

        for (int i = 0; i < exp.length(); ++i) {
            char c = exp[i];
            if (c == ' ') {
                continue;}
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
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!q.empty() && q.peek() != '(' && priority(c) <= priority(q.peek())) {
                    postfix += q.dequeue();
                    postfix += ' ';
                }
                q.enqueue(c);
            }
            else if (c == '(') {
                postfix += c;
            }
            else if (c == ')') {
                while (!postfix.empty() && postfix.back() != '(') {
                    q.enqueue(postfix.back());
                    postfix.pop_back();
                }
                if (!postfix.empty())
                    postfix.pop_back();
            }
        }

        while (!q.empty()) {
             postfix += q.dequeue();
             postfix += ' ';
        }
        
        return postfix;
    }

};