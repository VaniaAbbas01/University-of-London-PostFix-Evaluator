#include "Hashtable.h"
#include <string>

HashTable::HashTable()
{
    // new array “HashMap”‘[26]
    hash_arr = new std::string[26];

}

// FUNCTION Insert(value, variable)
void HashTable::Insert(std::string value, std::string key)
{
    // hashcode ← HashCode(key)
    int hashcode = HashCode(key);

    // index ← MapHashCodeToIndex(hashcode)
    int index = MapHashCodeToIndex(hashcode);

    // HashMap[index] ← value
    hash_arr[index] = value;
}
// ENDFUNCTION

// FUNCTION HashCode(key)
int HashTable::HashCode(std::string key)
{
    // ascii ← 97
    int ascii = 97;  

    // hashcode ← key[0] - ascii
    int hashcode = key[0] - ascii;
    
    // RETURN hashcode
    return hashcode; 
}
// ENDFUNCTION

// FUNCTION MapHashCodeToIndex(hashcode)
int HashTable::MapHashCodeToIndex(int hashcode)
{
    // index ← hashcode % 26
    int index = hashcode % 26;

    
    // RETURN index
    return index;

}
// ENDFUNCTION


// FUNCTION Search(variable)
std::string HashTable::Search(std::string variable)
{
    std::string value;
    
    // hashcode ← HashCode(key)
    int hashcode = HashCode(variable);

    // index ← MapHashCodeToIndex(hashcode)
    int index = MapHashCodeToIndex(hashcode);

    // value ← HashMap(index)
    value = hash_arr[index];
    // RETURN value
    return value;
}
// ENDFUNCTION