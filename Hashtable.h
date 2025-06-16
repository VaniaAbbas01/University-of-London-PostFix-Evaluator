#pragma once
#include <iostream>

class HashTable
{
    private:
        std::string *hash_arr;

    public:
    std::string key;
    double value;
    HashTable();
    // caculates hashcode for the variable
    int HashCode(std::string key);
    // maps the hashcode to index by finding modulus 26
    int MapHashCodeToIndex( int HashCode);
    // searches for the variable equivalent value
    std::string Search(std::string a);
    // inserts the value of the variable
    void Insert(std::string value, std::string key);


};