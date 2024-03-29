// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

TStack<char, 100> stack1;
TStack<int, 100> stack2;

std::string infx2pstfx(std::string inf) {
    std::string exit;
    for (char i: inf) {
        if (i == '(')
            stack1.push(i);
        else if (i > '0' && i < '9') {
            exit += i;
            exit += ' ';
        } else if (i == ')') {
            while (stack1.get() != '(' && !stack1.isEmpty()) {
                exit += stack1.pop();
            }
            if (stack1.get() == '(')
                stack1.pop();
        } else if (i == '+' || i == '-') {
            if (!stack1.isEmpty()) {
                switch (stack1.get()) {
                    case '*': {
                        exit += '*';
                        stack1.pop();
                        break;
                    }
                    case '/': {
                        exit += '/';
                        stack1.pop();
                        break;
                    }
                    case '+': {
                        exit += '+';
                        stack1.pop();
                        break;
                    }
                    case '-': {
                        exit += '-';
                        stack1.pop();
                        break;
                    }
                }
                stack1.push(i);
            } else
                stack1.push(i);
        } else if (i == '*' || i == '/') {
            if (!stack1.isEmpty()) {
                switch (stack1.get()) {
                    case '*': {
                        exit += '*';
                        stack1.pop();
                        break;
                    }
                    case '/': {
                        exit += '/';
                        stack1.pop();
                        break;
                    }
                }
                stack1.push(i);
            } else
                stack1.push(i);
        }
    }
    while (!stack1.isEmpty()) {
        exit += stack1.pop();
    }
    return exit;
}

int eval(std::string pref) {
    std::string sTemp;
    for (char i: pref) {
        if ((i >= '0' && i <= '9')) {
            sTemp += i;

        } else if (i == ' ') {
            stack2.push(std::stoi(sTemp));
            sTemp.clear();
        } else if (i == '+' || i == '-' || i == '*' || i == '/') {
            switch (i) {
                case '*': {
                    stack2.push(stack2.pop() * stack2.pop());
                    break;
                }
                case '/': {
                    stack2.push(stack2.pop() / stack2.pop());
                    break;
                }
                case '+': {
                    stack2.push(stack2.pop() + stack2.pop());
                    break;
                }
                case '-': {
                    stack2.push(stack2.pop() - stack2.pop());
                    break;
                }
            }
        }
    }
    return stack2.pop();
}
