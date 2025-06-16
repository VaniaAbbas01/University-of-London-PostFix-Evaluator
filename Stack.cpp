#include "Stack.h"
#include <iostream>

Stack::Stack(int m)
{
    // new array stack[20]
    stack_arr = new std::string[m];
    // size = m
    size = m;
    // head 
    head = -1;
}

// FUNCTION push(data)
void Stack::push(std::string data)
{
    // IF head >= stack.length() - 1
    if(head > size - 1)
    {
        // Stack Overflow
        std::cout << "Stack Overflow" << std::endl;
    }
    else // ELSE
    {
        
        // stack[head + 1] = data
        stack_arr[++head] = data;
    }
    // ENDIF
}
// ENDFUNCTION

// FUNCTION pop()
std::string Stack::pop()
{
    // IF head = -1
    if(head == -1)
    {
        // Stack Underflow
        std::cout << "Stack Underflow";
        // RETURN  “”
        return "";
    }
    else // ELSE
    {
        // value = stack[top]
        std::string value = stack_arr[head--]; 
        // RETURN value
        return value;

    } // ENDIF

}
// ENDFUNCTION

// FUNCTION getTop()
std::string Stack::getTop()
{
    // RETURN stack[head]
    return stack_arr[head];
}
// ENDFUNCTION

// FUNCTION isEmpty()
bool Stack::isEmpty()
{
    // IF head = -1 THEN
    if(head == -1)
    {
        // RETURN true
        return true;
    }
    // return false
    return false;
}
// ENDFUNCTION






