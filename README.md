# University-of-London-PostFix-Evaluator

This Postfix Evaluator project was developed as a semester project during my Bachelor's degree in Computer Science. It demonstrates the practical application of core data structures to evaluate mathematical expressions written in postfix notation (also known as Reverse Polish Notation).

## Key Data Strauctures Used Include:

-- Hash Tables - For storing and retrieving variable values efficiently.
-- Stack - For processing and evaluating postfix expressions.

The classes implemented for the project include

## Classes Implemented Include:

### HashTable Class

Implements a basic hash table for mapping variable identifiers (e.g., x, y) to their corresponding numeric values. It enables quick lookups during expression evaluation.

### Stack Class

A standard LIFO stack used to process postfix expressions. It supports basic push/pop operations required for expression parsing and evaluation.

### Evaluator Class

The core class that orchestrates the entire evaluation process. It utilizes the HashTable and Stack classes to:
Parse the expression.
Resolve variables using the hash table.
Perform evaluation using the stack.

## How to Compile and Run

`g++ Evaluator.cpp Hashtable.cpp Stack.cpp main.cpp -o app`

Execute the compiled binary:

`.\app`
