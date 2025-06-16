#pragma once

#include <string>
class Stack
{
    private:
        // initiating a stack array
        std::string *stack_arr;
        int head;
        int size;

    public:
        // Stack class constructor 
        Stack(int m);
        // stack push operation method
        void push(std::string m);
        // stack pop operation method
        std::string pop();
        // get the top of the stack
        std::string getTop();
        // stack empty check
        bool isEmpty();
};