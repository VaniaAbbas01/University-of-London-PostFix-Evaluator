#include <iostream>
#include "Evaluator.h"
#include <string>
#include "string.h"
#include <cmath>

Evaluator::Evaluator()
{
    

}

// FUNCTION PostfixEvaluator(postFixExp) 
void Evaluator::postfixEvaluator(char* postFix_express)
{
    // tokenise function
    char *token;
    const char *delim = " ";
    token = strtok(postFix_express, delim);
    
    // for first token in postfix expression
    Processor(token);

    if( token!=NULL )
    {
        // FOR each token in postfix expression 
        while( (token=strtok(NULL, delim)) !=NULL )
        {
            // Processor(token)
            Processor(token);
        }

    }

    // IF !stack.ISEMPTY
    if(!stack.isEmpty())
    {
        std::string result;
        // result ← POP[Stack]
        result = stack.pop();
        // IF !stack.ISEMPTY
        if(!stack.isEmpty())
        {
            // “Wrong Input”
            std::cout << "Wrong Input" << std::endl;
        }

        // RETURN result 
        std::cout << result << std::endl;
    } // ENDIF 
}
// ENDFUNCTION

// FUNCTION Processor(token)
void Evaluator::Processor(std::string token)
{
    if(
        token != "+" && token != "-" 
        && token != "*" && token != "/" 
        && token != "=" && token != "%" 
        && token != "pow" && token != "cos"
        && token != "tan" && token != "sin"
        && token != "ln" && token != "log10"
        && token != "log2" && token != "sqrt"
        && token != "exp" && token != "max"
        )
    {     
        // IF token is a number THEN
        if(isNum(token))
        {
            // PUSH[token,stack]
            stack.push(token);
        }           
        else // ELSE (token is a variable) 
        {
            // PUSH[token,stack] 
            stack.push(token);
        }    
    }           
    else  // ELSE IF token is an operator THEN 
    {
        // ProcessOperator(token) 
        processOperator(token);
    }
    // ENDIF 

}
// ENDFUNCTION

// FUNCTION processOperator(token)
void Evaluator::processOperator(std::string token)
{
    std::string num1, num2;
    double x, y, result;
    
    // IF operator is “+” THEN 
    if(token == "+")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }        
        else // ELSE (num1 is a variable) 
        {
            // x ← GetVariableValue(v)
            x = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ←  POP[stack]
        num1 = stack.pop();
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // y ← Built-in-string-to-double(num1) 
            y = std::stod(num1);
        }
        else  // ELSE (num1 is a variable) 
        {
            // y ← GetVariableValue(v)
            y = getVariableValue(num1);
        }
        // ENDIF 

        // result ←  x + y 
        result = x + y;
        // PUSH[result, stack]
        stack.push(std::to_string(result));

    }

    // ELSE IF operator is “-” THEN 
    else if(token == "-")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }

        else  // ELSE (num1 is a variable) 
        {
            // x ← GetVariableValue(v)
            x = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ←  POP[stack]
        num1 = stack.pop();
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // y ← Built-in-string-to-double(num1) 
            y = std::stod(num1);
        }   
        else // ELSE (num1 is a variable)
        {
            // y ← GetVariableValue(num1)
            y = getVariableValue(num1);
        }
        // ENDIF 

        // result ←  x - y 
        result = x - y;
        // PUSH[result, stack]
        stack.push(std::to_string(result));
        
    }

    // ELSE IF operator is “*” THEN 
    else if(token == "*")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ←  POP[stack]
        num1 = stack.pop();
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // y ← Built-in-string-to-double(num1) 
            y = std::stod(num1);
        }
        else // ELSE (num1 is a variable) 
        {
            // y ← GetVariableValue(num1)
            y = getVariableValue(num1);
        }
        // ENDIF 

        // result ←  x * y 
        result = x * y;
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “/” THEN 
    else if(token == "/")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ←  POP[stack]
        num1 = stack.pop();
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // y ← Built-in-string-to-double(num1) 
            y = std::stod(num1);
        }
        else // ELSE (num1 is a variable) 
        {
            // y ← GetVariableValue(num1)
            y = getVariableValue(num1);
        }
        // ENDIF 

        // result ←  x / y 
        result = x / y;
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “pow” THEN 
    else if(token == "pow")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ←  POP[stack]
        num1 = stack.pop();
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // y ← Built-in-string-to-double(num1) 
            y = std::stod(num1);
        }
        else // ELSE (num1 is a variable) 
        {
            // y ← GetVariableValue(num1)
            y = getVariableValue(num1);
        }
        // ENDIF 

        // result ←  x pow y 
        result = pow(x, y);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “%” THEN 
    else if(token == "%")
    {
        int e, f;
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            e = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            e = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ← POP[stack]
        num1 = stack.pop();
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // y ← Built-in-string-to-double(num1) 
            f = std::stod(num1);
        }
        else // ELSE (num1 is a variable) 
        {
            // y ← GetVariableValue(num1)
            f = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  x % y 
        result = e % f;
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “cos” THEN 
    else if(token == "cos")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  cos(x) 
        result = cos(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “tan” THEN 
    else if(token == "tan")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  tan(x) 
        result = tan(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “sin” THEN 
    else if(token == "sin")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  sin(x) 
        result = sin(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “ln” THEN 
    else if(token == "ln")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  ln(x) 
        result = log(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “log10” THEN 
    else if(token == "log10")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  log10(x) 
        result = log10(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “cos” THEN 
    else if(token == "log2")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  log2(x) 
        result = log2(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “cos” THEN 
    else if(token == "sqrt")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  sqrt(x) 
        result = sqrt(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “max” THEN 
    else if(token == "max")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            y = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            y = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←   max of x and y 
        result = std::max(x, y);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    // ELSE IF operator is “exp” THEN 
    else if(token == "exp")
    {
        // num1 ← POP[stack]
        num1 = stack.pop(); 
        // IF num1 is a number THEN 
        if(isNum(num1))
        {
            // x ← Built-in-string-to-double(num1) 
            x = std::stod(num1);
        }
        else // ELSE (num1 is a variable)      
        {
            // x ← GetVariableValue(num1)
            x = getVariableValue(num1);
        }
        // ENDIF 

        //  result ←  tan(x) 
        result = exp(x);
        // PUSH[result, stack]
        stack.push(std::to_string(result));
    }
    else 
    {
        // variable ← POP[stack] 
        num1 = stack.pop(); 
        // value ← POP[stack]
        num2 = stack.pop(); 

        // HashMap.insert(variable, value)
        symbolTable.Insert(num1, num2);
    }
}
// ENDFUNCTION

// FUNCTION isNum(token)
bool Evaluator::isNum(std::string token)
{ 
    // boolean true
    bool value = true;
    // FOR 0 <= token < token.size DO
    for(int i = 0; i < token.size(); i++)
    {
        // IF !(token[i] >= 0 and token[i] <= 9 or token = . or token = -) THEN
        if(!((token[i] >= '0' && token[i] <= '9') || token[i] == '.' || token[i] == '-'))
        {
            // value = false
            value = false;
            // break
            break;
        }
    }
    // RETURN value
    return value;
}
// ENDFUNCTION

// FUNCTION getVariableValue
double Evaluator::getVariableValue(std::string variable)
{
    // var_value = hashTable.search(variable)
    std::string var_value = symbolTable.Search(variable);

    // value = Built-in-string-to-double(var_value)
    double value = std::stod(var_value);

    // RETURN value
    return value;

}
// ENDFUNCTION