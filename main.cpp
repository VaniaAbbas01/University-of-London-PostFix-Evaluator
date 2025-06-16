#include <iostream>
#include <string.h>
#include "Evaluator.h"
#include <string>

int main()
{
    char str[100], *token;
    const char *delim = " ";
    Evaluator evaluator;
    while(true)
    {
        // asks user to enter the postfix expression
        std::cout<<"Please enter a postfix expression: ";
        // recieves the line 
        std::cin.getline(str, 100);

        // when user writes exit in the terminal, progaram terminates
        if(strcmp(str, "exit") == 0)
        {
            break;
        }
        // postfixevaluator called 
        evaluator.postfixEvaluator(str);

    }

    return 0;
}