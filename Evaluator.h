#pragma once

#include "Stack.h"
#include "Hashtable.h"
#include <string>

class Evaluator
{
    public:
    Evaluator();
    
    // tokenises and returns the answer
    void postfixEvaluator(char* postFix_express);
    // operates numbers based on the operator
    void processOperator(std::string token);
    // checks whether the token is operator or operand
    void Processor(std::string token);
    // checks whether the token is a number, a negaive number, or a decimal number
    bool isNum(std::string value);
    // returns the value for the variable in Q
    double getVariableValue(std::string variable);

    private:
        // stack object created
        Stack stack{30};
        // hashtable object created
        HashTable symbolTable;

        


};